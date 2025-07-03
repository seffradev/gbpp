#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "raylib-cpp/Window.hpp"
#include "raylib.h"

namespace graphics {

constinit const size_t SCREEN_WIDTH  = 160;
constinit const size_t SCREEN_HEIGHT = 144;
constinit const size_t TARGET_FPS    = 60;
constinit const auto   TITLE         = "GameBoy++";

class DrawContext {
public:
    constexpr DrawContext(raylib::Window& window) : window(window) {
        window.BeginDrawing();
        window.ClearBackground(RAYWHITE);
    }

    constexpr ~DrawContext() { window.EndDrawing(); }

private:
    raylib::Window& window;
};

class Window {
public:
    constexpr Window() { window.SetTargetFPS(TARGET_FPS); }

    constexpr auto CreateDrawContext() -> DrawContext { return DrawContext{window}; }

    constexpr auto ShouldClose() -> bool { return window.ShouldClose(); }

private:
    raylib::Window window = raylib::Window(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
};

}

#endif  // !__WINDOW_HPP__
