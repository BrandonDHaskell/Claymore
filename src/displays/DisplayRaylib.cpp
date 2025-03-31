// DisplayRaylib.cpp
#include "claymore/displays/DisplayRaylib.hpp"

namespace Claymore {

DisplayRaylib::DisplayRaylib() = default;

DisplayRaylib::~DisplayRaylib() {
    if (isOpen_) {
        close();
    }
}

bool DisplayRaylib::initialize(int width, int height, const char* title) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, title);
    SetTargetFPS(60);
    isOpen_ = true;
    return true;
}

DimensionF DisplayRaylib::getDisplaySize() {
    return {
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())
    };
}

DisplayInput DisplayRaylib::pollEvents() {
    DisplayInput input{};
    input.mouse.x = static_cast<float>(GetMouseX());
    input.mouse.y = static_cast<float>(GetMouseY());
    input.mouse.isPrimaryButtonPressed = IsMouseButtonDown(MOUSE_LEFT_BUTTON);
    return input;
}

bool DisplayRaylib::shouldClose() const {
    return WindowShouldClose();
}

void DisplayRaylib::close() {
    CloseWindow();
    isOpen_ = false;
}

}  // namespace Claymore
