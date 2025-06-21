#pragma once
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

// Basic pub-sub event system
class EventSystem {
public:
    using Callback = std::function<void()>;

    // Subscribe a callback to an event name
    void Subscribe(const std::string& eventName, Callback cb);

    // Emit event to all subscribers
    void Emit(const std::string& eventName);

private:
    std::unordered_map<std::string, std::vector<Callback>> Subscribers_;
};
