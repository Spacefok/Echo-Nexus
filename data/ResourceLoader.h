#pragma once

#include <string>
#include <vector>
#include <cstdint>

// ResourceLoader loads text and binary assets from resource directory
class ResourceLoader {
public:
    explicit ResourceLoader(const std::string& resourcePath);

    // Load text file content by filename (without extension)
    std::string loadText(const std::string& fileName) const;

    // Load binary file content by filename (without extension)
    std::vector<uint8_t> loadBinary(const std::string& fileName) const;

private:
    std::string resourcePath_;
};
