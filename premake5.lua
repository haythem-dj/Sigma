workspace "Sigma"
	architecture "x86_64"
	startproject "Test"

	configurations
	{
		"Debug",
		"Release"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"
    
    includeDirs = {}
    includeDirs["SIGMA"] = "%{wks.location}/Sigma/src/Sigma"
    includeDirs["GLFW"] = "%{wks.location}/Libraries/glfw/glfw/include"
    includeDirs["GLAD"] = "%{wks.location}/Libraries/glad/include"
    includeDirs["GLM"] = "%{wks.location}/Libraries/glm/include"
    includeDirs["SPDLOG"] = "%{wks.location}/Libraries/spdlog/spdlog/include"
    includeDirs["STB_IMAGE"] ="%{wks.location}/Libraries/stb_image/include"
    includeDirs["ENTT"] = "%{wks.location}/Libraries/entt/include"

	defines
	{
		"GLM_ENABLE_EXPERIMENTAL",
		"STB_IMAGE_IMPLEMENTATION"
	}

    include "Libraries/glfw"
    include "Libraries/glad"
    include "Libraries/spdlog"

	include "Sigma"
	include "Test"
