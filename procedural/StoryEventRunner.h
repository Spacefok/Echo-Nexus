#ifndef PROCEDURAL_STORYEVENTRUNNER_H
#define PROCEDURAL_STORYEVENTRUNNER_H

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
    void onPeriodicEvent();

    void onCubeDefeated();
};
#endif
