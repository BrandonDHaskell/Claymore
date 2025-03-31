// ILayoutComputer.hpp
#pragma once

#include "claymore/interfaces/IView.hpp"
#include "claymore/structs/RenderCommands.hpp"
#include "claymore/structs/DisplayInput.hpp"
#include "claymore/structs/Dimension.hpp"       // optional, see Dimension notes for use

namespace Claymore{

class ILayoutComputer {
public:
    virtual ~ILayoutComputer() = default;
    
    virtual bool initialize(const DimensionF& dimensions) = 0;
    virtual void updateInput(const DisplayInput& input) = 0;
    virtual void computeLayout(IView& view, RenderCommandsArray& commands) = 0;
};

}   // namespace Claymore