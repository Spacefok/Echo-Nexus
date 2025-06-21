#ifndef CORE_SERVICELOCATOR_H
#define CORE_SERVICELOCATOR_H
#include <memory>
#include <stdexcept>
#include <typeindex>
#include <unordered_map>

// Simple service locator for managing shared services
class ServiceLocator {
   public:
    template <typename T>
    void registerService(std::shared_ptr<T> service) {
        auto type = std::type_index(typeid(T));
        if (services_.count(type)) {
            throw std::runtime_error("Service already registered");
        }
        services_[type] = service;
    }

    template <typename T>
    std::shared_ptr<T> get() {
        auto type = std::type_index(typeid(T));
        auto it = services_.find(type);
        if (it == services_.end()) {
            throw std::runtime_error("Service not found");
        }
        return std::static_pointer_cast<T>(it->second);
    }

   private:
    std::unordered_map<std::type_index, std::shared_ptr<void>> services_;
};
#endif
