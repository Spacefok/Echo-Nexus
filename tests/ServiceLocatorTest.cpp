#include "ServiceLocator.h"
#include <cassert>
#include <iostream>
#include <memory>

// Dummy service for testing
template<typename T>
struct DummyService {};

int main() {
    ServiceLocator locator;

    // Test registration and retrieval
    auto serviceA = std::make_shared<DummyService<int>>();
    locator.Register<DummyService<int>>(serviceA);
    assert(locator.Get<DummyService<int>>() == serviceA);

    // Test duplicate registration throws
    bool duplicateThrown = false;
    try {
        locator.Register<DummyService<int>>(serviceA);
    } catch (const std::runtime_error& e) {
        duplicateThrown = true;
    }
    assert(duplicateThrown && "Expected exception on duplicate registration");

    // Test retrieval of unregistered service throws
    bool notFoundThrown = false;
    try {
        locator.Get<DummyService<float>>();
    } catch (const std::runtime_error& e) {
        notFoundThrown = true;
    }
    assert(notFoundThrown && "Expected exception on missing service");

    std::cout << "ServiceLocator tests passed." << std::endl;
    return 0;
}
