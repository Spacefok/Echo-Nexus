# Create a static library for all game world entities
add_library(entitiesLib STATIC
    Entity.cpp          # <--- добавили здесь
    Player.cpp
    CloneBody.cpp
    Trait.cpp
    Faction.cpp
    Drone.cpp
)

# Allow other modules to include headers from project root and this directory
target_include_directories(entitiesLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)