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
		"Sigma",
	}

	prebuildcommands
	{
		("{COPY} %{wks.location}/bin/" .. outputdir .. "/Sigma/Sigma.dll %{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	}

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
		optimize "on"
