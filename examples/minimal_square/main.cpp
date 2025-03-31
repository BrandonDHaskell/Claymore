#include "claymore/core/ClaymoreEngine.hpp"
#include "claymore/displays/DisplayRaylib.hpp"
#include "claymore/views/ViewMinimal.hpp"
#include "claymore/layout_computers/LayoutComputerClay.hpp"
#include "claymore/renderers/RendererRaylib.hpp"

using namespace Claymore;

int main() {
    auto display = std::make_unique<DisplayRaylib>();
    auto view = std::make_unique<ViewMinimal>();
    auto layoutComputer = std::make_unique<LayoutComputerClay>();
    auto renderer = std::make_unique<RendererRaylib>();

    ClaymoreEngine engine(std::move(display), std::move(view), std::move(layoutComputer), std::move(renderer));
    
    if (!engine.initialize(800, 600, "Minimal Claymore App")) {
        return 1;
    }

    engine.runMainLoop();
    engine.shutdown();

    return 0;
}
