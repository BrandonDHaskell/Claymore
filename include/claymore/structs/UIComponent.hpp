// UIComponent.hpp
#pragma once

#include "Geometry.hpp"
#include "RenderCommands.hpp"

namespace Claymore {

struct UIComponent {
    Rect boundingBox;
    ColorRGBA color;
    std::string label; // Optional for components that require text
};

} // namespace claymore