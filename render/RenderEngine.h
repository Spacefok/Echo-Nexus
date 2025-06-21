#pragma once

#include <memory>
#include "core/ServiceLocator.h"

class AsciiMapRenderer;
class HUDRenderer;

// Coordinates rendering of game world and HUD
class RenderEngine {
public:
    explicit RenderEngine(ServiceLocator& locator);
    void render();

private:
    ServiceLocator& locator_;
    std::unique_ptr<AsciiMapRenderer> MapRenderer_;
    std::unique_ptr<HUDRenderer> HudRenderer_;
};
