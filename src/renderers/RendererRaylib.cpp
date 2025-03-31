#include "claymore/renderers/RendererRaylib.hpp"
#include "claymore/structs/DisplayInput.hpp"
#include "raylib.h"

namespace Claymore {

    RendererRaylib::RendererRaylib() = default;
    RendererRaylib::~RendererRaylib() = default;

bool RendererRaylib::initialize() {
//     SetConfigFlags(FLAG_WINDOW_RESIZABLE);
//     // TODO: carry forward Window title for Raylib
//     InitWindow(width, height, "Claymore minimal_square example");
//     SetTargetFPS(60);
    
    return true;
}

void RendererRaylib::beginFrame() {
    // if (!windowInitialized) return;
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void RendererRaylib::render(const RenderCommandsArray& commands) {
    for (const auto& cmd : commands) {
        if (cmd.type == RenderCommandType::Rect) {
            DrawRectangle(
                static_cast<int>(cmd.boundingBox.x),
                static_cast<int>(cmd.boundingBox.y),
                static_cast<int>(cmd.boundingBox.width),
                static_cast<int>(cmd.boundingBox.height),
                Color {
                    cmd.color.r,
                    cmd.color.g,
                    cmd.color.b,
                    cmd.color.a
                }
            );
        }
    }
        // TODO: Handle more command types in the future.
}

void RendererRaylib::endFrame() {
    EndDrawing();
}

void RendererRaylib::shutdown() {
}

} // namespace claymore
