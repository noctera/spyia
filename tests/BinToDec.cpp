#include "CppSteg/Conversions.hpp"
#include <catch2/catch.hpp>
#include <map>
#include <string>

TEST_CASE("Check binary to decimal conversion for numbers from 0 - 9", "[binToDec]") {


    std::map<std::string, int> binToDecDict{{"0000000", 0},  {"0000001", 1}, {"00000010", 2}, {"00000011", 3},
                                            {"00000100", 4}, {"00000101", 5}, {"00000110", 6}, {"00000111", 7},
                                            {"00001000", 8}, {"00001001", 9}};

    for (auto const& x : binToDecDict) {
        REQUIRE(cppsteg::conv::binToDec(x.first) == x.second);
    }
}