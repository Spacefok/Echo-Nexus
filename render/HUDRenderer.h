#ifndef RENDER_HUDRENDERER_H
#define RENDER_HUDRENDERER_H

class ServiceLocator;

// Renders player HUD (health, virus level)
class HUDRenderer {
   public:
    explicit HUDRenderer(ServiceLocator& locator);
    void renderHud();

   private:
    ServiceLocator& locator_;
};
#endif
