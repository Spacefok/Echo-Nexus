#ifndef CORE_GAMELOOP_H
#define CORE_GAMELOOP_H
#include "core/ServiceLocator.h"

// Main game loop
class GameLoop {
   public:
    explicit GameLoop(ServiceLocator& locator);
    void run();

   private:
    ServiceLocator& locator_;
};
#endif
