project "SPDLOG"
    kind "StaticLib"
    language "c++"
    cppdialect "c++17"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "spdlog/src/**.cpp",
        "spdlog/include/spdlog/**.h"
	}

    includedirs
    {
        "spdlog/include"
    }

    defines
    {
        "SPDLOG_COMPILED_LIB"
    }

    filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
