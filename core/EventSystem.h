#ifndef CORE_EVENTSYSTEM_H
#define CORE_EVENTSYSTEM_H
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

// Basic pub-sub event system
class EventSystem {
   public:
    using Callback = std::function<void()>;

    // Subscribe a callback to an event name
    void subscribe(const std::string& eventName, Callback cb);

    // Emit event to all subscribers
    void emit(const std::string& eventName);

   private:
    std::unordered_map<std::string, std::vector<Callback>> subscribers_;
};
#endif
