add_library(proceduralLib STATIC
    LevelGenerator.cpp
    EventGenerator.cpp
    StoryEventRunner.cpp
)

target_include_directories(proceduralLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
)

target_link_libraries(proceduralLib PUBLIC
    entitiesLib
    dataLib
    coreLib
    saveLib
    narrativeLib
)
