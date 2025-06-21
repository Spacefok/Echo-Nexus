# Собираем статическую библиотеку для управления экранами и вводом
add_library(uiLib STATIC
    UIManager.cpp
    UIScreen.cpp
    CombatLogScreen.cpp
    StatusScreen.cpp
)

# Зависимости: UI использует подсистемы отрисовки и ядра игры
target_link_libraries(uiLib PUBLIC
    renderLib
    coreLib
)

# Разрешаем подключать заголовки UI из проекта и модуля
target_include_directories(uiLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
)
