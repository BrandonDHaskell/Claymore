// DisplayRaylib.hpp
#pragma once

#include "claymore/interfaces/IDisplay.hpp"
#include "raylib.h"

namespace Claymore {

class DisplayRaylib final : public IDisplay {
public:
    DisplayRaylib();
    ~DisplayRaylib() override;

    bool initialize(int width, int height, const char* title) override;
    DimensionF getDisplaySize() override;
    DisplayInput pollEvents() override;
    bool shouldClose() const override;
    void close() override;

private:
    bool isOpen_ = false;
};

} // namespace Claymore