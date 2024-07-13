project "GLFW"
    kind "StaticLib"
    language "c"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "glfw/src/**.c",
        "glfw/src/**.h",
        "glfw/include/**.h"
	}

    includedirs
    {
        "glfw/include"
    }

	defines 
	{ 
		"_GLFW_WIN32",
    	"_CRT_SECURE_NO_WARNINGS"
	}

    filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
