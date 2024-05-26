## Automation before PowerShell

There are some neat little things you can do to start automating parts of your workflow, even before touching powershell. 

### Package managers

For instance, updating/installing/uninstalling apps with [package managers](), like [winget](https://learn.microsoft.com/en-us/windows/package-manager/winget/) or [scoop](https://scoop.sh/). Winget is installed on your windows machine by default, and if you use linux, you don't need me to tell you about package managers. 
All of the following commands require a Windows Terminal, CMD or PowerShell window. (I'd reccomend setting up a personal terminal[^1])
```winget upgrade``` will show and perform updates from packages that are registered, these include apps from the microsoft store. If you know the name of a package, which is usually ```dev.app``` (or ```app.app``` for some reason), you can install it right away with ```winget install <packagename>```, but if you don't, just hit the good ol' ```winget search```. There are lots more packages than you might expect, for example, ```winget search runescape``` returns:

![alt text](image.png)
But we all know you prefer RuneLite.

Winget isn't the best user experience since it often relies on the msstore versions of apps (which are sometimes truly terrible) so, when you're not installing a native msstore app or a microsoft product, use scoop, instead.

Regardless, getting used to package managers is a good way to reduce the amount of time it takes for you to update/install/uninstall things. You'll also get more comfortable using the CLI.

### 

# Getting started in PowerShell

Powershell is fairly simple if you've written code before, but if you haven't, don't be alarmed. Let's first look at how you would create a PowerShell script in the first place.

//TODO


[^1]: Using the Windows Terminal app is a great idea. It's a lot like a linux bash. It's like a modern combination of cmd & PowerShell. Install it by running ```winget install Microsoft.WindowsTerminal``` and you can read up on cool extra customization [here](https://learn.microsoft.com/en-us/windows/terminal/tutorials/custom-prompt-setup). 