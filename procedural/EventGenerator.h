#pragma once

#include "ServiceLocator.h"

// Generates timed or random events in the game world
class EventGenerator {
public:
    explicit EventGenerator(ServiceLocator& locator);
    
    // Called each tick to possibly generate events
    void Update(float deltaTime);

private:
    ServiceLocator& Locator_;
    float Timer_;
};