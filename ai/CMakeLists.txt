# Create static library for AI behaviors
add_library(aiLib STATIC
    EnemyAIController.cpp
    DroneBehavior.cpp
    DecisionEngine.cpp
)

# Зависимости: AI использует сущности, процедурную логику и ядро
target_link_libraries(aiLib PUBLIC
    entitiesLib
    proceduralLib
    coreLib
)

# Экспорт заголовков из модуля и корня проекта
target_include_directories(aiLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
)