<#
.SYNOPSIS
	Installs .NET Core SDK to $env:ProgramFiles\dotnet and $env:ProgramFiles(x86)\dotnet
.DESCRIPTION
	 Installs x86 and x64 versions of the .NET Core SDK to $env:ProgramFiles\dotnet and $env:ProgramFiles(x86)\dotnet
	 respectively.
	 
	 To customize install location and other aspects of this script, download dotnet-install.ps1 
		from https://dot.net/v1/dotnet-install.ps1. See documentation at 
		https://docs.microsoft.com/en-us/dotnet/core/tools/dotnet-install-script
.PARAMETER version
	Version number of the core-sdk build to install, defaults to "latest". Latest version
	number can be found at https://github.com/dotnet/core-sdk and https://dotnet.microsoft.com/download
.PARAMETER channel
	"channel" to install from, defaults to "master"
	Valid values for -channel are:
		Current - Most current release
		LTS - Long-Term Support channel (most current supported release)
		Two-part version in X.Y format representing a specific release (for example, 2.0, or 1.0)
		https://github.com/dotnet/core-sdk branch name (case-sensitive); for example, 
			release/3.0.1xx, or master (for nightly releases)
.PARAMETER Verbose 
	Displays diagnostics information.
.PARAMETER elevate
	Runs this script elevated (defaults to "$true")
	Setting this to $false should almost never be required.
.EXAMPLE
	PS> Install-Latest-DotnetCore3.ps1 
	Installs latest .NET Core SDK from 'master'
.EXAMPLE	
	PS> Install-Latest-DotnetCore3.ps1 -version 3.0.100-preview7-012331
	Installs version 3.0.100-preview7-012331 of the .NET Core SDK 
.EXAMPLE	
	PS> Install-Latest-DotnetCore3.ps1 -version 3.0.100-preview6-012264 -channel Release
	Installs version 3.0.100-preview6-012264 of the core-sdk. Usually ignores the value 
	specified in -channel
.EXAMPLE	
	PS> Install-Latest-DotnetCore3.ps1 -channel release/3.0.1xx
	Installs the latest build from release/3.0.1xx branch from https://github.com/dotnet/core-sdk
.EXAMPLE	
	PS> Install-Latest-DotnetCore3.ps1 -elevate $false
	Installs the latest build from 'master'; will not attempt to elevate if the script
	is running without administrator priviliges (will fail if the script is running without 
	admin priviliges)
#>
[CmdletBinding(PositionalBinding=$false)]
param(
  [string][Alias('v')]
  [Parameter(HelpMessage='Version number of the core-sdk build to install, defaults to "latest"')]
  $version = 'latest',
  
  [string][Alias('c')]
  [Parameter(HelpMessage='"channel" to install from, defaults to "master"')]
  $channel = 'master',
   
  [bool][Alias('e')]
  [Parameter(HelpMessage='Runs this script elevated (defaults to "$true")')]
  $elevate = $true
)


# Use-RunAs function from TechNet Script Gallery
# https://gallery.technet.microsoft.com/scriptcenter/63fd1c0d-da57-4fb4-9645-ea52fc4f1dfb
function Use-RunAs {    
    # Check if script is running as Adminstrator and if not use RunAs 
    # Use Check Switch to check if admin 
    param([Switch]$Check) 
     
    $IsAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()` 
        ).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator") 
         
    if ($Check) { 
		return $IsAdmin 
	}     
    if ($MyInvocation.ScriptName -ne "") {  
        if (-not $IsAdmin) {  
            try {  
				$arg = "-file `"$($MyInvocation.ScriptName)`"" 
				
				Write-Verbose "Starting elevated process..."
				Write-Verbose '\t' "$psHome\powershell.exe" -Verb Runas -ArgumentList $arg -ErrorAction 'stop'  
				
                Start-Process "$psHome\powershell.exe" -Verb Runas -ArgumentList $arg -ErrorAction 'stop'  
            } 
            catch { 
                Write-Warning "Error - Failed to restart script with runas"  
                break               
            } 
            Exit # Quit this session of powershell 
        }  
    }  
    else {  
        Write-Warning "Error - Script must be saved as a .ps1 file first"  
        break  
    }  
} 


# Make sure that the script is running elevated
if ($elevate) {
  Use-RunAs
}

$dotnet_install = "$env:TEMP\dotnet-install.ps1"
$x64InstallDir  = "$env:ProgramFiles\dotnet"
$x86InstallDir  = "${env:ProgramFiles(x86)}\dotnet"

$AllProtocols = [System.Net.SecurityProtocolType]'Ssl3,Tls,Tls11,Tls12'
[System.Net.ServicePointManager]::SecurityProtocol = $AllProtocols

Invoke-WebRequest https://dot.net/v1/dotnet-install.ps1 -OutFile $dotnet_install
Write-Verbose "Downloaded dotnet-install.ps1 to $dotnet_install"

.$dotnet_install -Channel $channel -Version $version -Architecture x64 -InstallDir $x64InstallDir
Write-Verbose "Installed SDK Version=$version Channel=$channel Architecture=x64 to $x64InstallDir"

.$dotnet_install -Channel $channel -Version $version -Architecture x86 -InstallDir $x86InstallDir
Write-Verbose "Installed SDK Version=$version Channel=$channel Architecture=x86 to $x64InstallDir"