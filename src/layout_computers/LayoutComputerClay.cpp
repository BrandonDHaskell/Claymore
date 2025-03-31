#define CLAY_IMPLEMENTATION
#include "clay.h"

#include "claymore/layout_computers/LayoutComputerClay.hpp"
#include <cstdio>

namespace Claymore {

// --- ClayArenaManager ---

LayoutComputerClay::ClayArenaManager::ClayArenaManager() {
    capacity_ = Clay_MinMemorySize();
    memory_ = std::make_unique<char[]>(capacity_);
    arena_ = Clay_CreateArenaWithCapacityAndMemory(capacity_, memory_.get());
}

Clay_Arena LayoutComputerClay::ClayArenaManager::getArena() const {
    return arena_;
}

// --- LayoutComputerclay ---

LayoutComputerClay::LayoutComputerClay()
    : layoutSize_{800.0f, 600.0f}, arenaManager_() {

    Clay_ErrorHandler errorHandler = {
        +[](Clay_ErrorData err) {
            std::printf("[Clay] Layout Error: %s\n", err.errorText.chars);
        },
        nullptr
    };

    Clay_Initialize(
        arenaManager_.getArena(),
        Clay_Dimensions {layoutSize_.width, layoutSize_.height},
        errorHandler   
    );
}

LayoutComputerClay::~LayoutComputerClay() = default;

bool LayoutComputerClay::initialize(const DimensionF& size) {
    layoutSize_ = size;
    Clay_SetLayoutDimensions({ size.width, size.height });
    return true;
}

void LayoutComputerClay::updateInput(const DisplayInput& input) {
    Clay_SetPointerState(
        { .x = input.mouse.x, .y = input.mouse.y },
        input.mouse.isPrimaryButtonPressed
    );

    Clay_SetLayoutDimensions({ layoutSize_.width, layoutSize_.height });
}

void LayoutComputerClay::computeLayout(IView& view, RenderCommandsArray& outCommands) {
    Clay_BeginLayout();
    view.buildLayout();
    Clay_RenderCommandArray clayCommands = Clay_EndLayout();

    outCommands.clear();
    outCommands.reserve(clayCommands.length);

    for (int i = 0; i < clayCommands.length; ++i) {
        const auto& cmd = clayCommands.internalArray[i];
        
        if (cmd.commandType == CLAY_RENDER_COMMAND_TYPE_RECTANGLE) {
            RenderCommand rcmd;
            rcmd.type = RenderCommandType::Rect;
            rcmd.boundingBox = {
                cmd.boundingBox.x,
                cmd.boundingBox.y,
                cmd.boundingBox.width,
                cmd.boundingBox.height
            };

            rcmd.color = {
                static_cast<uint8_t>(cmd.renderData.rectangle.backgroundColor.r),
                static_cast<uint8_t>(cmd.renderData.rectangle.backgroundColor.g),
                static_cast<uint8_t>(cmd.renderData.rectangle.backgroundColor.b),
                static_cast<uint8_t>(cmd.renderData.rectangle.backgroundColor.a),
            };
            outCommands.push_back(rcmd);
        }
    }

    // Append view-supplied render commands (e.g. custom drawables)
    const auto& viewCommands = view.getRenderCommands();
    outCommands.insert(outCommands.end(), viewCommands.begin(), viewCommands.end());
}

} // namespace Claymore
