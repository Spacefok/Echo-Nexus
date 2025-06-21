#ifndef RENDER_ASCIIMAPRENDERER_H
#define RENDER_ASCIIMAPRENDERER_H

#include <memory>
#include <vector>

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
#endif
