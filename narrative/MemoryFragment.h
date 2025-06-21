#pragma once
#include "narrative/MemoryFragment.h"
#include <string>

// Represents a single piece of recovered memory in the narrative system
class MemoryFragment {
public:
    // Constructor: set unique identifier and text content
    MemoryFragment(const std::string& id, const std::string& content);

    // Returns the fragment's identifier
    const std::string& getId() const;

    // Returns the text content of the fragment
    const std::string& getContent() const;

    // Has this fragment been unlocked (revealed) yet?
    bool isUnlocked() const;

    // Mark this fragment as unlocked
    void unlock();

private:
    std::string id_;        // Unique key for lookup
    std::string content_;   // The narrative text
    bool unlocked_;         // Reveal state
};
