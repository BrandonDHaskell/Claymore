#include "claymore/core/ClaymoreEngine.hpp"

#include <iostream>

namespace Claymore {

ClaymoreEngine::ClaymoreEngine(std::unique_ptr<IDisplay> display,
                               std::unique_ptr<IView> view,
                               std::unique_ptr<ILayoutComputer> layoutComputer,
                               std::unique_ptr<IRenderer> renderer) noexcept
    : display_(std::move(display)),
      view_(std::move(view)),
      layoutComputer_(std::move(layoutComputer)),
      renderer_(std::move(renderer)) {}

bool ClaymoreEngine::initialize(int width, int height, std::string_view title) noexcept {
    // TODO: Remove err after implementing logging
    if (!display_->initialize(width, height, title.data())) {
        std::cerr << "[Claymore] Failed to initialize display.\n";
        return false;
    }

    DimensionF dims(static_cast<float>(width), static_cast<float>(height));
    if (!layoutComputer_->initialize(dims)) {
        std::cerr << "[Claymore] Failed to initialize layout system.\n";
        return false;    
    }

    if (!view_->initialize()) {
        std::cerr << "[Claymore] Failed to initialize view.\n";
        return false;
    }

    if (!renderer_->initialize()) {
        std::cerr << "[Claymore] Failed to initialize renderer.\n";
        return false;
    }

    // All initializer checks are good
    return true;
}

void ClaymoreEngine::runMainLoop() noexcept {
    while (!display_->shouldClose()) {
        // TODO: pass deltaTime into view_->update() if needed
        DisplayInput input = display_->pollEvents();

        view_->update(input);
        view_->buildLayout();
        layoutComputer_->updateInput(input);

        renderCommands_.clear();
        layoutComputer_->computeLayout(*view_, renderCommands_);

        renderer_->beginFrame();
        renderer_->render(renderCommands_);
        renderer_->endFrame();
    }
}

void ClaymoreEngine::shutdown() noexcept {
    renderer_->shutdown();
    display_->close();
}

}   // namespace Claymore