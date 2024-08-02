project "Sigma"
	kind "SharedLib"
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
		"%{includeDirs.SIGMA}",
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
		"opengl32",
		"gdi32",
		"user32",
		"kernel32"
	}

	defines
	{
		"DLL_BUILD"
	}

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
		optimize "on"
