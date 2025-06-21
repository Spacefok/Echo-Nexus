# Собираем статическую библиотеку для процедурной генерации
add_library(proceduralLib STATIC
    LevelGenerator.cpp
    EventGenerator.cpp
    StoryEventRunner.cpp
)

# Экспорт заголовков из модуля, корня и ядра проекта
target_include_directories(proceduralLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
)

# Зависимости: процедурная генерация использует сущности, данные и ядро
target_link_libraries(proceduralLib PUBLIC
    entitiesLib
    dataLib
    coreLib
    saveLib
    narrativeLib
)