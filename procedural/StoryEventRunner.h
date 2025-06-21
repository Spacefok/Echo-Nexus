#pragma once

#include <string>
#include "ServiceLocator.h"

// Runs narrative story events based on triggers
class StoryEventRunner {
public:
    explicit StoryEventRunner(ServiceLocator& locator);

    // Start listening to events and trigger story
    void Initialize();

private:
    ServiceLocator& Locator_;

    // Handle a periodic event
    void OnPeriodicEvent();

    void OnCubeDefeated();
};