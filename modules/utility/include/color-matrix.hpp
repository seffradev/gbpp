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
    constexpr decltype(data)& get() { return data; }

    constexpr const decltype(data)& get() const { return data; }

    constexpr Color& operator[](std::size_t index) { return data[index]; }

    constexpr const Color& operator[](std::size_t index) const { return data[index]; }

    constexpr Color& operator[](std::size_t x, std::size_t y) { return data[y * width + x]; }

    constexpr const Color& operator[](std::size_t x, std::size_t y) const { return data[y * width + x]; }
};

}

#endif  // !__PIXEL_ARRAY_HPP__
