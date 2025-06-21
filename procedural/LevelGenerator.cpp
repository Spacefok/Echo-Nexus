#include "procedural/LevelGenerator.h"
#include "data/DataManager.h"
#include "core/GameWorld.h"
#include "entities/Drone.h"
#include "entities/Faction.h"
#include <nlohmann/json.hpp>

LevelGenerator::LevelGenerator(ServiceLocator& locator)
    : locator_(locator) {}

<<<<<<< Updated upstream
void LevelGenerator::GenerateLevel(int levelId) {
    auto dataManager = Locator_.Get<DataManager>();
    auto data = dataManager->LoadData("level_" + std::to_string(levelId));
=======
void LevelGenerator::generateLevel(int levelId) {
    // record current level in save manager
    locator_.get<SaveManager>()->setCurrentLevel(levelId);
    auto dataManager = locator_.get<DataManager>();
    auto data = dataManager->loadData("level_" + std::to_string(levelId));
>>>>>>> Stashed changes
    nlohmann::json enemyStats;
    try {
        enemyStats = dataManager->loadData("enemy_stats");
    } catch (const std::exception&) {
        enemyStats = nlohmann::json::object();
    }
    auto world = locator_.get<GameWorld>();

    // Create factions from data
    std::unordered_map<std::string, std::shared_ptr<Faction>> factions;
    for (auto& f : data["factions"]) {
        auto name = f.at("name").get<std::string>();
        factions[name] = std::make_shared<Faction>(name);
    }

    // Spawn drones
    for (auto& d : data["drones"]) {
        int id = d.at("id").get<int>();
        std::string factionName = d.at("faction").get<std::string>();
        int health = d.contains("health") ? d.at("health").get<int>()
                   : enemyStats[d.at("type").get<std::string>()].value("health", 10);
        float speed = d.contains("speed") ? d.at("speed").get<float>()
                       : enemyStats[d.at("type").get<std::string>()].value("speed", 1.0f);
        float damage = enemyStats[d.at("type").get<std::string>()].value("damage", 5.0f);
        float armor = enemyStats[d.at("type").get<std::string>()].value("armorClass", 0.0f);

        auto drone = std::make_shared<Drone>(id,
                        factions[factionName], d.at("type").get<std::string>(),
                        health, speed, damage, armor);
        world->addEntity(drone);
    }
<<<<<<< Updated upstream
}
=======

    if (levelId == 3) {
        locator_.get<NarrativeManager>()->unlockFragment("cube_awakens");
    }
}
>>>>>>> Stashed changes
