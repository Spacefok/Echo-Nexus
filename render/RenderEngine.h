#pragma once

#include <memory>
#include "ServiceLocator.h"

class AsciiMapRenderer;
class HUDRenderer;

// Coordinates rendering of game world and HUD
class RenderEngine {
public:
    explicit RenderEngine(ServiceLocator& locator);
    void Render();  // Render a full frame

private:
    ServiceLocator& Locator_;
    std::unique_ptr<AsciiMapRenderer> MapRenderer_;
    std::unique_ptr<HUDRenderer> HudRenderer_;
};