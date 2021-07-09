IncludeDir = {}
IncludeDir["Engine"] = "../Engine/Source"

project "Engine"
	kind "StaticLib"
	language "C++"
	editandcontinue "Off"

	files
	{
		"Source/**.h",
		"Source/**.c",
		"Source/**.cpp"
	}

	includedirs
	{
		"",
		"../",
		"Source/",
	}

	sysincludedirs
	{
		"%{IncludeDir.Engine}",
	}

	links
	{
	}

	defines
	{
		"SLATE_ENGINE",
		"SLATE_DYNAMIC",
		"SLATE_ROOT_DIR="  .. root_dir
	}

	filter 'architecture:x86_64'
		defines { "SLATE_SSE" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"
		disablewarnings { 4307 }
		characterset ("MBCS")

		--pchheader "Precompiled.h"
		--pchsource "Source/Precompiled.cpp"

		defines
		{
			"SLATE_PLATFORM_WINDOWS",
			"WIN32_LEAN_AND_MEAN",
			"_CRT_SECURE_NO_WARNINGS",
			"_DISABLE_EXTENDED_ALIGNED_STORAGE",
			"_SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING",
			"_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING",
		}

		files
		{
		}

		links
		{
		}

		buildoptions
		{
			"/MP", "/bigobj"
		}

	filter "configurations:Debug"
		defines { "SLATE_DEBUG", "_DEBUG"  }
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
