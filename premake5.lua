require 'scripts/premake/premake-defines'
require 'scripts/premake/premake-common'
require 'scripts/premake/premake-triggers'
require 'scripts/premake/premake-settings'

root_dir = os.getcwd()

Arch = ""

if _OPTIONS["arch"] then
	Arch = _OPTIONS["arch"]
else
	if _OPTIONS["os"] then
		_OPTIONS["arch"] = "arm"
		Arch = "arm"
	else
		_OPTIONS["arch"] = "x64"
		Arch = "x64"
	end
end

workspace( settings.workspace_name )
startproject "Sandbox"
	flags 'MultiProcessorCompile'
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	targetdir ("bin/%{outputdir}/")
	objdir ("bin/intermediates/%{outputdir}/obj/")

	if Arch == "arm" then 
		architecture "ARM"
	elseif Arch == "x64" then 
		architecture "x86_64"
	elseif Arch == "x86" then
		architecture "x86"
	end

	print("Arch = ", Arch)

	configurations
	{
		"Debug",
		"Release",
		"Production"
	}

	include "Engine/premake5"
	include "Sandbox/premake5"
