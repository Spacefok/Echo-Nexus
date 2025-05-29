#pragma once

#include <string>

// Base class for UI screens
class UIScreen {
public:
    virtual ~UIScreen() = default;
    virtual void Show() = 0;
    virtual void Hide() = 0;
    virtual std::string GetName() const = 0;
};