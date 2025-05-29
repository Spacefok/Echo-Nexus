#include "procedural/EventGenerator.h"
#include "core/EventSystem.h"

EventGenerator::EventGenerator(ServiceLocator& locator)
    : Locator_(locator), Timer_(0.0f) {}

void EventGenerator::Update(float deltaTime) {
    Timer_ += deltaTime;
    if (Timer_ >= 10.0f) {
        Locator_.Get<EventSystem>()->Emit("PeriodicEvent");
        Timer_ = 0.0f;
    }
}