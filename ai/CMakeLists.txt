add_library(aiLib STATIC
    EnemyAIController.cpp
    DroneBehavior.cpp
    DecisionEngine.cpp
)

target_link_libraries(aiLib PUBLIC
    entitiesLib
    proceduralLib
    coreLib
)

target_include_directories(aiLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
)
