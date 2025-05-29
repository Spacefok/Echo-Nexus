#include "ui/UIManager.h"
#include "ui/UIScreen.h"
#include <iostream>

UIManager::UIManager(ServiceLocator& locator)
    : Locator_(locator), ActiveScreen_("") {}

void UIManager::RegisterScreen(std::shared_ptr<UIScreen> screen) {
    Screens_[screen->GetName()] = screen;
}

void UIManager::ShowScreen(const std::string& name) {
    if (Screens_.count(name)) {
        if (!ActiveScreen_.empty() && Screens_[ActiveScreen_]) {
            Screens_[ActiveScreen_]->Hide();
        }
        ActiveScreen_ = name;
        Screens_[name]->Show();
    }
}

void UIManager::HideScreen(const std::string& name) {
    if (Screens_.count(name) && Screens_[name]) {
        Screens_[name]->Hide();
        if (ActiveScreen_ == name) ActiveScreen_.clear();
    }
}

void UIManager::Update(float /*deltaTime*/) {
    // For demo: show combat log when any
    if (!ActiveScreen_.empty()) {
        Screens_[ActiveScreen_]->Show();
    }
    
    // Input handling can be added here
}
