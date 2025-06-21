#ifndef UI_UISCREEN_H
#define UI_UISCREEN_H

#include <string>

// Base class for UI screens
class UIScreen {
   public:
    virtual ~UIScreen() = default;
    virtual void show() = 0;
    virtual void hide() = 0;
    virtual std::string getName() const = 0;
};
#endif
