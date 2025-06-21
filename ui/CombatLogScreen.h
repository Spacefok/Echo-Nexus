#pragma once

#include "ui/UIScreen.h"
#include <vector>
#include <string>

// Screen to display combat logs
class CombatLogScreen : public UIScreen {
public:
    CombatLogScreen();
    void show() override;
    void hide() override;
    std::string getName() const override;

    // Add a new log entry
    void addEntry(const std::string& entry);

private:
    bool visible_;
    std::vector<std::string> entries_;
};
