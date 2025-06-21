#include "core/EventSystem.h"

void EventSystem::subscribe(const std::string& eventName, Callback cb) {
    subscribers_[eventName].push_back(std::move(cb));
}

void EventSystem::emit(const std::string& eventName) {
    auto it = subscribers_.find(eventName);
    if (it != subscribers_.end()) {
        for (auto& cb : it->second) {
            cb();
        }
    }
}
