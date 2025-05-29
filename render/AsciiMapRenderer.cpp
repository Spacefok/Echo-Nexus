#include "render/AsciiMapRenderer.h"
#include "entities/Entity.h"
#include <iostream>
#include <vector>
#include <string>

AsciiMapRenderer::AsciiMapRenderer(ServiceLocator& locator)
    : Locator_(locator), MapWidth_(80), MapHeight_(24) {}

void AsciiMapRenderer::RenderMap(const std::vector<std::shared_ptr<Entity>>& entities) {
    std::vector<std::string> grid(MapHeight_, std::string(MapWidth_, '.'));
    for (auto& e : entities) {
        auto id = e->GetId();
        int x = static_cast<int>(id % MapWidth_);
        int y = static_cast<int>((id / MapWidth_) % MapHeight_);
        char symbol = (id == 1 ? '@' : 'D');
        grid[y][x] = symbol;
    }
    for (auto& row : grid) {
        std::cout << row << '\n';
    }
}
