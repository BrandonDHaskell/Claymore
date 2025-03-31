#pragma once

#include "claymore/interfaces/IRenderer.hpp"

namespace Claymore {

class RendererRaylib final : public IRenderer {
public:
    RendererRaylib();
    ~RendererRaylib() override;

    bool initialize() override;
    void beginFrame() override;
    void render(const RenderCommandsArray& commands) override;
    void endFrame() override;
    void shutdown() override;
};

} // namespace Claymore