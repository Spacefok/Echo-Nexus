#include "core/EventSystem.h"

void EventSystem::Subscribe(const std::string& eventName, Callback cb) {
    Subscribers_[eventName].push_back(std::move(cb));
}

void EventSystem::Emit(const std::string& eventName) {
    auto it = Subscribers_.find(eventName);
    if (it != Subscribers_.end()) {
        for (auto& cb : it->second) {
            cb();
        }
    }
}
