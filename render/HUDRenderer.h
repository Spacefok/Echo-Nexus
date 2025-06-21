#pragma once

class ServiceLocator;

// Renders player HUD (health, virus level)
class HUDRenderer {
public:
    explicit HUDRenderer(ServiceLocator& locator);
    void renderHud();

private:
    ServiceLocator& locator_;
};
