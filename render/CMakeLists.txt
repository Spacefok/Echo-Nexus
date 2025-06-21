
add_library(renderLib STATIC
    RenderEngine.cpp
    AsciiMapRenderer.cpp
    HUDRenderer.cpp
)

target_link_libraries(renderLib PUBLIC
    coreLib
)

target_include_directories(renderLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
)
