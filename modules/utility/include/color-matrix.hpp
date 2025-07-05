#ifndef __PIXEL_ARRAY_HPP__
#define __PIXEL_ARRAY_HPP__

#include <raylib.h>

#include <array>
#include <cstddef>

namespace graphics {

template <size_t width, size_t height>
class ColorMatrix {
private:
    std::array<Color, width * height> data;

public:
    constexpr auto get() -> decltype(data)& { return data; }

    constexpr auto get() const -> const decltype(data)& { return data; }

    constexpr auto operator[](std::size_t index) -> Color& { return data[index]; }

    constexpr auto operator[](std::size_t index) const -> const Color& { return data[index]; }

    constexpr auto operator[](std::size_t x, std::size_t y) -> Color& { return data[y * width + x]; }

    constexpr auto operator[](std::size_t x, std::size_t y) const -> const Color& { return data[y * width + x]; }
};

}

#endif  // !__PIXEL_ARRAY_HPP__
