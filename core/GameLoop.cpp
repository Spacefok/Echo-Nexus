#include "core/GameLoop.h"
#include "entities/Player.h"
#include "entities/Drone.h"
#include "render/RenderEngine.h"
#include "ai/DecisionEngine.h"
#include "ui/UIManager.h"
#include "ui/CombatLogScreen.h"
#include "ui/StatusScreen.h"
#include "core/GameWorld.h"
#include "core/EventSystem.h"
#include <iostream>

GameLoop::GameLoop(ServiceLocator& locator)
    : Locator_(locator) {}

void GameLoop::Run() {
    auto world = Locator_.Get<GameWorld>();
    auto player = Locator_.Get<Player>();
    auto decision = Locator_.Get<DecisionEngine>();
    auto renderer = Locator_.Get<RenderEngine>();
    auto ui = Locator_.Get<UIManager>();
    auto log = Locator_.Get<CombatLogScreen>();
    auto status = Locator_.Get<StatusScreen>();
    ui->ShowScreen("CombatLog");

    bool running = true;
    bool cubeEventSent = false;
    while (running) {
        bool endTurn = false;
        while (!endTurn) {
            status->Show();
            std::cout << "1) Attack  2) Heal  3) End Turn\n> ";
            int choice;
            if (!(std::cin >> choice)) {
                return; // input error
            }
            switch (choice) {
                case 1: {
                    // attack first living drone
                    bool hit = false;
                    for (auto& e : world->GetEntities()) {
                        auto drone = std::dynamic_pointer_cast<Drone>(e);
                        if (drone && drone->GetHealth() > 0) {
                            drone->SetHealth(drone->GetHealth() - 5);
                            log->AddEntry("Player hits Drone " + std::to_string(drone->GetId()) + " for 5 damage");
                            if (drone->GetHealth() <= 0) {
                                log->AddEntry("Drone " + std::to_string(drone->GetId()) + " destroyed");
                            }
                            hit = true;
                            break;
                        }
                    }
                    if (!hit) {
                        log->AddEntry("No target available");
                    }
                    break;
                }
                case 2:
                    player->Heal(5);
                    log->AddEntry("Player heals 5 HP");
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
        decision->Update(1.0f);
        world->Update(0.0f);

        // Render and UI
        renderer->Render();
        ui->Update(0.0f);

        // Check end conditions
        if (player->GetHealth() <= 0) {
            std::cout << "You died!\n";
            running = false;
        }
        bool anyDroneAlive = false;
        for (auto& e : world->GetEntities()) {
            auto drone = std::dynamic_pointer_cast<Drone>(e);
            if (drone) {
                if (drone->GetHealth() > 0) {
                    anyDroneAlive = true;
                } else if (drone->GetId() == 99 && !cubeEventSent) {
                    Locator_.Get<EventSystem>()->Emit("CubeDefeated");
                    cubeEventSent = true;
                }
            }
            if (anyDroneAlive)
                break;
        }
        if (!anyDroneAlive) {
            std::cout << "All enemies defeated!\n";
            running = false;
        }
    }
}
