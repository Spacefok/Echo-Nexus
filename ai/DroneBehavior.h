#ifndef AI_DRONEBEHAVIOR_H
#define AI_DRONEBEHAVIOR_H

#include <memory>

class ServiceLocator;
class Drone;

// Encapsulates behavior logic for drone entities
class DroneBehavior {
   public:
    explicit DroneBehavior(ServiceLocator& locator);

    // Execute behavior for a given drone each tick
    void execute(std::shared_ptr<Drone> drone, float deltaTime);

   private:
    ServiceLocator& locator_;
};
#endif
