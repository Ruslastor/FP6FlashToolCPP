#pragma once
#include "FileHandler.h"

class HexFile : public FileHandler {
    public:
        bool load(const std::string& path) override;
    
        FileType get_file_type() const override {return FileType::HEX;}
    
};