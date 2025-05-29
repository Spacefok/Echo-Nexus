#include "narrative/MemoryFragment.h"

MemoryFragment::MemoryFragment(const std::string& id, const std::string& content)
    : Id_(id), Content_(content), Unlocked_(false) {}

const std::string& MemoryFragment::GetId() const {
    return Id_;
}

const std::string& MemoryFragment::GetContent() const {
    return Content_;
}

bool MemoryFragment::IsUnlocked() const {
    return Unlocked_;
}

void MemoryFragment::Unlock() {
    Unlocked_ = true;
}
