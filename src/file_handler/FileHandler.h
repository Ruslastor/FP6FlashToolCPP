#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

#define TOOL_WORKSPACE_ROOT "FlashTool"

enum class FileType {
    HEX,
    PR6,
    ES6,
    ModuleInfo,
    FlashLog
};


class FileHandler {
    public:
        virtual ~FileHandler() = default;
    
        virtual bool load(const std::string& path) = 0;

        virtual FileType get_file_type() const = 0;
    
        bool save_to(const std::string& path) const;

        std::filesystem::path get_workspace_root() const;
    private:
        std::vector<std::string> lines;

        static const std::filesystem::path workspace_root;


    protected:
        bool copy_to_workspace(const std::string& source_path, std::filesystem::path& copy_path) const;
    };