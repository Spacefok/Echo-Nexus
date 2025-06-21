add_library(dataLib STATIC
    DataManager.cpp
    ResourceLoader.cpp
    DialogueDatabase.cpp
)

target_include_directories(dataLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/config
)

target_link_libraries(dataLib PUBLIC
    configLib
    nlohmann_json::nlohmann_json
)
