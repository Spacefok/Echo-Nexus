#include "procedural/LevelGenerator.h"
#include "data/DataManager.h"
#include "core/GameWorld.h"
#include "entities/Drone.h"
#include "entities/Faction.h"
#include <nlohmann/json.hpp>

LevelGenerator::LevelGenerator(ServiceLocator& locator)
    : Locator_(locator) {}

void LevelGenerator::GenerateLevel(int levelId) {
    auto data = Locator_.Get<DataManager>()->LoadData("level_" + std::to_string(levelId));
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
        int health = d.at("health").get<int>();
        float speed = d.at("speed").get<float>();

        auto drone = std::make_shared<Drone>(id,
                        factions[factionName], health, speed);
        world->AddEntity(drone);
    }
}