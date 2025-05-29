# Собираем статическую библиотеку для сюжетных элементов игры
add_library(narrativeLib STATIC
    NarrativeManager.cpp
    MemoryFragment.cpp
    Quest.cpp
    DialogueManager.cpp
    StoryGraph.cpp
)

# Экспорт заголовков из модуля и корня проекта
target_include_directories(narrativeLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
)

# Зависимости: сюжетный модуль использует dataLib, coreLib и proceduralLib
target_link_libraries(narrativeLib PUBLIC
    dataLib
    coreLib
    proceduralLib
)