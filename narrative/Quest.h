#pragma once

#include <string>

// Represents a quest in the narrative system
class Quest {
public:
    explicit Quest(const std::string& questId);
    std::string GetId() const;
    bool IsCompleted() const;
    void Complete();

private:
    std::string QuestId_;
    bool Completed_;
};
