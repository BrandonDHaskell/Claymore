#include "raylib.h"

#define CLAY_IMPLEMENTATION
#include "../../external/clay/clay.h"

//--------------------------------------------------
// BEGIN: clay_adapter candidate code
//--------------------------------------------------

// Clay global settings
constexpr int screenWidth = 800;
constexpr int screenHeight = 600;
uint32_t clayMemorySize = Clay_MinMemorySize();    // Clay arena

// Simple text measurement function (needed by Clay)
Clay_Dimensions MeasureTextFunc(Clay_StringSlice text, Clay_TextElementConfig* config, void* userData) {
    (void)userData;
    int fontSize = config->fontSize > 0 ? config->fontSize : 20;
    return Clay_Dimensions {
        static_cast<float>(MeasureTextEx(GetFontDefault(), text.chars, (float)fontSize, 0).x),
        static_cast<float>(fontSize),
    };
}

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

    //--------------------------------------------------
    // BEGIN: clay_adapter candidate code
    //--------------------------------------------------
    
    // Initialize Raylib
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Claymore: Minimal Square");
    SetTargetFPS(60);

    // Allocate Clay memory
    void* memory = malloc(clayMemorySize);
    Clay_Arena arena = Clay_CreateArenaWithCapacityAndMemory(clayMemorySize, memory);

    // Optional error handler
    Clay_ErrorHandler handler = { nullptr, nullptr };

    // Initialize Clay
    Clay_Context* ctx = Clay_Initialize(arena, Clay_Dimensions{ (float)screenWidth, (float)screenHeight }, handler);
    Clay_SetMeasureTextFunction(MeasureTextFunc, nullptr);

    //--------------------------------------------------
    // END:   clay_adapter candidate code
    //--------------------------------------------------

    while (!WindowShouldClose()) {
        
        //--------------------------------------------------
        // BEGIN: raylib_adapter candidate code
        //--------------------------------------------------

        // Get and set window dimensions
        int w = GetScreenWidth();
        int h = GetScreenHeight();

        //--------------------------------------------------
        // END:   raylib_adapter candidate code
        //--------------------------------------------------


        //--------------------------------------------------
        // BEGIN: clay_adapter candidate code
        //--------------------------------------------------

        Clay_SetLayoutDimensions({ (float)w, (float)h });
        // Per-frame layout setup
        Clay_BeginLayout();

        //--------------------------------------------------
        // END: clay_adapter candidate code
        //--------------------------------------------------

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
    
        //--------------------------------------------------
        // BEGIN: clay_adapter candidate code
        //--------------------------------------------------

        // End layout and get render commands
        Clay_RenderCommandArray commands = Clay_EndLayout();

        //--------------------------------------------------
        // END: clay_adapter candidate code
        //--------------------------------------------------

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
    free(memory);
    CloseWindow();
    return 0;
}
