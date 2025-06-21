#pragma once
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <stdexcept>

// Simple service locator for managing shared services
class ServiceLocator {
public:
    template<typename T>
    void Register(std::shared_ptr<T> service) {
        auto type = std::type_index(typeid(T));
        if (Services_.count(type)) {
            throw std::runtime_error("Service already registered");
        }
        Services_[type] = service;
    }

    template<typename T>
    std::shared_ptr<T> Get() {
        auto type = std::type_index(typeid(T));
        auto it = Services_.find(type);
        if (it == Services_.end()) {
            throw std::runtime_error("Service not found");
        }
        return std::static_pointer_cast<T>(it->second);
    }

private:
    std::unordered_map<std::type_index, std::shared_ptr<void>> Services_;
};
