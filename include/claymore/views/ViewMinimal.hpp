// ViewMinimal.hpp
#pragma once

#include "claymore/interfaces/IView.hpp"
#include "claymore/structs/RenderCommands.hpp"

namespace Claymore {

class ViewMinimal : public IView {
public:
    ViewMinimal();
    ~ViewMinimal() override;

    bool initialize() override;
    void update(const DisplayInput& input) override;
    void buildLayout() override;
    const RenderCommandsArray& getRenderCommands() const;

private:
    RenderCommandsArray layoutCommands_;
};

} // namespace Claymore