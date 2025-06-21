# Build save manager library
add_library(saveLib STATIC
    SaveManager.cpp
)

target_include_directories(saveLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/core
)

target_link_libraries(saveLib PUBLIC
    dataLib
    narrativeLib
    entitiesLib
    nlohmann_json::nlohmann_json
)
