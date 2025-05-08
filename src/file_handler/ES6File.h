#pragma once

#include "FileHandler.h"


class ES6File : public FileHandler{
    public:
        bool load(const std::string& path) override;

        FileType get_file_type() const override {return FileType::ES6;}

        std::string get_extention() const override {return ".ex6";}

};