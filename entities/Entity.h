#pragma once

#include <cstddef>

// Базовый класс для всех игровых объектов
class Entity {
protected:
    explicit Entity(std::size_t id);

public:
    virtual ~Entity() = default;

    // Уникальный идентификатор сущности
    std::size_t getId() const;

    // Обновление сущности (вызывается каждый тик)
    virtual void update(float deltaTime) = 0;

private:
    std::size_t id_;
};
