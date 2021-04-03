# @author : Ryosuke Koike
# @created: April 3, 2021

$root_dir_fullname = Split-Path $MyInvocation.MyCommand.Path
$exe_name = "jp.ac.kyoto-u.me.mechatronics.bench.exe"
$exe_fullname = "${root_dir_fullname}\bin\${exe_name}"
$src_fullname = "${root_dir_fullname}\util\bench.cpp"
$long_input_fullname = "${root_dir_fullname}\res\bench\long.txt"
$short_input_fullname = "${root_dir_fullname}\res\bench\short.txt"
$time_limit_fullname = "${root_dir_fullname}\res\bench\time_limit.txt"
$num_repeat = 10

g++ $src_fullname -o $exe_fullname
$success_to_compile = $?

if (!$success_to_compile) {
	Write-Host "Error: Failed to compile"
	exit
}

$input_fullnames = @($short_input_fullname, $long_input_fullname)
$result_times = @()
foreach ($input_fullname in $input_fullnames) {
	$result_time = 0
	Write-Host "-----------------------"
	Write-Host $input_fullname
	for ($i = 0; $i -lt $num_repeat; $i++) {
		$result = & "${root_dir_fullname}\util\execute.ps1" `
			-exe_fullname $exe_fullname `
			-input_fullname $input_fullname `
			-omit_info `
			-timeout_sec 5
		Write-Host $result[0] $result[1]"[ms]"
		if ($result[0] -ne "Completed") {
			Write-Host "Error: Failed to execute."
			exit
		}
		$result_time += $result[1]
	}
	$mean = $result_time / $num_repeat
	$result_times += $mean
	Write-Host "Mean time: ${mean}"
}

# longのほうの結果の切り上げ[sec]を課題の制限時間とする
$ceiled_time = [Math]::Ceiling($result_times[1] / 1000)
$ceiled_time | Out-File -FilePath $time_limit_fullname
Write-Host "Time limit: ${ceiled_time}"