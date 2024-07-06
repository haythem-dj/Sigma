workspace "Sigma"
	architecture "x86_64"
	startproject "Test"

	configurations
	{
		"Debug",
		"Release"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

	links
	{
		"Engine"
	}

	include "Engine"
	include "Test"
