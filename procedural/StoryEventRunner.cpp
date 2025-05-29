#include "procedural/StoryEventRunner.h"
#include "narrative/NarrativeManager.h"
#include "core/EventSystem.h"
#include <iostream>

StoryEventRunner::StoryEventRunner(ServiceLocator& locator)
    : Locator_(locator) {}

void StoryEventRunner::Initialize() {
    Locator_.Get<EventSystem>()->Subscribe("PeriodicEvent", [this]() {
        OnPeriodicEvent();
    });
}

void StoryEventRunner::OnPeriodicEvent() {
    // Unlock a random fragment for demo
    auto narrative = Locator_.Get<NarrativeManager>();
    narrative->UnlockFragment("secret_log");
    std::cout << "StoryEventRunner: secret_log unlocked\n";
}
