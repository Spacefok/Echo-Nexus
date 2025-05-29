#include "narrative/Quest.h"

Quest::Quest(const std::string& questId)
    : QuestId_(questId), Completed_(false) {}

std::string Quest::GetId() const {
    return QuestId_;
}

bool Quest::IsCompleted() const {
    return Completed_;
}

void Quest::Complete() {
    Completed_ = true;
}
