#pragma once

#include "ui/UIScreen.h"
#include "core/ServiceLocator.h"
class Player;

// Экран статуса игрока: здоровье и уровень вируса
class StatusScreen : public UIScreen {
public:
    explicit StatusScreen(ServiceLocator& locator);
    void Show() override;
    void Hide() override;
    std::string GetName() const override;

private:
    ServiceLocator& Locator_;
    bool Visible_;
};
