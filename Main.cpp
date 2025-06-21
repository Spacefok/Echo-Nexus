#include "ServiceLocator.h"
#include "DataManager.h"
#include "ResourceLoader.h"
#include "ConfigLoader.h"
#include "GameWorld.h"
#include "GameLoop.h"
#include "NarrativeManager.h"
#include "LevelGenerator.h"
#include "save/SaveManager.h"
#include "procedural/EventGenerator.h"
#include "procedural/StoryEventRunner.h"
#include "ai/DecisionEngine.h"
#include "ui/UIManager.h"
#include "ui/CombatLogScreen.h"
#include "ui/StatusScreen.h"

int main() {
    // Load configuration
    ConfigLoader configLoader;
    auto gameConfig = configLoader.LoadConfig("config/game_config.json");

    // Setup service locator
    ServiceLocator serviceLocator;

    // Core services
    auto eventSystem = std::make_shared<EventSystem>();
    serviceLocator.Register<EventSystem>(eventSystem);

    // Data and resources
    auto dataManager = std::make_shared<DataManager>(gameConfig.DataPath);
    serviceLocator.Register<DataManager>(dataManager);
    auto resourceLoader = std::make_shared<ResourceLoader>(gameConfig.ResourcePath);
    serviceLocator.Register<ResourceLoader>(resourceLoader);

    // World and narrative
    auto gameWorld = std::make_shared<GameWorld>();
    serviceLocator.Register<GameWorld>(gameWorld);
    auto narrativeManager = std::make_shared<NarrativeManager>(serviceLocator);
    serviceLocator.Register<NarrativeManager>(narrativeManager);
    narrativeManager->LoadFragments("memory_fragments");
    narrativeManager->StartStory(gameConfig.StoryStartPoint);

    // Save manager
    auto saveManager = std::make_shared<SaveManager>("saves/savegame.json", serviceLocator);
    serviceLocator.Register<SaveManager>(saveManager);
    saveManager->Load();

    // Level generation
    LevelGenerator levelGenerator(serviceLocator);
    int startLevel = saveManager->GetCurrentLevel();
    if (startLevel == 0) {
        startLevel = gameConfig.StartLevel;
    }
    levelGenerator.GenerateLevel(startLevel);

    // AI engine
    auto decisionEngine = std::make_shared<DecisionEngine>(serviceLocator);
    serviceLocator.Register<DecisionEngine>(decisionEngine);

    // UI Manager and Combat Log
    auto uiManager = std::make_shared<UIManager>(serviceLocator);
    serviceLocator.Register<UIManager>(uiManager);
    auto combatLog = std::make_shared<CombatLogScreen>();
    uiManager->RegisterScreen(combatLog);
    serviceLocator.Register<CombatLogScreen>(combatLog);

    // Экран статуса игрока
    auto statusScreen = std::make_shared<StatusScreen>(serviceLocator);
    uiManager->RegisterScreen(statusScreen);
    serviceLocator.Register<StatusScreen>(statusScreen);

    // Procedural generators
    auto eventGenerator = std::make_shared<EventGenerator>(serviceLocator);
    serviceLocator.Register<EventGenerator>(eventGenerator);
    auto storyRunner = std::make_shared<StoryEventRunner>(serviceLocator);
    serviceLocator.Register<StoryEventRunner>(storyRunner);
    storyRunner->Initialize();

    // Main loop
    GameLoop gameLoop(serviceLocator);
    // Run until exit condition
    gameLoop.Run();

    // Auto-save on exit
    saveManager->Save();
    return 0;
}
