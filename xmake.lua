---@format disable
add_rules("mode.debug", "mode.release", "mode.coverage")
set_languages("cxxlatest")

add_requires("raylib-cpp")

includes("modules/utility/xmake.lua")
includes("modules/gameboy/xmake.lua")
includes("modules/runtime/xmake.lua")
