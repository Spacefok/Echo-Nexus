#include "procedural/LevelGenerator.h"
#include "data/DataManager.h"
#include "core/GameWorld.h"
#include "entities/Drone.h"
#include "entities/Faction.h"
#include "save/SaveManager.h"
#include <nlohmann/json.hpp>

LevelGenerator::LevelGenerator(ServiceLocator& locator)
    : Locator_(locator) {}

void LevelGenerator::GenerateLevel(int levelId) {
    // record current level in save manager
    Locator_.Get<SaveManager>()->SetCurrentLevel(levelId);
    auto dataManager = Locator_.Get<DataManager>();
    auto data = dataManager->LoadData("level_" + std::to_string(levelId));
    nlohmann::json enemyStats;
    try {
        enemyStats = dataManager->LoadData("enemy_stats");
    } catch (const std::exception&) {
        enemyStats = nlohmann::json::object();
    }
    auto world = Locator_.Get<GameWorld>();

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

        auto drone = std::make_shared<Drone>(id,
                        factions[factionName], health, speed);
        world->AddEntity(drone);
    }
}