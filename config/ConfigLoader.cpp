#include "config/ConfigLoader.h"

#include <fstream>
#include <stdexcept>

GameConfig ConfigLoader::LoadConfig(const std::string& filePath) {
    std::ifstream configStream(filePath);
    if (!configStream.is_open()) {
        throw std::runtime_error("Cannot open config file: " + filePath);
    }

    nlohmann::json jsonConfig;
    configStream >> jsonConfig;

    GameConfig config;
    // Map JSON fields to GameConfig members
    config.DataPath = jsonConfig.at("dataPath").get<std::string>();
    config.ResourcePath = jsonConfig.at("resourcePath").get<std::string>();
    config.StartLevel = jsonConfig.at("startLevel").get<int>();
    config.StoryStartPoint = jsonConfig.at("storyStartPoint").get<std::string>();

    return config;
}
