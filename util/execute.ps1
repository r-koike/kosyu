# @author : Ryosuke Koike
# @created: April 3, 2021
# @description: 実行時の出力はファイルへdumpし，ステータスは[実行ステータス，所要時間[ms]]の順にechoする．
# !@caution!: -output_fullnameにワイルドカードを含めないこと．Remove-Itemするので悲惨なことになる．

Param(
	[parameter(mandatory = $true)][String]$exe_fullname,
	[String]$input_fullname,
	[String]$output_fullname,
	[switch]$omit_info,
	[int]$timeout_sec = 2
)
chcp 65001 | Out-Null

# 念のため
if (("" -ne $output_fullname) -and (Test-Path $output_fullname)) {
	Remove-Item $output_fullname 
}

# exeの実行を開始する
# PSはパイプラインの時に引数をオブジェクト化するため低速であり，これを避けるためにcmd内で実行する
# また，outputの受け渡しもPSのオブジェクト受け渡しは低速のため使えず，Windowsのファイルとして受け渡す
$exe_command = ""
if (("" -ne $input_fullname) -and ("" -ne $output_fullname)) {
	$exe_command = "type `"${input_fullname}`" | `"${exe_fullname}`" > `"${output_fullname}`""
}
elseif ("" -ne $input_fullname) {
	$exe_command = "type `"${input_fullname}`" | `"${exe_fullname}`""
}
elseif ("" -ne $output_fullname) {
	$exe_command = "`"${exe_fullname}`" > `"${output_fullname}`""
}
else {
	$exe_command = "`"${exe_fullname}`""
}
$j = Start-Job {
	param (
		[string]$command
	)
	cmd.exe /c $command
} -ArgumentList $exe_command 

# exeの実行が終わるのを待つ
$measured = Measure-Command {
	# これは[$timeout_sec]秒よりも短くなることはない（たぶん）
	Wait-Job -Job $j -Timeout $timeout_sec | Out-Null
}
$total_milliseconds = $measured.TotalMilliseconds

# 実行がうまくいったかどうかを判別する（出力の正誤は判定しない）
if (!$omit_info) { Write-Host command: $exe_command }
if (!$omit_info) { Receive-Job -Job $j }
if (!$omit_info) { Write-Host Total milliseconds: $total_milliseconds }
if (!$omit_info) { Write-Host Job state: $j.State }
$execution_state = "Completed"
if ($j.State -eq "Completed") {
	# AC or WA
	$execution_state = "Completed"
}
elseif ($j.State -eq "Running") {
	$execution_state = "TLE"
}
elseif ($j.State -eq "Failed") {
	$execution_state = "RE"
}

if (!$omit_info) { Write-Host "Removing job" }
Remove-Job -force $j
if (!$omit_info) { Write-Host "-----------------" }

Write-Output $execution_state
Write-Output $total_milliseconds