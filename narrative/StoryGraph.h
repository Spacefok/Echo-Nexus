#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// Represents branching structure of the narrative
class StoryGraph {
public:
    StoryGraph();
    void AddNode(const std::string& id, const std::vector<std::string>& next);
    std::vector<std::string> GetNext(const std::string& id) const;

private:
    std::unordered_map<std::string, std::vector<std::string>> Graph_;
};
