#ifndef PROCEDURAL_EVENTGENERATOR_H
#define PROCEDURAL_EVENTGENERATOR_H

#include "ServiceLocator.h"

// Generates timed or random events in the game world
class EventGenerator {
   public:
    explicit EventGenerator(ServiceLocator& locator);

    // Called each tick to possibly generate events
    void update(float deltaTime);

   private:
    ServiceLocator& locator_;
    float timer_;
};
#endif
