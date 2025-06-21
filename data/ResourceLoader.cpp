#include "data/ResourceLoader.h"
#include <fstream>
#include <stdexcept>
#include <cstdint>
#include <iterator>

ResourceLoader::ResourceLoader(const std::string& resourcePath)
    : resourcePath_(resourcePath) {}

std::string ResourceLoader::loadText(const std::string& fileName) const {
    std::string fullPath = resourcePath_ + "/" + fileName + ".txt";
    std::ifstream input(fullPath);
    if (!input.is_open()) {
        throw std::runtime_error("Cannot open text resource: " + fullPath);
    }

    std::string content((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
    return content;  // Return entire file as string
}

std::vector<uint8_t> ResourceLoader::loadBinary(const std::string& fileName) const {
    std::string fullPath = resourcePath_ + "/" + fileName;
    std::ifstream input(fullPath, std::ios::binary);
    if (!input.is_open()) {
        throw std::runtime_error("Cannot open binary resource: " + fullPath);
    }

    std::vector<uint8_t> buffer((std::istreambuf_iterator<char>(input)),
                               std::istreambuf_iterator<char>());
    return buffer;  // Return raw bytes
}
