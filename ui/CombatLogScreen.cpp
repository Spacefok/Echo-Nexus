#include "ui/CombatLogScreen.h"
#include <iostream>

CombatLogScreen::CombatLogScreen()
    : visible_(false) {}

void CombatLogScreen::show() {
    visible_ = true;
    std::cout << "--- Combat Log ---\n";
    for (const auto& e : entries_) {
        std::cout << e << "\n";
    }
}

void CombatLogScreen::hide() {
    visible_ = false;
}

std::string CombatLogScreen::getName() const {
    return "CombatLog";
}

void CombatLogScreen::addEntry(const std::string& entry) {
    entries_.push_back(entry);
    if (visible_) show();
}
