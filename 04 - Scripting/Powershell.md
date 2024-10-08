## Automation before PowerShell

There are some neat little things you can do to start automating parts of your workflow, even before touching powershell. 

### Package managers

For instance, updating/installing/uninstalling apps with [package managers](), like [winget](https://learn.microsoft.com/en-us/windows/package-manager/winget/) or [scoop](https://scoop.sh/). Winget is installed on your windows machine by default, and if you use linux, you don't need me to tell you about package managers. 
All of the following commands require a Windows Terminal, CMD or PowerShell window.
```winget upgrade``` will show and perform updates from packages that are registered, these include apps from the microsoft store. If you know the name of a package, which is usually ```dev.app``` (or ```app.app``` for some reason), you can install it right away with ```winget install <packagename>```, but if you don't, just hit the good ol' ```winget search```. There are lots more packages than you might expect, for example, ```winget search runescape``` returns:

![alt text](RunescapeCLI.png)

But we all know you prefer RuneLite.

Winget isn't the best user experience since it often relies on the msstore versions of apps (which are sometimes truly terrible) so, when you're not installing a native msstore app or a microsoft product, use scoop, instead.

Regardless, getting used to package managers is a good way to reduce the amount of time it takes for you to update/install/uninstall things. You'll also get more comfortable using the CLI.

### 

# Getting started in PowerShell

[Corresponding Microsoft Learning Module](https://learn.microsoft.com/en-us/training/modules/introduction-to-powershell/)

Powershell is fairly simple if you've written code before, but if you haven't, don't be alarmed. Let's first look at how you'd write a simple "Hello, World".
For this, create a ```test.ps1``` with the following content:
```
Write-Host "Hello, World"
```
You can then just run it. Actually, I recommend making a ```scripts``` folder somewhere and then [adding that folder to the PATH](https://stackoverflow.com/questions/44272416/how-to-add-a-folder-to-path-environment-variable-in-windows-10-with-screensho). You can now run it from anywhere, by just writing ```test``` in a shell.

Let's store something in a variable, for which we use ```$```:
```
$name = "Mandi"
Write-Host "Hello, I'm $name."
```
Output: ```Hello, I'm Mandi.```

We can use simple, built-in functions like ```Get-Date```:
```
$date = Get-Date
Write-Host "Today's date is $date."
```
Output: ```Today's date is 05/26/2024 20:42:59.```

Ain't pretty, is it. But, we can use flags for the Get-Date cmdlet like follows:
```
$day = Get-Date -Format "dddd"
$date = Get-Date -Format "dd"
$month = Get-Date -Format "MMMM"
$year = Get-Date -Format "yyyy"

Write-Host "Today's $day, the $date of $month $year."
```
Output: ```Today's Sunday, the 26 of May 2024.```

Here, the -Format flag takes a string and reads just that, how to format Get-Date. The main takeaway here are flags, how to use them, and the fact that variables get processed within a string[^1].

## Creating a user profile in PowerShell

Using the Windows Terminal app is a great idea. It's a lot like a linux bash. It's like a modern combination of cmd & PowerShell. Install it by running ```winget install Microsoft.WindowsTerminal``` and you can read up on cool extra customization [here](https://dev.to/ansonh/customize-beautify-your-windows-terminal-2022-edition-541l) and [here](https://learn.microsoft.com/en-us/windows/terminal/tutorials/custom-prompt-setup).

Any aliases you want to set should be done so in `$profile`.

`$profile` is a PowerShell script that gets run every time you open up PowerShell.

If you don't know where that is for you, just open PowerShell and run:
```shell
echo $profile
```
You can edit this file with `nano $profile` or `code $profile` or however you want.\
For example, if you want to set an alias for `set-location`, like `goto`, you can write:
```shell
New-Alias Goto Set-Location
```
inside of your $profile file.

## Automating Simple Tasks in PowerShell

Sometimes, you just want to automate tasks you do way too often by hand. Chances are, there's probably a script for that out there, but maybe not. I, for example, wanted a simple, versatile backup script, so I wrote [this](https://github.com/FlyMandi/PWSH-Collection?tab=readme-ov-file#automated-backup). It uses 7zip to compress a folder and move it to a backup location (like a remote server, or another drive).

Then, I noticed I wanted to change the theme to [winfetch](https://github.com/lptstr/winfetch) way too often. This included stuff like logo size, ascii art/image, etc, etc. So, I wrote a script to switch between profiles [here](https://github.com/FlyMandi/PWSH-Collection?tab=readme-ov-file#swap-between-winfetch-configs).

## Using Powershell to fix niche issues

Sometimes, you'll run into an issue that is not easily resolved by an application update. Such was the case with an annoying issue that would show an old version number for Discord inside `winget-cli`, while having the newest version installed. As consequence, winget would tell me all the time that my discord was out-of-date. Tired of this nonsense, I wrote [this fix](https://github.com/FlyMandi/PWSH-Collection/tree/main?tab=readme-ov-file#fix-winget-showing-out-of-date-package-version-with-updated-app)

[^1]: If you wanted to output the string `I make $money`, you'd have to write ```I make `$money```. A backtick reverts the dollar sign to plain text instead of trying to parse a variable.