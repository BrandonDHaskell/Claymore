#pragma once
#include <concepts>

namespace Claymore {

// A UIComponent must implement a parameterless buildLayout() method
template<typename T>
concept UIComponent = requires(T t) {
    { t.buildLayout() } -> std::same_as<void>;
};

} // namespace Claymore
