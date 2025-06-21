#pragma once

#include <memory>
#include <unordered_map>
#include <string>

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
<<<<<<< Updated upstream
    ServiceLocator& Locator_;
    std::unordered_map<std::string, std::shared_ptr<UIScreen>> Screens_;
    std::string ActiveScreen_;
};
=======
    ServiceLocator& locator_;
    std::unordered_map<std::string, std::shared_ptr<UIScreen>> screens_;
    std::unordered_set<std::string> activeScreens_;
};
>>>>>>> Stashed changes
