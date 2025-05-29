#pragma once

#include <vector>
#include <memory>

class Entity;
class ServiceLocator;

// Renders ASCII map based on entity positions
class AsciiMapRenderer {
public:
    explicit AsciiMapRenderer(ServiceLocator& locator);
    void RenderMap(const std::vector<std::shared_ptr<Entity>>& entities);

private:
    ServiceLocator& Locator_;
    int MapWidth_;
    int MapHeight_;
};