// IDisplay.hpp
#pragma once

#include "claymore/structs/DisplayInput.hpp"
#include "claymore/structs/Dimension.hpp"

namespace Claymore {

class IDisplay {
public:
    virtual ~IDisplay() = default;

    virtual bool initialize(int width, int heigh, const char* title) = 0;
    virtual DimensionF getDisplaySize() = 0;
    virtual DisplayInput pollEvents() = 0;
    virtual bool shouldClose() const = 0;
    virtual void close() = 0;
};

}   // namespace Claymore