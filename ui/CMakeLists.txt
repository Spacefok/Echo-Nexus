add_library(uiLib STATIC
    UIManager.cpp
    UIScreen.cpp
    CombatLogScreen.cpp
    StatusScreen.cpp
)

target_link_libraries(uiLib PUBLIC
    renderLib
    coreLib
)

target_include_directories(uiLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
)
