#pragma once

#include <bitset>
#include <string>

namespace Spyia::Conversion {
    inline std::string textToBin(const std::string& input) {
        std::string bitStr = "";

        for (std::size_t i = 0; i < input.size(); ++i) {
            bitStr += std::bitset<8>(input[i]).to_string();
        }
        return bitStr;
    }

    // the header consists of 32 bits that indicate the length of the text
    inline std::string createHeader(int stringLength) {
        return std::bitset<32>(stringLength).to_string();
    }
    inline std::string decToBin(const int& input) {
        return std::bitset<8>(input).to_string();
    }

    inline unsigned char binToDec(const std::string& input) {
        return std::bitset<8>(input).to_ulong();
    }

    inline char binToText(const std::string& input) {
        return std::bitset<8>(input).to_ulong();
    }

    inline int decodeHeader(std::string header) {
        std::bitset<32> temp(header);
        return static_cast<int>(temp.to_ulong());
    }

}