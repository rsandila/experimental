workspace "experimental"
  platforms { "64bit", "32bit" }
  configurations { "Debug", "Release" }
  warnings "Extra"
  if os.is("macosx") then
    buildoptions "-std=c++11 -stdlib=libc++"
  else
    if not os.is("windows") then
       buildoptions "-std=c++0x"
       links { "pthread" }
    end
  end

  flags { "StaticRuntime", "MultiProcessorCompile" }

	filter "configurations:Debug"
    defines { "DEBUG" }
    flags { "Symbols" }
    linkoptions "-g"
  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
	filter "configurations:64bit"
		architecture ( "x86_64" )

  project "experimental-tests"
    kind "ConsoleApp"
    language "C++"
    files { "include/**.h", "tests/**.cpp" }
    
