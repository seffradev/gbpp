#ifndef __GAMEBOY_SCREEN_HPP__
#define __GAMEBOY_SCREEN_HPP__

#include <raylib.h>

#include <cstddef>

namespace graphics {

template <size_t width, size_t height>
class Screen {
public:
    constexpr Screen(void* pixel_data)
        : image(Image{.data    = pixel_data,
                      .width   = width,
                      .height  = height,
                      .mipmaps = 1,
                      .format  = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8}),
          screen(LoadTextureFromImage(image)) {}

    constexpr void Draw() const {
        UpdateTexture(screen, image.data);
        DrawTexture(screen, 0, 0, WHITE);
    }

private:
    Image     image;
    Texture2D screen;
};

}

#endif  // !__GAMEBOY_SCREEN_HPP__
