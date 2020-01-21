workspace "experimental"
  platforms { "64bit", "32bit" }
  configurations { "Debug", "Release" }
  warnings "Extra"
  if os.istarget("macosx") then
    buildoptions "-std=c++11 -stdlib=libc++"
  else
    if not os.istarget("windows") then
       buildoptions "-std=c++1y"
       --- buildoptions "-std=c++0x"
       links { "pthread" }
    end
  end

  flags { "MultiProcessorCompile" }
  staticruntime "on"

	filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"
    linkoptions "-g"
  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
	filter "configurations:64bit"
		architecture ( "x86_64" )

  project "experimental-tests"
    kind "ConsoleApp"
    language "C++"
    files { "include/**.hpp", "tests/**.cpp" }
