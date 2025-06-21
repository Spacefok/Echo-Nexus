#include "ui/UIManager.h"
#include "ui/UIScreen.h"
#include <iostream>

UIManager::UIManager(ServiceLocator& locator)
    : Locator_(locator) {}

void UIManager::RegisterScreen(std::shared_ptr<UIScreen> screen) {
    Screens_[screen->GetName()] = screen;
}

void UIManager::ShowScreen(const std::string& name) {
    if (Screens_.count(name)) {
        ActiveScreens_.insert(name);
        Screens_[name]->Show();
    }
}

void UIManager::HideScreen(const std::string& name) {
    if (Screens_.count(name) && Screens_[name]) {
        Screens_[name]->Hide();
        ActiveScreens_.erase(name);
    }
}

void UIManager::Update(float /*deltaTime*/) {
    for (const auto& name : ActiveScreens_) {
        auto it = Screens_.find(name);
        if (it != Screens_.end()) {
            it->second->Show();
        }
    }
    
    // Input handling can be added here
}
