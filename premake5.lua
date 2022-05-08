workspace "passMangerCpp"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "passManger"
    location "passManger"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "hashingLib/src/**.h"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

    filter "system:linux"
        cppdialect "C++17"

    filter "configurations:Debug"
        defines "PM_DEBUG"
        symbols "On"
    
        filter "configurations:Release"
        defines "PM_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "HZ_DIST"
        optimize "On"