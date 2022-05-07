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
    clr "On"

    targetdir = ("bin/" .. outputdir .. "/%{prj.name}")
    objDir = ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    filter "system:windows"
        cppDialect = "C++23"
        staticRuntime = "On"
        systemversion = "latest"

    filter "configurations:Debug"
        defines "PM_DEBUG"
        symbols "On"
    
        filter "configurations:Release"
        defines "PM_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "HZ_DIST"
        optimize "On"