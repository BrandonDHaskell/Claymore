// ViewMinimal.cpp
#include "claymore/views/ViewMinimal.hpp"
#include "claymore/structs/RenderCommands.hpp"
#include "claymore/structs/Dimension.hpp"
#include "clay.h"

#include <iostream>

namespace Claymore {

ViewMinimal::ViewMinimal() = default;
ViewMinimal::~ViewMinimal() = default;

bool ViewMinimal::initialize() {
    return true;
}

void ViewMinimal::update(const DisplayInput& input) {
    (void)input;
}

void ViewMinimal::buildLayout() {
    layoutCommands_.clear();

    // Using Claymore
    RenderCommand cmd;
    cmd.type = RenderCommandType::Rect;
    cmd.boundingBox = { 100.0f, 100.0f, 250.f, 250.f },
    cmd.color = { 0, 50, 234, 255 };

    layoutCommands_.push_back(cmd);

    // using Clay
    // CLAY({ .layout = layoutElement, .backgroundColor = {255,255,255,0} }) {
    //     CLAY_TEXT(CLAY_STRING(""), CLAY_TEXT_CONFIG({ .fontId = 0 }));
    // }
}

const RenderCommandsArray& ViewMinimal::getRenderCommands() const {
    return layoutCommands_;
}

}