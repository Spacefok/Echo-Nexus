#pragma once

#include <string>

// Represents a quest in the narrative system
class Quest {
public:
    explicit Quest(const std::string& questId);
    std::string getId() const;
    bool isCompleted() const;
    void complete();

private:
    std::string questId_;
    bool completed_;
};
