#ifndef __GAMEBOY_SCREEN_HPP__
#define __GAMEBOY_SCREEN_HPP__

#include <raylib.h>

#include "pixel-array.hpp"
#include "window.hpp"

namespace graphics {

class GameboyScreen {
public:
    constexpr GameboyScreen() {
        image  = Image{.data    = pixel_array.get().data(),
                       .width   = SCREEN_WIDTH,
                       .height  = SCREEN_HEIGHT,
                       .mipmaps = 1,
                       .format  = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8};
        screen = LoadTextureFromImage(image);
    }

    constexpr void Draw() const {
        UpdateTexture(screen, image.data);
        DrawTexture(screen, 0, 0, WHITE);
    }

    constexpr Color& operator[](std::size_t x, std::size_t y) { return pixel_array[x, y]; }

    constexpr const Color& operator[](std::size_t x, std::size_t y) const { return pixel_array[x, y]; }

private:
    PixelArray<SCREEN_WIDTH, SCREEN_HEIGHT> pixel_array;
    Image                                   image;
    Texture2D                               screen;
};

}

#endif  // !__GAMEBOY_SCREEN_HPP__
