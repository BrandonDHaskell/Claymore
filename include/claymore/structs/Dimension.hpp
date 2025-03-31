/**
 * @file Dimension.hpp
 * @brief A generic, lightweight container for two-dimensional size (width,
 * height).
 *
 * Claymore::Dimension<T> is an *optional*, subsystem-agnostic struct designed
 * to represent the size of any 2D area such as screen dimensions, layout
 * bounds, texture extents, or window sizes. This struct is templated to 
 * support different numeric types (e.g., float, int, unsigned depending on use
 * case. It is intended to be used when the ClaymoreEngine subsystems may not
 * use the same dimension types. (Ex. Clay primarily uses 'float' type,
 * while Raylib uses 'int' type.)
 *
 * @tparam T Numeric type (e.g., float, int, unsigned). Must satisfy
 * std::is_arithmetic.
 *
 * ## Design Goals:
 * - **Minimal**: No behavior beyond storage and conversion.
 * - **Generic**: Avoids coupling to rendering or layout engines.
 * - **Trivial**: POD-type, trivially copyable, zero-cost abstraction.
 * - **Safe**: Type-checked at compile time via `static_assert`.
 *
 * ## Example:
 * @code
 * using namespace Claymore;
 * 
 * Dimension<float> layoutSize(1920.5f, 1080.5f);
 * Dimension<int> screenSize = layoutSize.cast<int>();
 * 
 * framebuffer.resize(screenSize.width, screenSize.height);
 * @endcode
 *
 * ## Common Type Aliases:
 * - `DimensionF`: float (layout precision)
 * - `DimensionI`: int (pixel coordinates)
 * - `DimensionU`: unsigned (buffer sizes)
 *
 * @note This type does not define comparison, area, or scaling operations.
 *       These should be handled by higher-level abstractions (e.g., `Rect<T>`, `Box<T>`).
 */

// claymore/structs/Dimension.hpp
#pragma once

#include <type_traits>

namespace Claymore {

template<typename T>
struct Dimension {
    static_assert(std::is_arithmetic_v<T>, "Dimension<T> must be a numeric type");

    T width;
    T height;

    constexpr Dimension() : width(0), height(0) {}
    constexpr Dimension(T w, T h) : width(w), height(h) {}

    template<typename U>
    constexpr Dimension<U> cast() const {
        return Dimension<U>(
            static_cast<U>(width),
            static_cast<U>(height)
        );
    }
};

// Type aliases for usage
using DimensionF = Dimension<float>;
using DimensionI = Dimension<int>;
using DimensionU = Dimension<unsigned>;

} // namespace Claymore