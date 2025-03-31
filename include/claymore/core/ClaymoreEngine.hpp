// claymore/core/ClaymoreEngine.hpp
#pragma once

#include "claymore/interfaces/IDisplay.hpp"
#include "claymore/interfaces/IView.hpp"
#include "claymore/interfaces/ILayoutComputer.hpp"
#include "claymore/interfaces/IRenderer.hpp"
#include "claymore/structs/RenderCommands.hpp"

#include <memory>
#include <string_view>

namespace Claymore {

class ClaymoreEngine {
public:
    ClaymoreEngine(std::unique_ptr<IDisplay> display,
                   std::unique_ptr<IView> view,
                   std::unique_ptr<ILayoutComputer> layoutComputer,
                   std::unique_ptr<IRenderer> renderer) noexcept;

    [[nodiscard]] bool initialize(int width, int height, std::string_view title) noexcept;
    void runMainLoop() noexcept;
    void shutdown() noexcept;

private:
    std::unique_ptr<IDisplay> display_;
    std::unique_ptr<IView> view_;
    std::unique_ptr<ILayoutComputer> layoutComputer_;
    std::unique_ptr<IRenderer> renderer_;

    RenderCommandsArray renderCommands_;
};    

}   // namespace Claymore