// LayoutComputerClay.hpp
#pragma once

#include "claymore/interfaces/ILayoutComputer.hpp"
#include "clay.h"

#include <memory>

namespace Claymore {

class LayoutComputerClay : public ILayoutComputer {
public:
    LayoutComputerClay();
    ~LayoutComputerClay() override;
    
    bool initialize(const DimensionF& size) override;
    void updateInput(const DisplayInput& input) override;
    void computeLayout(IView& view, RenderCommandsArray& commands) override;

private:
    // Possible move this to another file if needed
    class ClayArenaManager {
    public:
        ClayArenaManager();
        ~ClayArenaManager() = default;

        Clay_Arena getArena() const;

    private:
        size_t capacity_;
        std::unique_ptr<char[]> memory_;
        Clay_Arena arena_;
    };

    DimensionF layoutSize_;
    ClayArenaManager arenaManager_;
};

} // namespace Claymore
