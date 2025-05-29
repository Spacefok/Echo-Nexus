#pragma once

#include <string>
#include <nlohmann/json.hpp>

// DataManager loads and provides access to game data files
class DataManager {
public:
    // Constructor takes base path to data directory
    explicit DataManager(const std::string& dataPath);

    // Load arbitrary JSON data by filename (without extension)
    nlohmann::json LoadData(const std::string& fileName) const;

private:
    std::string DataPath_;  // Base directory for data files
};