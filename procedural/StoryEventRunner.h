#pragma once

#include <string>
#include "ServiceLocator.h"

// Runs narrative story events based on triggers
class StoryEventRunner {
public:
    explicit StoryEventRunner(ServiceLocator& locator);

    // Start listening to events and trigger story
    void initialize();

private:
    ServiceLocator& locator_;

    // Handle a periodic event
<<<<<<< Updated upstream
    void OnPeriodicEvent();
};
=======
    void onPeriodicEvent();

    void onCubeDefeated();
};
>>>>>>> Stashed changes
