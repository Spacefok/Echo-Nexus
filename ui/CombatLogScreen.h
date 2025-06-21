#ifndef UI_COMBATLOGSCREEN_H
#define UI_COMBATLOGSCREEN_H

#include <string>
#include <vector>

#include "ui/UIScreen.h"

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
#endif
