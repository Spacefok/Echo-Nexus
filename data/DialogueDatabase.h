#pragma once

#include <string>

// Manages retrieval of dialogue entries
class DialogueDatabase {
public:
    // Construct with path to dialogue data
    explicit DialogueDatabase(const std::string& dbPath);

    // Get dialogue text by key
    std::string GetDialogue(const std::string& key) const;
};
