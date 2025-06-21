#include "procedural/StoryEventRunner.h"
#include "narrative/NarrativeManager.h"
#include "core/EventSystem.h"
#include <iostream>

StoryEventRunner::StoryEventRunner(ServiceLocator& locator)
    : Locator_(locator) {}

void StoryEventRunner::Initialize() {
    auto events = Locator_.Get<EventSystem>();
    events->Subscribe("PeriodicEvent", [this]() { OnPeriodicEvent(); });
    events->Subscribe("CubeDefeated", [this]() { OnCubeDefeated(); });

    Locator_.Get<NarrativeManager>()->AddQuest("defeat_cube");
}

void StoryEventRunner::OnPeriodicEvent() {
    // Unlock a random fragment for demo
    auto narrative = Locator_.Get<NarrativeManager>();
    narrative->UnlockFragment("secret_log");
    std::cout << "StoryEventRunner: secret_log unlocked\n";
}

void StoryEventRunner::OnCubeDefeated() {
    auto narrative = Locator_.Get<NarrativeManager>();
    narrative->UnlockFragment("cube_destroyed");
    narrative->CompleteQuest("defeat_cube");
    std::cout << "StoryEventRunner: cube_destroyed unlocked\n";
}
