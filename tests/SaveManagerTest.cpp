#include "core/ServiceLocator.h"
#include "core/EventSystem.h"
#include "core/GameWorld.h"
#include "entities/Player.h"
#include "entities/CloneBody.h"
#include "data/DataManager.h"
#include "narrative/NarrativeManager.h"
#include "narrative/MemoryFragment.h"
#include "save/SaveManager.h"
#include <cassert>
#include <cstdio>

int main() {
    ServiceLocator locator;
    auto events = std::make_shared<EventSystem>();
    locator.Register<EventSystem>(events);
    auto world = std::make_shared<GameWorld>();
    locator.Register<GameWorld>(world);
    auto data = std::make_shared<DataManager>(DATA_DIR);
    locator.Register<DataManager>(data);
    auto player = std::make_shared<Player>(1, std::make_shared<CloneBody>(100, 0.f, 0.f));
    locator.Register<Player>(player);
    auto narrative = std::make_shared<NarrativeManager>(locator);
    locator.Register<NarrativeManager>(narrative);
    narrative->LoadFragments("memory_fragments");

    auto saver = std::make_shared<SaveManager>("test_save.json", locator);
    locator.Register<SaveManager>(saver);
    saver->SetCurrentLevel(2);
    player->ApplyDamage(20); // 80 HP
    player->AddVirus(15.0f);
    narrative->UnlockFragment("secret_log");
    saver->Save();

    // create new environment to load
    ServiceLocator locator2;
    auto events2 = std::make_shared<EventSystem>();
    locator2.Register<EventSystem>(events2);
    auto world2 = std::make_shared<GameWorld>();
    locator2.Register<GameWorld>(world2);
    auto data2 = std::make_shared<DataManager>(DATA_DIR);
    locator2.Register<DataManager>(data2);
    auto player2 = std::make_shared<Player>(1, std::make_shared<CloneBody>(100, 0.f, 0.f));
    locator2.Register<Player>(player2);
    auto narrative2 = std::make_shared<NarrativeManager>(locator2);
    locator2.Register<NarrativeManager>(narrative2);
    narrative2->LoadFragments("memory_fragments");

    auto saverPtr = std::make_shared<SaveManager>("test_save.json", locator2);
    locator2.Register<SaveManager>(saverPtr);
    saverPtr->Load();

    assert(saverPtr->GetCurrentLevel() == 2);
    assert(player2->GetHealth() == 80);
    assert(static_cast<int>(player2->GetVirusLevel()) == 15);
    auto unlocked = narrative2->GetUnlockedFragments();
    bool found = false;
    for (auto& f : unlocked) {
        if (f->GetId() == "secret_log") { found = true; break; }
    }
    assert(found && "Fragment not loaded");

    std::remove("test_save.json");
    return 0;
}
