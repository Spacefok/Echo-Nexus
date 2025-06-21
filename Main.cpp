#include "ConfigLoader.h"
#include "DataManager.h"
#include "GameLoop.h"
#include "GameWorld.h"
#include "LevelGenerator.h"
#include "NarrativeManager.h"
#include "ResourceLoader.h"
#include "ServiceLocator.h"
#include "ai/DecisionEngine.h"
#include "entities/CloneBody.h"
#include "entities/Player.h"
#include "procedural/EventGenerator.h"
#include "procedural/StoryEventRunner.h"
#include "save/SaveManager.h"
#include "ui/CombatLogScreen.h"
#include "ui/StatusScreen.h"
#include "ui/UIManager.h"

int main() {
    // Load configuration
    ConfigLoader configLoader;
    auto gameConfig = configLoader.LoadConfig("assets/game_config.json");

    // Setup service locator
    ServiceLocator serviceLocator;

    // Core services
    auto eventSystem = std::make_shared<EventSystem>();
    serviceLocator.registerService<EventSystem>(eventSystem);

    // Data and resources
    auto dataManager = std::make_shared<DataManager>(gameConfig.DataPath);
    serviceLocator.registerService<DataManager>(dataManager);
    auto resourceLoader = std::make_shared<ResourceLoader>(gameConfig.ResourcePath);
    serviceLocator.registerService<ResourceLoader>(resourceLoader);

    // World and narrative
    auto gameWorld = std::make_shared<GameWorld>();
    serviceLocator.registerService<GameWorld>(gameWorld);
    auto narrativeManager = std::make_shared<NarrativeManager>(serviceLocator);
    serviceLocator.registerService<NarrativeManager>(narrativeManager);
    narrativeManager->loadFragments("memory_fragments");
    narrativeManager->startStory(gameConfig.StoryStartPoint);

    // Player setup
    auto playerData = dataManager->loadData("player_stats");
    auto playerBody = std::make_shared<CloneBody>(playerData["maxHealth"].get<int>(),
                                                  playerData["virusRate"].get<float>(),
                                                  playerData["virusCarryover"].get<float>());
    auto player = std::make_shared<Player>(1, playerBody);
    player->setCombatStats(playerData["baseDamage"].get<float>(),
                           playerData["weaponMod"].get<float>(),
                           playerData["armorClass"].get<float>());
    serviceLocator.registerService<Player>(player);
    gameWorld->addEntity(player);

    // Save manager
    auto saveManager = std::make_shared<SaveManager>("saves/savegame.json", serviceLocator);
    serviceLocator.registerService<SaveManager>(saveManager);
    saveManager->load();

    // Level generation
    LevelGenerator levelGenerator(serviceLocator);
    int startLevel = saveManager->getCurrentLevel();
    if (startLevel == 0) {
        startLevel = gameConfig.StartLevel;
    }
    levelGenerator.generateLevel(startLevel);

    // AI engine
    auto decisionEngine = std::make_shared<DecisionEngine>(serviceLocator);
    serviceLocator.registerService<DecisionEngine>(decisionEngine);

    // UI Manager and Combat Log
    auto uiManager = std::make_shared<UIManager>(serviceLocator);
    serviceLocator.registerService<UIManager>(uiManager);
    auto combatLog = std::make_shared<CombatLogScreen>();
    uiManager->registerScreen(combatLog);
    serviceLocator.registerService<CombatLogScreen>(combatLog);

    auto statusScreen = std::make_shared<StatusScreen>(serviceLocator);
    uiManager->registerScreen(statusScreen);
    serviceLocator.registerService<StatusScreen>(statusScreen);

    // Procedural generators
    auto eventGenerator = std::make_shared<EventGenerator>(serviceLocator);
    serviceLocator.registerService<EventGenerator>(eventGenerator);
    auto storyRunner = std::make_shared<StoryEventRunner>(serviceLocator);
    serviceLocator.registerService<StoryEventRunner>(storyRunner);
    storyRunner->initialize();

    // Main loop
    GameLoop gameLoop(serviceLocator);
    // Run until exit condition
    gameLoop.run();

    // Auto-save on exit
    saveManager->save();
    return 0;
}
