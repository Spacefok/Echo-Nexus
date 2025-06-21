#include "data/DataManager.h"
#include <fstream>
#include <stdexcept>

DataManager::DataManager(const std::string& dataPath)
    : dataPath_(dataPath) {}

nlohmann::json DataManager::loadData(const std::string& fileName) const {
    // Construct full path to JSON file
    std::string fullPath = dataPath_ + "/" + fileName + ".json";
    std::ifstream input(fullPath);
    if (!input.is_open()) {
        throw std::runtime_error("Cannot open data file: " + fullPath);
    }

    nlohmann::json jsonData;
    input >> jsonData;
    return jsonData;  // Return parsed JSON data
}
