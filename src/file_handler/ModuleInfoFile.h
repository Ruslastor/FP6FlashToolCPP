#pragma once
#include "FileHandler.h"

class ModuleInfoFile : public FileHandler{
    public:
        bool load(const std::string& path) override;

        FileType get_file_type() const override {return FileType::ModuleInfo;}

        std::string get_extention() const override {return ".mod";}

};