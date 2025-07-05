#ifndef __SCREEN_HPP__
#define __SCREEN_HPP__

#include <raylib.h>

#include <cstddef>

#include "color-matrix.hpp"

namespace graphics {

template <size_t width, size_t height>
class Screen {
public:
    constexpr Screen()
        : color_matrix({}),
          image(Image{.data    = color_matrix.get().data(),
                      .width   = width,
                      .height  = height,
                      .mipmaps = 1,
                      .format  = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8}),
          screen(LoadTextureFromImage(image)) {}

    constexpr void Draw() const {
        UpdateTexture(screen, image.data);
        DrawTexture(screen, 0, 0, WHITE);
    }

    constexpr auto operator[](std::size_t index) -> Color& { return color_matrix[index]; }

    constexpr auto operator[](std::size_t index) const -> const Color& { return color_matrix[index]; }

    constexpr auto operator[](std::size_t x, std::size_t y) -> Color& { return color_matrix[y * width + x]; }

    constexpr auto operator[](std::size_t x, std::size_t y) const -> const Color& {
        return color_matrix[y * width + x];
    }

private:
    ColorMatrix<width, height> color_matrix;
    Image                      image;
    Texture2D                  screen;
};

}

#endif  // !__SCREEN_HPP__
