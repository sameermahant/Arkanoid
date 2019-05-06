#pragma once

#include <stdint.h>

namespace Settings {

constexpr uint32_t windowWidth{800}, windowHeight{600};
constexpr char windowTitle[] = "Arkanoid";

constexpr int brickRows{4};
constexpr int brickColumns{11};
constexpr float brickSpacing{3.0f};
constexpr float brickOffsetX{22.0f};
constexpr float brickOffsetY{22.0f};

} // namespace Settings
