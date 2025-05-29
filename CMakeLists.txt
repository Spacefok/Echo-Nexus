cmake_minimum_required(VERSION 3.16)
project(EchoNexus VERSION 0.1.0 LANGUAGES CXX)

# Enable C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for IDEs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Download nlohmann/json via FetchContent if not installed
include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)

# Build options
option(BUILD_TESTS "Build unit tests" ON)

# Add module subdirectories
add_subdirectory(entities)
add_subdirectory(core)
add_subdirectory(ai)
add_subdirectory(render)
add_subdirectory(ui)
add_subdirectory(procedural)
add_subdirectory(config)
add_subdirectory(data)
add_subdirectory(narrative)
add_subdirectory(save)

# Main executable
add_executable(EchoNexusExecutable Main.cpp)

target_link_libraries(EchoNexusExecutable
    PRIVATE
        entitiesLib
        coreLib
        aiLib
        renderLib
        uiLib
        proceduralLib
        dataLib
        narrativeLib
        saveLib
        nlohmann_json::nlohmann_json
)

target_include_directories(EchoNexusExecutable
    PRIVATE
        ${CMAKE_SOURCE_DIR}/entities
        ${CMAKE_SOURCE_DIR}/core
        ${CMAKE_SOURCE_DIR}/ai
        ${CMAKE_SOURCE_DIR}/render
        ${CMAKE_SOURCE_DIR}/ui
        ${CMAKE_SOURCE_DIR}/procedural
        ${CMAKE_SOURCE_DIR}/data
        ${CMAKE_SOURCE_DIR}/narrative
        ${CMAKE_SOURCE_DIR}/save
)

# Unit tests
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
