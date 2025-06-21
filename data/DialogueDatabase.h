#ifndef DATA_DIALOGUEDATABASE_H
#define DATA_DIALOGUEDATABASE_H

#include <string>

// Manages retrieval of dialogue entries
class DialogueDatabase {
   public:
    // Construct with path to dialogue data
    explicit DialogueDatabase(const std::string& dbPath);

    // Get dialogue text by key
    std::string getDialogue(const std::string& key) const;
};
#endif
