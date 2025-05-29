#include "core/ServiceLocator.h" // Add this include to resolve incomplete type error  
#include "render/HUDRenderer.h"  
#include "entities/Player.h"  
#include <iostream>  

HUDRenderer::HUDRenderer(ServiceLocator& locator)  
    : Locator_(locator) {}  

void HUDRenderer::RenderHud() {  
    auto player = Locator_.Get<Player>();  
    int health = player->GetHealth();  
    int maxHealth = player->GetMaxHealth();  
    float virus = player->GetVirusLevel();  
    std::cout << "Health: " << health << "/" << maxHealth  
              << "  Virus: " << virus << std::endl;  
}
