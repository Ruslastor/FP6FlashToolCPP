#include "ES6File.h"

bool ES6File::load(const std::string& path) {
    std::ifstream in(path);
    if (!in) {
        std::cerr << "[ES6File] Could not open file at " << path << "\n";
        return false;
    }

    std::string line;
    while (std::getline(in, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    return true;
}