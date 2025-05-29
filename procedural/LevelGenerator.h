#pragma once

#include <string>
#include "ServiceLocator.h"

// Generates levels by spawning entities based on data definitions
class LevelGenerator {
public:
    explicit LevelGenerator(ServiceLocator& locator);

    // Generate level with given ID or index
    void GenerateLevel(int levelId);

private:
    ServiceLocator& Locator_;
};