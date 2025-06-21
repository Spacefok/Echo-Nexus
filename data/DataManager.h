#ifndef DATA_DATAMANAGER_H
#define DATA_DATAMANAGER_H

#include <nlohmann/json.hpp>
#include <string>

// DataManager loads and provides access to game data files
class DataManager {
   public:
    // Constructor takes base path to data directory
    explicit DataManager(const std::string& dataPath);

    // Load arbitrary JSON data by filename (without extension)
    nlohmann::json loadData(const std::string& fileName) const;

   private:
    std::string dataPath_;
};
#endif
