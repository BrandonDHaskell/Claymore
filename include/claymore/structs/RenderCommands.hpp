// RenderCommands.hpp
#pragma once

#include <vector>
#include <string>
#include "Geometry.hpp"

namespace Claymore {

enum class RenderCommandType {
    Rect,
    Button,
    Text,
    Image,
    Custom
};

struct ColorRGBA {
    uint8_t r = 255, g = 255, b = 255, a = 255;
};

struct RenderCommand {
    RenderCommandType type = RenderCommandType::Custom;
    Rect boundingBox;
    ColorRGBA color;
    std::string text;
};

using RenderCommandsArray = std::vector<RenderCommand>;

}   // namespace Claymore