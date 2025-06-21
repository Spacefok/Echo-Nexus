#include "ServiceLocator.h"
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
    locator.registerService<EventSystem>(events);
    auto world = std::make_shared<GameWorld>();
    locator.registerService<GameWorld>(world);
    auto data = std::make_shared<DataManager>(DATA_DIR);
    locator.registerService<DataManager>(data);
    auto player = std::make_shared<Player>(1, std::make_shared<CloneBody>(100, 0.f, 0.f));
    locator.registerService<Player>(player);
    auto narrative = std::make_shared<NarrativeManager>(locator);
    locator.registerService<NarrativeManager>(narrative);
    narrative->loadFragments("memory_fragments");

    auto saver = std::make_shared<SaveManager>("test_save.json", locator);
    locator.registerService<SaveManager>(saver);
    saver->setCurrentLevel(2);
    player->applyDamage(20); // 80 HP
    player->addVirus(15.0f);
    narrative->unlockFragment("secret_log");
    saver->save();

    // create new environment to load
    ServiceLocator locator2;
    auto events2 = std::make_shared<EventSystem>();
    locator2.registerService<EventSystem>(events2);
    auto world2 = std::make_shared<GameWorld>();
    locator2.registerService<GameWorld>(world2);
    auto data2 = std::make_shared<DataManager>(DATA_DIR);
    locator2.registerService<DataManager>(data2);
    auto player2 = std::make_shared<Player>(1, std::make_shared<CloneBody>(100, 0.f, 0.f));
    locator2.registerService<Player>(player2);
    auto narrative2 = std::make_shared<NarrativeManager>(locator2);
    locator2.registerService<NarrativeManager>(narrative2);
    narrative2->loadFragments("memory_fragments");

    auto saverPtr = std::make_shared<SaveManager>("test_save.json", locator2);
    locator2.registerService<SaveManager>(saverPtr);
    saverPtr->load();

    assert(saverPtr->getCurrentLevel() == 2);
    assert(player2->getHealth() == 80);
    assert(static_cast<int>(player2->getVirusLevel()) == 15);
    auto unlocked = narrative2->getUnlockedFragments();
    bool found = false;
    for (auto& f : unlocked) {
        if (f->getId() == "secret_log") { found = true; break; }
    }
    assert(found && "Fragment not loaded");

    std::remove("test_save.json");
    return 0;
}
