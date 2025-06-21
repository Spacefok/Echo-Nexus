add_library(coreLib STATIC
    GameWorld.cpp
    EventSystem.cpp
    GameLoop.cpp
)

target_include_directories(coreLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)
