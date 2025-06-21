#pragma once
#include "ServiceLocator.h"

// Main game loop
class GameLoop {
public:
    explicit GameLoop(ServiceLocator& locator);
    void Run();

private:
    ServiceLocator& Locator_;
};
