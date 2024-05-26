Param(
    [string]$FromFolder
)

# path to your installed rar.exe (NOT WinRAR.exe)
$rar = "C:\Program Files\WinRAR\Rar.exe"

# path to your desired destination (hopefully on a different drive than your important files)
$ToFolder = "D:\Backup Folder\"

$date = Get-Date -format "yy-MM-dd"
$leafName = Split-Path -Path $FromFolder -Leaf
$archiveName = "$leafName`_backup-$date.rar"

# rar syntax: (rar <destination> <source>), where:
# <destination> would be something like "C:\Backup Folder\Backup.rar"
# <source> is the CLI argument $FromFolder, but you might also want to use $pwd (directory from which the script was called)

# run rar.exe "a -u" (update) "-y" (presume yes) "-m5" (highest compression) "-t" (test after finishing)
&$rar a -u -y -m5 -t $ToFolder\$archiveName $FromFolder

# example call of this script (when added in PATH): 
# xample_backup -FromFolder "C:\Important Files\"

# it would then add all the files from "C:\Important Files\" to "D:\Backup Folder\Important Files_backup-24-05-26.rar",
# as well as test & verify that those files are in working order. If you make a backup within the same day, 
# since the -u flag is set, it will only add changed/added files to the archive, so the process should take significantly less time.