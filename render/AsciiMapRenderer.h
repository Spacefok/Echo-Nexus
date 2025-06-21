#pragma once

#include <vector>
#include <memory>

class Entity;
class ServiceLocator;

// Renders ASCII map based on entity positions
class AsciiMapRenderer {
public:
    explicit AsciiMapRenderer(ServiceLocator& locator);
    void renderMap(const std::vector<std::shared_ptr<Entity>>& entities);

private:
    ServiceLocator& locator_;
    int mapWidth_;
    int mapHeight_;
};
