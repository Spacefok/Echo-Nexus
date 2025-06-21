#include "ui/UIManager.h"
#include "ui/UIScreen.h"
#include <iostream>

UIManager::UIManager(ServiceLocator& locator)
<<<<<<< Updated upstream
    : Locator_(locator), ActiveScreen_("") {}
=======
    : locator_(locator) {}
>>>>>>> Stashed changes

void UIManager::registerScreen(std::shared_ptr<UIScreen> screen) {
    screens_[screen->getName()] = screen;
}

<<<<<<< Updated upstream
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
=======
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
>>>>>>> Stashed changes
    }
    
    // Input handling can be added here
}
