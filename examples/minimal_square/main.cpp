#include "raylib.h"
#include "clay.h"
#include "../../include/claymore/layout/clay_layout_computer.h"

// Global settings
constexpr int screenWidth = 800;
constexpr int screenHeight = 600;

// Clay Adapter
claymore::ClayAdapter layoutAdapter;


//--------------------------------------------------
// BEGIN: clay_adapter candidate code
//--------------------------------------------------

// Basic renderer for Clay rectangles using Raylib
void DrawClayRenderCommands(const Clay_RenderCommandArray& commands) {
    for (int i = 0; i < commands.length; ++i) {
        const Clay_RenderCommand& cmd = commands.internalArray[i];
        if (cmd.commandType == CLAY_RENDER_COMMAND_TYPE_RECTANGLE) {
            const auto& box = cmd.boundingBox;
            const auto& color = cmd.renderData.rectangle.backgroundColor;

            DrawRectangle(
                static_cast<int>(box.x),
                static_cast<int>(box.y),
                static_cast<int>(box.width),
                static_cast<int>(box.height),
                Color {
                    static_cast<unsigned char>(color.r),
                    static_cast<unsigned char>(color.g),
                    static_cast<unsigned char>(color.b),
                    static_cast<unsigned char>(color.a)
                }
            );
        }
    }
}

//--------------------------------------------------
// END: clay_adapter candidate code
//--------------------------------------------------

int main() {

    // Initialize Raylib
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Claymore: Minimal Square");
    SetTargetFPS(60);

    layoutAdapter.init(screenWidth, screenHeight);

    while (!WindowShouldClose()) {
        
        //--------------------------------------------------
        // BEGIN: raylib_adapter candidate code
        //--------------------------------------------------

        // Get and set window dimensions (Raylib)
        int w = GetScreenWidth();
        int h = GetScreenHeight();

        //--------------------------------------------------
        // END:   raylib_adapter candidate code
        //--------------------------------------------------

        layoutAdapter.setLayoutSize(w, h);
        layoutAdapter.beginLayout();

        //--------------------------------------------------
        // BEGIN: ui_system candidate code
        //--------------------------------------------------

        // Declare a single square
        CLAY({ 
            .id = CLAY_ID("Background"),
            .layout = CLAY__INIT(Clay_LayoutConfig) {
                .sizing = { CLAY_SIZING_PERCENT(1.0f), CLAY_SIZING_PERCENT(1.0f) },
                .childAlignment = {CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER},
                .layoutDirection = CLAY_TOP_TO_BOTTOM
            },
            .backgroundColor = { 85, 85, 95, 255 }
        }) {
            CLAY({
                .id = CLAY_ID("Square"),
                .layout = CLAY__INIT(Clay_LayoutConfig) {
                    .sizing = {
                        .width = CLAY_SIZING_FIXED(200),
                        .height = CLAY_SIZING_FIXED(200)
                    },
                    .layoutDirection = CLAY_LEFT_TO_RIGHT,
                },
                .backgroundColor = { 0, 0, 255, 255 }, // Blue square
            });
        };

        //--------------------------------------------------
        // END:   ui_system candidate code
        //--------------------------------------------------
    
        Clay_RenderCommandArray commands = layoutAdapter.endLayout();

        //--------------------------------------------------
        // BEGIN: raylib_adapter candidate code
        //--------------------------------------------------

        // Begin Raylib draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (commands.length > 0) {
            DrawClayRenderCommands(commands);
        }
        EndDrawing();

        //--------------------------------------------------
        // END:   raylib_adapter candidate code
        //--------------------------------------------------
    }

    // Cleanup
    layoutAdapter.shutdown();
    CloseWindow();
    return 0;
}
