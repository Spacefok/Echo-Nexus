# Build config loader library
add_library(configLib STATIC
    ConfigLoader.cpp
)

target_include_directories(configLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(configLib PUBLIC
    nlohmann_json::nlohmann_json
)   