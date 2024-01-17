workspace "WindowsApplication"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

project "WindowsProject"
	location "Project1"
	kind "WindowedApp"
	language "C++20"
	targetdir "Project1/bin/%{cfg.buildcfg}"

	files 
	{
		"%{prj.name}/src/inc/**.h",
		"%{prj.name}/src/**.cpp"
	}

	filter {"configurations:Debug"}
		defines {"DEBUG"}
		symbols "On"

	filter {"configurations:Release"}
		defines {"NDEBUG"}
		optimize "On"