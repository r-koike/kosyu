# @author : Ryosuke Koike
# @created: April 3, 2021

chcp 65001 | Out-Null

$tasks = @("A", "B", "C", "D", "E")

$root_dir_fullname = Split-Path $MyInvocation.MyCommand.Path
$judge_fullname = "${root_dir_fullname}\judge.ps1"

Write-Host "==========================================="
Write-Host "Matsuno Lab's Shinjin Kensyu"
Write-Host "C++ Judge System v1.0"

foreach ($task in $tasks) {
	& $judge_fullname $task
}



