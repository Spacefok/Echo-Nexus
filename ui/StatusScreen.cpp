#include "ui/StatusScreen.h"
#include "entities/Player.h"
#include <iostream>

StatusScreen::StatusScreen(ServiceLocator& locator)
    : Locator_(locator), Visible_(false) {}

void StatusScreen::Show() {
    Visible_ = true;
    auto player = Locator_.Get<Player>();
    std::cout << "HP: " << player->GetHealth() << "/" << player->GetMaxHealth()
              << "  Virus: " << player->GetVirusLevel() << std::endl;
}

void StatusScreen::Hide() {
    Visible_ = false;
}

std::string StatusScreen::GetName() const {
    return "Status";
}
