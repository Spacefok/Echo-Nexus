#ifndef UI_UIMANAGER_H
#define UI_UIMANAGER_H

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>

class ServiceLocator;
class UIScreen;

// Manages multiple UI screens and input
class UIManager {
   public:
    explicit UIManager(ServiceLocator& locator);

    // Register a screen
    void registerScreen(std::shared_ptr<UIScreen> screen);

    // show() a screen by name
    void showScreen(const std::string& name);

    // hide() a screen by name
    void hideScreen(const std::string& name);

    // Update UI (handle input, draw active screens)
    void update(float deltaTime);

   private:
    ServiceLocator& locator_;
    std::unordered_map<std::string, std::shared_ptr<UIScreen>> screens_;
    std::unordered_set<std::string> activeScreens_;
};
#endif
