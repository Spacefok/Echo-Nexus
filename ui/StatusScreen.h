#pragma once

#include "ui/UIScreen.h"
#include "ServiceLocator.h"
class Player;

// Экран статуса игрока: здоровье и уровень вируса
class StatusScreen : public UIScreen {
public:
    explicit StatusScreen(ServiceLocator& locator);
    void show() override;
    void hide() override;
    std::string getName() const override;

private:
    ServiceLocator& locator_;
    bool visible_;
};
