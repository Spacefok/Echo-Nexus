#include "procedural/EventGenerator.h"
#include "core/EventSystem.h"

EventGenerator::EventGenerator(ServiceLocator& locator)
    : locator_(locator), timer_(0.0f) {}

void EventGenerator::update(float deltaTime) {
    timer_ += deltaTime;
    if (timer_ >= 10.0f) {
        locator_.get<EventSystem>()->emit("PeriodicEvent");
        timer_ = 0.0f;
    }
}
