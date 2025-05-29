#pragma once

#include <cstddef>

// Базовый класс для всех игровых объектов
class Entity {
protected:
    explicit Entity(std::size_t id);

public:
    virtual ~Entity() = default;

    // Уникальный идентификатор сущности
    std::size_t GetId() const;

    // Обновление сущности (вызывается каждый тик)
    virtual void Update(float deltaTime) = 0;

private:
    std::size_t Id_;  // Хранит ID
};