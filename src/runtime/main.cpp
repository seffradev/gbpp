#include <cstdint>
#include <random>
#include <raylib-cpp/raylib-cpp.hpp>

#include "gameboy-screen.hpp"
#include "log.hpp"
#include "raylib.h"
#include "window.hpp"

using namespace logging;
using namespace graphics;

auto main(int, char*[]) noexcept -> int {
    auto _ = Logger<Level::Trace>{};

    std::default_random_engine             generator;
    std::uniform_int_distribution<uint8_t> distribution{};

    auto window = Window{};
    auto screen = GameboyScreen{};

    while (!window.ShouldClose()) {
        auto _ = window.CreateDrawContext();

        for (auto y = 0uz; y < SCREEN_HEIGHT; ++y) {
            for (auto x = 0uz; x < SCREEN_WIDTH; ++x) {
                screen[x, y] = Color{
                    .r = distribution(generator), .g = distribution(generator), .b = distribution(generator), .a = 255};
            }
        }

        screen.Draw();
    }

    return 0;
}
