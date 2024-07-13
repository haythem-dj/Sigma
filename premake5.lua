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
    includeDirs["GLFW"] = "%{wks.location}/Libraries/glfw/glfw/include"
    includeDirs["GLAD"] = "%{wks.location}/Libraries/glad/include"
    includeDirs["GLM"] = "%{wks.location}/Libraries/glm"
    includeDirs["STB_IMAGE"] ="%{wks.location}/Libraries/stb_image"

	defines
	{
		"GLM_ENABLE_EXPERIMENTAL",
		"STB_IMAGE_IMPLEMENTATION"
	}

    include "Libraries/glfw"
    include "Libraries/glad"

	include "Engine"
	include "Test"
