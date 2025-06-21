#include "narrative/Quest.h"

Quest::Quest(const std::string& questId)
    : questId_(questId), completed_(false) {}

std::string Quest::getId() const {
    return questId_;
}

bool Quest::isCompleted() const {
    return completed_;
}

void Quest::complete() {
    completed_ = true;
}
