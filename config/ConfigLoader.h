#ifndef CONFIG_CONFIGLOADER_H
#define CONFIG_CONFIGLOADER_H

#include <nlohmann/json.hpp>
#include <string>

// Structure to hold game configuration parameters
typedef struct GameConfig {
    std::string DataPath;         // Path to game data directory
    std::string ResourcePath;     // Path to resource files (assets)
    int StartLevel;               // Initial level index or ID
    std::string StoryStartPoint;  // Narrative entry point identifier
} GameConfig;

class ConfigLoader {
   public:
    // Loads JSON config from file and returns GameConfig
    GameConfig LoadConfig(const std::string& filePath);
};
#endif
