#include "narrative/StoryGraph.h"

StoryGraph::StoryGraph() = default;

void StoryGraph::AddNode(const std::string& id, const std::vector<std::string>& next) {
    Graph_[id] = next;
}

std::vector<std::string> StoryGraph::GetNext(const std::string& id) const {
    auto it = Graph_.find(id);
    if (it != Graph_.end()) return it->second;
    return {};
}
