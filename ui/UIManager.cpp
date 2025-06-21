#include "ui/UIManager.h"
#include "ui/UIScreen.h"
#include <iostream>

UIManager::UIManager(ServiceLocator& locator)
    : locator_(locator) {}

void UIManager::registerScreen(std::shared_ptr<UIScreen> screen) {
    screens_[screen->getName()] = screen;
}

void UIManager::showScreen(const std::string& name) {
    if (screens_.count(name)) {
        activeScreens_.insert(name);
        screens_[name]->show();
    }
}

void UIManager::hideScreen(const std::string& name) {
    if (screens_.count(name) && screens_[name]) {
        screens_[name]->hide();
        activeScreens_.erase(name);
    }
}

void UIManager::update(float /*deltaTime*/) {
    for (const auto& name : activeScreens_) {
        auto it = screens_.find(name);
        if (it != screens_.end()) {
            it->second->show();
        }
    }
    
    // Input handling can be added here
}
