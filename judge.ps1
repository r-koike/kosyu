# @author : Ryosuke Koike
# @created: April 3, 2021

Param(
	[parameter(mandatory = $true)][ValidateSet("A", "B", "C", "D", "E")][String]$task
)
chcp 65001 | Out-Null
$root_dir_fullname = Split-Path $MyInvocation.MyCommand.Path
$exe_name = "jp.ac.kyoto-u.me.mechatronics.task${task}.exe"
$exe_fullname = "${root_dir_fullname}\bin\${exe_name}"
$src_fullname = "${root_dir_fullname}\src\${task}.cpp"
$temp_output_fullname = "${root_dir_fullname}\temp_output.txt"
$time_limit_fullname = "${root_dir_fullname}\res\bench\time_limit.txt"

$time_limit = 2
if (Test-Path $time_limit_fullname) {
	$time_limit_list = (Get-Content $time_limit_fullname) -as [int[]]
	$time_limit = $time_limit_list[0]
}

g++ $src_fullname -o $exe_fullname
$success_to_compile = $?

Write-Host "==========================================="
Write-Host "Task: ${task}, Time limit: ${time_limit}[s]"
Write-Host "-----------------------------------"
$task_judge = "AC"
if (!$success_to_compile) {
	$task_judge = "CE"
}
else {
	Write-Host "| judge file   | judge | time[ms] |"
	Write-Host "-----------------------------------"
	$judges = @()
	$execute_times = @()
	Get-ChildItem "${root_dir_fullname}\res\judge${task}\judge*.txt" -Name | ForEach-Object {
		$judge_fullname = "${root_dir_fullname}\res\judge${task}\${_}"
		$ans_fullname = "${root_dir_fullname}\res\judge${task}\ans_${_}"

		# ここでexecute.ps1を呼ぶ
		$result = & "${root_dir_fullname}\util\execute.ps1" `
			-exe_fullname $exe_fullname `
			-input_fullname $judge_fullname `
			-output_fullname $temp_output_fullname `
			-omit_info `
			-timeout_sec $time_limit

		$judge = $result[0]
		$time = $result[1]
		if ($judge -eq "Completed") {
			# 最後は改行があってもなくてもいいが，2個以上の改行は許されない
			# no differences -> $? = True, otherwise -> $? = False
			fc.exe /a $temp_output_fullname $ans_fullname | Out-Null
			$all_ok = $?

			if ($all_ok) {
				$judge = "AC"
			}
			else {
				$judge = "WA"
			}
		}
		$judges += $judge
		$execute_times += $time

		# ! ちゃんと後片付けをしておく
		if (($null -ne $temp_output_fullname) -and (Test-Path $temp_output_fullname)) {
			Remove-Item $temp_output_fullname 
		}

		$s1 = $_.PadRight(12)
		$s2 = $judge.PadLeft(3)
		$s3 = $time.ToString("0.00").PadLeft(8)
		Write-Host "| ${s1} |  ${s2}  | ${s3} |"
	}

	foreach ($judge in $judges) {
		if ($judge -eq "TLE") {
			$task_judge = "TLE"
			break
		}
		if ($judge -eq "WA") {
			$task_judge = "WA"
		}
	}
}

Write-Host "-----------------------------------"
Write-Host "Task judge: ${task_judge}"

