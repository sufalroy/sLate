IncludeDir = {}
IncludeDir["Engine"] = "../Engine/Source"

project "Sandbox"
	kind "WindowedApp"
	language "C++"

	files
	{
		"**.h",
		"**.cpp",
	}

	sysincludedirs
	{
		"%{IncludeDir.Engine}",
	}

	includedirs
	{
		"../Engine/Source",
	}

	links
	{
		"Engine"
	}

	defines
	{
	}

	filter 'architecture:x86_64'
		defines { "SLATE_SSE" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		entrypoint "WinMainCRTStartup"

		defines
		{
			"SLATE_PLATFORM_WINDOWS",
			"WIN32_LEAN_AND_MEAN",
			"_CRT_SECURE_NO_WARNINGS",
			"_DISABLE_EXTENDED_ALIGNED_STORAGE",
			"_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING",
			"SLATE_ROOT_DIR="  .. root_dir,
		}

		libdirs
		{
		}

		links
		{
		}

		disablewarnings { 4307 }

	
	filter "configurations:Debug"
		defines { "SLATE_DEBUG", "_DEBUG" }
		symbols "On"
		runtime "Debug"
		optimize "Off"

	filter "configurations:Release"
		defines { "SLATE_RELEASE" }
		optimize "Speed"
		symbols "On"
		runtime "Release"

	filter "configurations:Production"
		defines "SLATE_PRODUCTION"
		symbols "Off"
		optimize "Full"
		runtime "Release"
