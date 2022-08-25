#pragma once

#include <string>
#include <fstream>
#include <exception>

namespace Spyia {
    std::string fileToBinary(const std::string &filePath) {
        std::ifstream ifs(filePath, std::ios::binary);
        if(!ifs)
        {
            throw std::invalid_argument("Could not open secret file");
        }
        return std::string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    }
}
