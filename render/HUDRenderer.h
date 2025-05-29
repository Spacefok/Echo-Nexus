#pragma once

class ServiceLocator;

// Renders player HUD (health, virus level)
class HUDRenderer {
public:
    explicit HUDRenderer(ServiceLocator& locator);
    void RenderHud();

private:
    ServiceLocator& Locator_;
};