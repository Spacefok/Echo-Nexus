#ifndef NARRATIVE_QUEST_H
#define NARRATIVE_QUEST_H

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
#endif
