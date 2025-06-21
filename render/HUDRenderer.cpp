#include "render/HUDRenderer.h"

#include <iostream>

#include "core/ServiceLocator.h"  // Add this include to resolve incomplete type error
#include "entities/Player.h"

HUDRenderer::HUDRenderer(ServiceLocator& locator) : locator_(locator) {}

void HUDRenderer::renderHud() {
    auto player = locator_.get<Player>();
    int health = player->getHealth();
    int maxHealth = player->getMaxHealth();
    float virus = player->getVirusLevel();
    std::cout << "Health: " << health << "/" << maxHealth << "  Virus: " << virus << std::endl;
}
