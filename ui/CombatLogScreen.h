#pragma once

#include "ui/UIScreen.h"
#include <vector>
#include <string>

// Screen to display combat logs
class CombatLogScreen : public UIScreen {
public:
    CombatLogScreen();
    void Show() override;
    void Hide() override;
    std::string GetName() const override;

    // Add a new log entry
    void AddEntry(const std::string& entry);

private:
    bool Visible_;
    std::vector<std::string> Entries_;
};
