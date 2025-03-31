// IRenderer.hpp
#pragma once

#include "../structs/RenderCommands.hpp"

namespace Claymore {

class IRenderer {
public:
    virtual ~IRenderer() = default;

    virtual bool initialize() = 0;
    virtual void beginFrame() = 0;
    virtual void render(const RenderCommandsArray& commands) = 0;
    virtual void endFrame() = 0;
    virtual void shutdown() = 0;
     
};

} // namespace Claymore