#pragma once
#include "narrative/MemoryFragment.h"
#include <string>

// Represents a single piece of recovered memory in the narrative system
class MemoryFragment {
public:
    // Constructor: set unique identifier and text content
    MemoryFragment(const std::string& id, const std::string& content);

    // Returns the fragment's identifier
    const std::string& GetId() const;

    // Returns the text content of the fragment
    const std::string& GetContent() const;

    // Has this fragment been unlocked (revealed) yet?
    bool IsUnlocked() const;

    // Mark this fragment as unlocked
    void Unlock();

private:
    std::string Id_;        // Unique key for lookup
    std::string Content_;   // The narrative text
    bool Unlocked_;         // Reveal state
};