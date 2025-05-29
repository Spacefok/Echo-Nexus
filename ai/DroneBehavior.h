#pragma once

#include <memory>

class ServiceLocator;
class Drone;

// Encapsulates behavior logic for drone entities
class DroneBehavior {
public:
    explicit DroneBehavior(ServiceLocator& locator);

    // Execute behavior for a given drone each tick
    void Execute(std::shared_ptr<Drone> drone, float deltaTime);

private:
    ServiceLocator& Locator_;
};