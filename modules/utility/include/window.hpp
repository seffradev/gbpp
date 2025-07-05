#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <raylib.h>

#include <raylib-cpp/Window.hpp>

namespace graphics {

constinit const size_t DEFAULT_FPS = 60;

class DrawContext {
public:
    constexpr DrawContext(raylib::Window& window) : window(window) {
        window.BeginDrawing();
        window.ClearBackground(RAYWHITE);
    }

    constexpr DrawContext(const DrawContext&)                    = delete;
    constexpr auto operator=(const DrawContext&) -> DrawContext& = delete;
    constexpr DrawContext(DrawContext&&)                         = delete;
    constexpr auto operator=(DrawContext&&) -> DrawContext&      = delete;

    constexpr ~DrawContext() { window.EndDrawing(); }

private:
    raylib::Window& window;
};

class Window {
public:
    constexpr Window(int width, int height, std::string title, int target_fps = DEFAULT_FPS)
        : window(width, height, title) {
        window.SetTargetFPS(target_fps);
    }

    constexpr auto CreateDrawContext() -> DrawContext { return DrawContext{window}; }

    constexpr auto ShouldClose() -> bool { return window.ShouldClose(); }

private:
    raylib::Window window;
};

}

#endif  // !__WINDOW_HPP__
