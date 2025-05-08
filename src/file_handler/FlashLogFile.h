#pragma once
#include "FileHandler.h"

class FlashLogFile : public FileHandler{
    public:
        bool load(const std::string& path) override;

        FileType get_file_type() const override {return FileType::FlashLog;}

        std::string get_extention() const override {return ".flog";}
};