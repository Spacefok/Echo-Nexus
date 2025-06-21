#pragma once

// Manages registration and update of game systems
class SystemManager {
public:
    SystemManager();
    
    // Initialize all systems
    void Initialize();
    
    // Update systems each frame (stub)
    void Update(float deltaTime);
};
