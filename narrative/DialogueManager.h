#ifndef NARRATIVE_DIALOGUEMANAGER_H
#define NARRATIVE_DIALOGUEMANAGER_H

#include <string>

// Manages branching dialogues in the narrative system
class DialogueManager {
   public:
    DialogueManager();
    std::string GetDialogueLine(const std::string& nodeId) const;
    void AdvanceDialogue(const std::string& nodeId);
};
#endif
