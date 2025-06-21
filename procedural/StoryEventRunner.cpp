#include "procedural/StoryEventRunner.h"

#include <iostream>

#include "core/EventSystem.h"
#include "narrative/NarrativeManager.h"

StoryEventRunner::StoryEventRunner(ServiceLocator& locator) : locator_(locator) {}

void StoryEventRunner::initialize() {
    auto events = locator_.get<EventSystem>();
    events->subscribe("PeriodicEvent", [this]() { onPeriodicEvent(); });
    events->subscribe("CubeDefeated", [this]() { onCubeDefeated(); });

    locator_.get<NarrativeManager>()->addQuest("defeat_cube");
}

void StoryEventRunner::onPeriodicEvent() {
    // Unlock a random fragment for demo
    auto narrative = locator_.get<NarrativeManager>();
    narrative->unlockFragment("secret_log");
    std::cout << "StoryEventRunner: secret_log unlocked\n";
}

void StoryEventRunner::onCubeDefeated() {
    auto narrative = locator_.get<NarrativeManager>();
    narrative->unlockFragment("cube_destroyed");
    narrative->completeQuest("defeat_cube");
    std::cout << "StoryEventRunner: cube_destroyed unlocked\n";
}
