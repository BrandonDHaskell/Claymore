// DisplayInput.hpp
#pragma once

namespace Claymore {

struct PointerInput {
    float x = 0.0f;
    float y = 0.0f;
    bool isPrimaryButtonPressed = false;
    bool isSecondaryButtonPressed = false;
};

struct KeyboardInput {
    int keyCode = 0;
    bool isPressed = false;
};

struct DisplaySize {
    int x = 0;
    int y = 0;
};

struct DisplayInput {
    DisplaySize display;
    PointerInput mouse;
    KeyboardInput keyboard;
    float displayWidth = 0.0f;
    float displayHeight = 0.0f;
};

}   // namespace Claymore