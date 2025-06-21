#include "render/RenderEngine.h"

#include <cstdlib>

#include "core/GameWorld.h"
#include "render/AsciiMapRenderer.h"
#include "render/HUDRenderer.h"

RenderEngine::RenderEngine(ServiceLocator& locator)
    : locator_(locator),
      MapRenderer_(std::make_unique<AsciiMapRenderer>(locator)),
      HudRenderer_(std::make_unique<HUDRenderer>(locator)) {}

void RenderEngine::render() {
    std::system("clear");  // Clear console screen
    auto entities = locator_.get<GameWorld>()->getEntities();
    MapRenderer_->renderMap(entities);
    HudRenderer_->renderHud();
}
