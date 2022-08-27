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

namespace Spyia {
    inline std::vector<int> generateNumbersBySeed(const std::string &seed, int amount, int min, int max)
    {
        std::vector<int> numbers;
        // TODO: Maybe add recursion in the future

        std::uniform_int_distribution<int> uniform_dist(min, max);
        for (std::size_t i = 0; i < amount; ++i)
        {
            // add the index at every cycle to generate a new number, otherwise it would always return the same number
            std::default_random_engine e1(std::hash<std::string>{}(seed + char(i)));

            // generate random number located in given span
            int randomNumber = uniform_dist(e1);
            while (std::find(numbers.begin(), numbers.end(), randomNumber) != numbers.end())
            {
                // if number already got generated, increase index and max number to generate a new number with new seed
                // without changing the amount of numbers returned
                ++i;
                ++amount;
                e1 = std::default_random_engine (std::hash<std::string>{}(seed + char(i)));
                randomNumber = uniform_dist(e1);
            }
            numbers.push_back(randomNumber);
        }
        return numbers;
    }

    inline std::string encryptionToString(Encryption::EncryptionType encryptionType) {
        switch(encryptionType) {
            case Encryption::EncryptionType::AES_CBC: return "AESCBC";
            case Encryption::EncryptionType::NONE: return "NONE";
        }
    }
}

# endif