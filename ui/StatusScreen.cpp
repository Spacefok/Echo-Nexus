#include "ui/StatusScreen.h"

#include <iostream>

#include "entities/Player.h"

StatusScreen::StatusScreen(ServiceLocator& locator) : locator_(locator), visible_(false) {}

void StatusScreen::show() {
    visible_ = true;
    auto player = locator_.get<Player>();
    std::cout << "HP: " << player->getHealth() << "/" << player->getMaxHealth()
              << "  Virus: " << player->getVirusLevel() << std::endl;
}

void StatusScreen::hide() { visible_ = false; }

std::string StatusScreen::getName() const { return "Status"; }
