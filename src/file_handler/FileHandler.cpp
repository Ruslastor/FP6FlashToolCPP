#include "FileHandler.h"


const std::filesystem::path FileHandler::workspace_root = std::filesystem::path(std::getenv("APPDATA")) / TOOL_WORKSPACE_ROOT;

std::filesystem::path FileHandler::get_workspace_root() const{return workspace_root;}

bool FileHandler::saveTo(const std::string& path) const{
    std::ofstream out(path);
    if (!out) return false;
    for (const auto& line : lines) {
        out << line << "\n";
    }
    return true;
}

bool FileHandler::copy_to_workspace(const std::string& source_path, std::filesystem::path& copy_path) const {
    namespace fs = std::filesystem;
    fs::path source = source_path;

    std::string subdir;
    switch (get_file_type()) {
        case FileType::HEX: subdir = "hex"; break;
        case FileType::PR6: subdir = "pr6"; break;
        case FileType::ES6: subdir = "es6"; break;
        case FileType::ModuleInfo: subdir = "modules"; break;
        default: subdir = "misc"; break;
    }

    fs::path destination_dir = get_workspace_root() / subdir;

    fs::create_directories(destination_dir);
    fs::path destination = destination_dir / source.filename();

    try {
        fs::copy_file(source, destination, fs::copy_options::overwrite_existing);
        copy_path = destination;
        return true;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "[FileHandler] Copy error: " << e.what() << "\n";
        return false;
    }
}