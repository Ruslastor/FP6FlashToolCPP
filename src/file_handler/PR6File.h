#pragma once

#include "FileHandler.h"


class PR6File : public FileHandler{
    public:
        bool load(const std::string& path) override;

        FileType get_file_type() const override {return FileType::PR6;}

        std::string get_extention() const override {return ".pr6";}

};