#include "render/RenderEngine.h"
#include "render/AsciiMapRenderer.h"
#include "render/HUDRenderer.h"
#include "core/GameWorld.h"
#include <cstdlib>

RenderEngine::RenderEngine(ServiceLocator& locator)
    : Locator_(locator),
      MapRenderer_(std::make_unique<AsciiMapRenderer>(locator)),
      HudRenderer_(std::make_unique<HUDRenderer>(locator)) {}

void RenderEngine::Render() {
    std::system("clear");  // Clear console screen
    auto entities = Locator_.Get<GameWorld>()->GetEntities();
    MapRenderer_->RenderMap(entities);
    HudRenderer_->RenderHud();
}
