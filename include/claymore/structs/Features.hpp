// Features.hpp
#pragma once

#include "Geometry.hpp"

namespace Claymore {

// Hoverable state feature
struct Hoverable {
    bool isHovered = false;
};

// Selectable state feature
struct Selectable {
    bool isSelected = false;
};

// Active state feature
struct Active {
    bool isActive = false;
};

// Draggable state feature
struct Draggable {
    bool isDragging = false;
    Vec2 dragOffset = {0, 0};
};

} // namespace Claymore