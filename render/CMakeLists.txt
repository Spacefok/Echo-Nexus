
# Собираем статическую библиотеку для отрисовки ASCII-интерфейса
add_library(renderLib STATIC
    RenderEngine.cpp
    AsciiMapRenderer.cpp
    HUDRenderer.cpp
)

# Зависимости: отрисовка использует ядро игры
target_link_libraries(renderLib PUBLIC
    coreLib
)

# Экспорт заголовков из модуля и корня проекта
target_include_directories(renderLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
)