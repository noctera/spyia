#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>
#include <bitset>

#include <spyia/encryption/encryptionType.hpp>

namespace Spyia {
    inline std::vector<int> generateNumbersBySeed(const std::string &seed, int amount, int min, int max)
    {
        std::vector<int> numbers;
        // TODO: Maybe add recursion in the future

        std::uniform_int_distribution<int> uniform_dist(min, max);
        for (std::size_t i = 0; i < amount; ++i)
        {
            // add the index at every cycle to generate a new number, otherwise it would always return the same number
            std::default_random_engine e1(std::hash<std::string>{}(seed + std::to_string(i)));

            // generate random number located in given span
            int randomNumber = uniform_dist(e1);
            while (std::find(numbers.begin(), numbers.end(), randomNumber) != numbers.end())
            {
                // if number already got generated, increase index and max number to generate a new number with new seed
                // without changing the amount of numbers returned
                ++i;
                ++amount;
                e1 = std::default_random_engine (std::hash<std::string>{}(seed + std::to_string(i)));
                randomNumber = uniform_dist(e1);
            }
            numbers.push_back(randomNumber);
        }
        return numbers;
    }

    inline std::vector<std::string> divideString(std::string input, int n)
    {
        std::vector<std::string> stringParts;
        int stringSize = input.size() / n;
        int nextStringPart = stringSize;

        for(std::size_t i = 0; i < n; ++i) {
            if(i == 0) {
                stringParts.emplace_back(input.substr(0,nextStringPart - 1));
            }
            else if(i + 1 == n) {
                stringParts.emplace_back(input.substr(nextStringPart,input.size()));
            }
            else {
                stringParts.emplace_back(input.substr(nextStringPart,nextStringPart + stringSize - 1));
                nextStringPart += stringSize;
            }
        }
        return stringParts;
    }

    inline std::string encryptionTypeToString(Encryption::EncryptionType encryptionType)
    {
        switch(encryptionType) {
            case Encryption::EncryptionType::AES_CBC: return "AESCBC"; break;
            case Encryption::EncryptionType::NONE: return "NONE"; break;
        }
    }

    inline std::string fileTypeToString(File::FileType fileType)
    {
        switch(fileType) {
            case File::FileType::JPEG: return "JPEG"; break;
            case File::FileType::GIF: return "GIF"; break;
            case File::FileType::SVG: return "SVG"; break;
            case File::FileType::PNG: return "PNG"; break;
            case File::FileType::TIF: return "TIF"; break;
            case File::FileType::MP4: return "MP4"; break;
            case File::FileType::AVI: return "AVI"; break;
            case File::FileType::MOV: return "MOV"; break;
            case File::FileType::FLV: return "FLV"; break;
            case File::FileType::AVCHD: return "AVCHD"; break;
            case File::FileType::M4A: return "M4A"; break;
            case File::FileType::MP3: return "MP3"; break;
            case File::FileType::WAV: return "WAV"; break;
            case File::FileType::PDF: return "PDF"; break;
            case File::FileType::DOC: return "DOC"; break;
            case File::FileType::DOCX: return "DOCX"; break;
            case File::FileType::HTML: return "HTML"; break;
            case File::FileType::XLS: return "XLS"; break;
            case File::FileType::TXT: return "TXT"; break;
            case File::FileType::PPT: return "PPT"; break;
            case File::FileType::PPTX: return "PPTX"; break;
            case File::FileType::ODP: return "ODP"; break;
            case File::FileType::KEY: return "KEY"; break;
        }
    }

    inline std::string decToBin(const int& input) {
        return std::bitset<8>(input).to_string();
    }

    inline unsigned char binToDec(const std::string& input) {
        return std::bitset<8>(input).to_ulong();
    }

    inline void manipulateByte(unsigned char& pixel, int bitPosition, const char& bit) {
        std::string binConvertedValue = decToBin(pixel);

        // manipulate last bit of binary number
        binConvertedValue[bitPosition] = bit;

        // change out color value
        pixel = binToDec(binConvertedValue);
    }
}

# endif