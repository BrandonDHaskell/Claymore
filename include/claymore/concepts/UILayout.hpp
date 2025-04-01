#pragma once
#include <concepts>

namespace Claymore {

// A UILayout is a higher-order structure that composes UIComponents.
// Still requires buildLayout() as the primary interface.
template<typename T>
concept UILayout = requires(T t) {
    { t.buildLayout() } -> std::same_as<void>;
};

} // namespace Claymore