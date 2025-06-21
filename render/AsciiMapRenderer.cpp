#include "render/AsciiMapRenderer.h"

#include <iostream>
#include <string>
#include <vector>

#include "entities/Entity.h"

AsciiMapRenderer::AsciiMapRenderer(ServiceLocator& locator)
    : locator_(locator), mapWidth_(80), mapHeight_(24) {}

void AsciiMapRenderer::renderMap(const std::vector<std::shared_ptr<Entity>>& entities) {
    std::vector<std::string> grid(mapHeight_, std::string(mapWidth_, '.'));
    for (auto& e : entities) {
        auto id = e->getId();
        int x = static_cast<int>(id % mapWidth_);
        int y = static_cast<int>((id / mapWidth_) % mapHeight_);
        char symbol = (id == 1 ? '@' : 'D');
        grid[y][x] = symbol;
    }
    for (auto& row : grid) {
        std::cout << row << '\n';
    }
}
