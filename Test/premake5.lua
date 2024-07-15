project "Test"
	kind "ConsoleApp"
	language "c++"
	cppdialect "c++17"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"**.h",
		"**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Engine/Sigma",
		"%{includeDirs.GLFW}",
        "%{includeDirs.GLAD}",
        "%{includeDirs.GLM}",
        "%{includeDirs.STB_IMAGE}",
        "%{includeDirs.ENTT}"
    }

	links
	{
		"Engine",
        "GLFW",
        "GLAD",
		"opengl32",
		"gdi32",
		"user32",
		"kernel32"
	}

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
		optimize "on"
