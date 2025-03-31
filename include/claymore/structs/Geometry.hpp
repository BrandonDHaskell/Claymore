// Geometry.hpp
#pragma once

namespace Claymore {

struct Vec2 {
    float x = 0.0f, y = 0.0f;
};

struct Rect {
    float x = 0.0f, y = 0.0f;
    float width = 0.0f, height = 0.0f;

    inline bool contains(const Vec2& point) const {
        return point.x >= x && point.x <= x + width &&
               point.y >= y && point.y <= y + height;
    }
};

}