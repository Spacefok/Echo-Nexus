#pragma once

#include <string>
#include "ServiceLocator.h"

// Generates levels by spawning entities based on data definitions
class LevelGenerator {
public:
    explicit LevelGenerator(ServiceLocator& locator);

    // Generate level with given ID or index
    void generateLevel(int levelId);

private:
    ServiceLocator& locator_;
};
