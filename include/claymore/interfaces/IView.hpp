// IView.hpp
#pragma once

#include "claymore/structs/RenderCommands.hpp"
#include "claymore/structs/DisplayInput.hpp"

namespace Claymore {

class IView {
public:
    virtual ~IView() = default;

    virtual bool initialize() = 0;
    
    // Process input and update state
    virtual void update(const DisplayInput& input) = 0;

    // Declarative layout declaration
    virtual void buildLayout() = 0;

    virtual const RenderCommandsArray& getRenderCommands() const = 0;
};

}   // namespace Claymore