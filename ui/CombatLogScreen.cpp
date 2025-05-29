#include "ui/CombatLogScreen.h"
#include <iostream>

CombatLogScreen::CombatLogScreen()
    : Visible_(false) {}

void CombatLogScreen::Show() {
    Visible_ = true;
    std::cout << "--- Combat Log ---\n";
    for (const auto& e : Entries_) {
        std::cout << e << "\n";
    }
}

void CombatLogScreen::Hide() {
    Visible_ = false;
}

std::string CombatLogScreen::GetName() const {
    return "CombatLog";
}

void CombatLogScreen::AddEntry(const std::string& entry) {
    Entries_.push_back(entry);
    if (Visible_) Show();
}