#include "data/DataManager.h"
#include <fstream>
#include <stdexcept>

DataManager::DataManager(const std::string& dataPath)
    : DataPath_(dataPath) {}

nlohmann::json DataManager::LoadData(const std::string& fileName) const {
    // Construct full path to JSON file
    std::string fullPath = DataPath_ + "/" + fileName + ".json";
    std::ifstream input(fullPath);
    if (!input.is_open()) {
        throw std::runtime_error("Cannot open data file: " + fullPath);
    }

    nlohmann::json jsonData;
    input >> jsonData;
    return jsonData;  // Return parsed JSON data
}
