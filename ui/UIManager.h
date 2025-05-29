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
    void RegisterScreen(std::shared_ptr<UIScreen> screen);

    // Show a screen by name
    void ShowScreen(const std::string& name);

    // Hide a screen by name
    void HideScreen(const std::string& name);

    // Update UI (handle input, draw active screens)
    void Update(float deltaTime);

private:
    ServiceLocator& Locator_;
    std::unordered_map<std::string, std::shared_ptr<UIScreen>> Screens_;
    std::string ActiveScreen_;
};