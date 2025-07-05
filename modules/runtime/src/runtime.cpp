#include <raylib.h>

#include <cstdint>
#include <random>
#include <raylib-cpp/raylib-cpp.hpp>

#include "color-matrix.hpp"
#include "log.hpp"
#include "screen.hpp"
#include "window.hpp"

using namespace logging;
using namespace graphics;

const int ALPHA_OPAQUE = 255;

const int         WINDOW_WIDTH  = 160;
const int         WINDOW_HEIGHT = 144;
const std::string WINDOW_TITLE  = "GameBoy++";

auto main(int, char*[]) noexcept -> int {
    auto _ = Logger{Level::Trace};

    std::default_random_engine             generator;
    std::uniform_int_distribution<uint8_t> distribution{};

    auto window       = Window{WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE};
    auto color_matrix = ColorMatrix<WINDOW_WIDTH, WINDOW_HEIGHT>{};
    auto screen       = Screen<WINDOW_WIDTH, WINDOW_HEIGHT>{color_matrix.get().data()};

    while (!window.ShouldClose()) {
        auto _ = window.CreateDrawContext();

        for (auto y = 0uz; y < WINDOW_HEIGHT; ++y) {
            for (auto x = 0uz; x < WINDOW_WIDTH; ++x) {
                color_matrix[x, y] = Color{.r = distribution(generator),
                                           .g = distribution(generator),
                                           .b = distribution(generator),
                                           .a = ALPHA_OPAQUE};
            }
        }

        screen.Draw();
    }

    return 0;
}
