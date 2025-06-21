# ServiceLocator unit tests
add_executable(ServiceLocatorTest
    ServiceLocatorTest.cpp
)

target_include_directories(ServiceLocatorTest PRIVATE
    ${CMAKE_SOURCE_DIR}/core
)

enable_testing()
add_test(NAME ServiceLocatorTest COMMAND ServiceLocatorTest)

add_executable(SaveManagerTest
    SaveManagerTest.cpp
)
target_include_directories(SaveManagerTest PRIVATE
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/entities
    ${CMAKE_SOURCE_DIR}/data
    ${CMAKE_SOURCE_DIR}/narrative
    ${CMAKE_SOURCE_DIR}/save
)
target_link_libraries(SaveManagerTest PRIVATE
    coreLib
    entitiesLib
    dataLib
    narrativeLib
    saveLib
    nlohmann_json::nlohmann_json
)
target_compile_definitions(SaveManagerTest PRIVATE DATA_DIR="${CMAKE_SOURCE_DIR}/assets")
add_test(NAME SaveManagerTest COMMAND SaveManagerTest)
