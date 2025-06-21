#include "narrative/MemoryFragment.h"

MemoryFragment::MemoryFragment(const std::string& id, const std::string& content)
    : id_(id), content_(content), unlocked_(false) {}

const std::string& MemoryFragment::getId() const { return id_; }

const std::string& MemoryFragment::getContent() const { return content_; }

bool MemoryFragment::isUnlocked() const { return unlocked_; }

void MemoryFragment::unlock() { unlocked_ = true; }
