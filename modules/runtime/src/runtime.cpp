#include <raylib.h>

#include <cstdint>
#include <random>
#include <raylib-cpp/raylib-cpp.hpp>

#include "log.hpp"
#include "screen.hpp"
#include "window.hpp"

using namespace logging;
using namespace graphics;

const int ALPHA_OPAQUE = 255;

const int         WINDOW_WIDTH  = 160;
const int         WINDOW_HEIGHT = 144;
const std::string WINDOW_TITLE  = "GameBoy++";
const auto        SCALE         = 4;

auto main(int, char*[]) noexcept -> int {
    auto _ = Logger{Level::Trace};

    std::default_random_engine             generator;
    std::uniform_int_distribution<uint8_t> distribution{};

    auto window = Window{WINDOW_WIDTH * SCALE, WINDOW_HEIGHT * SCALE, WINDOW_TITLE};
    auto screen = Screen<WINDOW_WIDTH, WINDOW_HEIGHT>{SCALE};

    while (!window.ShouldClose()) {
        auto _ = window.CreateDrawContext();

        for (auto y = 0uz; y < WINDOW_HEIGHT; ++y) {
            for (auto x = 0uz; x < WINDOW_WIDTH; ++x) {
                screen[x, y] = Color{.r = distribution(generator),
                                     .g = distribution(generator),
                                     .b = distribution(generator),
                                     .a = ALPHA_OPAQUE};
            }
        }

        screen.Draw();
    }

    return 0;
}
