#include "core/GameLoop.h"
#include "entities/Player.h"
#include "entities/Drone.h"
#include "render/RenderEngine.h"
#include "ai/DecisionEngine.h"
#include "ui/UIManager.h"
#include "ui/CombatLogScreen.h"
#include "core/GameWorld.h"
#include <iostream>

GameLoop::GameLoop(ServiceLocator& locator)
    : locator_(locator) {}

<<<<<<< Updated upstream
void GameLoop::Run() {
    auto world = Locator_.Get<GameWorld>();
    auto player = Locator_.Get<Player>();
    auto decision = Locator_.Get<DecisionEngine>();
    auto renderer = Locator_.Get<RenderEngine>();
    auto ui = Locator_.Get<UIManager>();
    auto log = Locator_.Get<CombatLogScreen>();
=======
void GameLoop::run() {
    auto world = locator_.get<GameWorld>();
    auto player = locator_.get<Player>();
    auto decision = locator_.get<DecisionEngine>();
    auto renderer = locator_.get<RenderEngine>();
    auto ui = locator_.get<UIManager>();
    auto log = locator_.get<CombatLogScreen>();
    auto status = locator_.get<StatusScreen>();
    ui->showScreen("CombatLog");
>>>>>>> Stashed changes

    bool running = true;
    while (running) {
        bool endTurn = false;
        while (!endTurn) {
<<<<<<< Updated upstream
=======
            status->show();
>>>>>>> Stashed changes
            std::cout << "1) Attack  2) Heal  3) End Turn\n> ";
            int choice;
            if (!(std::cin >> choice)) {
                return; // input error
            }
            switch (choice) {
                case 1: {
                    // attack first living drone
                    bool hit = false;
                    for (auto& e : world->getEntities()) {
                        auto drone = std::dynamic_pointer_cast<Drone>(e);
                        if (drone && drone->getHealth() > 0) {
                            int damage = static_cast<int>(player->getBaseDamage() *
                                (1 + player->getWeaponMod() - drone->getArmorClass()));
                            drone->setHealth(drone->getHealth() - damage);
                            log->addEntry("Player hits Drone " + std::to_string(drone->getId()) +
                                " for " + std::to_string(damage) + " damage");
                            if (drone->getHealth() <= 0) {
                                log->addEntry("Drone " + std::to_string(drone->getId()) + " destroyed");
                            }
                            hit = true;
                            break;
                        }
                    }
                    if (!hit) {
                        log->addEntry("No target available");
                    }
                    break;
                }
                case 2:
                    player->heal(5);
                    log->addEntry("Player heals 5 HP");
                    break;
                case 3:
                    endTurn = true;
                    break;
                default:
                    std::cout << "Invalid choice\n";
                    break;
            }
        }

        // Enemy turn
        decision->update(1.0f);
        world->update(0.0f);

        // Render and UI
        renderer->render();
        ui->update(0.0f);

        // Check end conditions
        if (player->getHealth() <= 0) {
            std::cout << "You died! Rebirthing...\n";
            player->rebirth(std::make_shared<CloneBody>(player->getMaxHealth(), 0.5f, 5));
            player->addTrait(std::make_shared<Trait>("Resilient", "Survived death", 1.0f));
        }
        bool anyDroneAlive = false;
        for (auto& e : world->getEntities()) {
            auto drone = std::dynamic_pointer_cast<Drone>(e);
<<<<<<< Updated upstream
            if (drone && drone->GetHealth() > 0) {
                anyDroneAlive = true;
=======
            if (drone) {
                if (drone->getHealth() > 0) {
                    anyDroneAlive = true;
                } else if (drone->getId() == 99 && !cubeEventSent) {
                    locator_.get<EventSystem>()->emit("CubeDefeated");
                    cubeEventSent = true;
                }
            }
            if (anyDroneAlive)
>>>>>>> Stashed changes
                break;
            }
        }
        if (!anyDroneAlive) {
            std::cout << "All enemies defeated!\n";
            running = false;
        }
    }
}
