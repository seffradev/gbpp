---@format disable
add_rules("mode.debug", "mode.release", "mode.coverage")

add_requires("raylib-cpp")

set_languages("cxxlatest")

target("library")
    set_kind("static")
    add_includedirs("include/library", { public = true })
    -- add_files("src/library/*.cpp")
    add_packages("raylib-cpp", { public = true })

target("runtime")
    set_kind("binary")
    add_files("src/runtime/*.cpp")
    add_deps("library")
    set_default(true)
