add_library(narrativeLib STATIC
    NarrativeManager.cpp
    MemoryFragment.cpp
    Quest.cpp
    DialogueManager.cpp
    StoryGraph.cpp
)

target_include_directories(narrativeLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
)

target_link_libraries(narrativeLib PUBLIC
    dataLib
    coreLib
    proceduralLib
)
