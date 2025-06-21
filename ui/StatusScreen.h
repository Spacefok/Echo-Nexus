#ifndef UI_STATUSSCREEN_H
#define UI_STATUSSCREEN_H

#include "ServiceLocator.h"
#include "ui/UIScreen.h"
class Player;

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
#endif
