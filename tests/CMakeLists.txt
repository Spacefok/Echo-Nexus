# ServiceLocator unit tests
add_executable(ServiceLocatorTest
    ServiceLocatorTest.cpp
)

target_include_directories(ServiceLocatorTest PRIVATE
    ${CMAKE_SOURCE_DIR}/core
)

enable_testing()
add_test(NAME ServiceLocatorTest COMMAND ServiceLocatorTest)
