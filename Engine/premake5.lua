project "Engine"
	kind "StaticLib"
	language "c++"
	cppdialect "c++17"
    staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

	pchheader "sgpch.h"
	pchsource "src/sgpch.cpp"

	files
	{
		"**.h",
		"**.cpp"
	}

	includedirs
	{
		"%{includeDirs.ENGINE}",
		"%{includeDirs.GLFW}",
        "%{includeDirs.GLAD}",
        "%{includeDirs.GLM}",
        "%{includeDirs.SPDLOG}",
        "%{includeDirs.STB_IMAGE}",
        "%{includeDirs.ENTT}"
	}

	links
	{
        "GLFW",
		"GLAD",
		"SPDLOG",
		"opengl32.lib",
		"gdi32.lib",
		"user32.lib",
		"kernel32.lib"
	}	

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
		optimize "on"
