workspace "CM"
   architecture "x64"
   language "C++"
   configurations { "Debug", "Release" }
    filter "configurations:Release"
        defines { "" }
        symbols "On"

project "CMS"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   architecture "x64"

   targetdir ("Build/%{configurations}-%{architecture}/bin/")
   objdir ("Build/%{configurations}-%{architecture}/int/")
   
   IncludeDir = {"External/","Headers"}