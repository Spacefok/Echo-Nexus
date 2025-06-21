#pragma once
#include "core/ServiceLocator.h"

// Main game loop
class GameLoop {
public:
    explicit GameLoop(ServiceLocator& locator);
    void run();

private:
    ServiceLocator& locator_;
};
