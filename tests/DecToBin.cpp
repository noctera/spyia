#include "CppSteg/Conversions.hpp"
#include <catch2/catch.hpp>
#include <map>
#include <string>

TEST_CASE("Check decimal to binary conversion for numbers from 0 - 9", "[decToBin]") {
    std::map<int, std::string> decToBinDict{{0, "00000000"},  {1, "00000001"}, {2, "00000010"}, {3, "00000011"},
                                            {4, "00000100"}, {5, "00000101"}, {6, "00000110"}, {7, "00000111"},
                                            {8, "00001000"}, {9, "00001001"}};

    for (auto const& x : decToBinDict) {
        REQUIRE(cppsteg::conv::decToBin(x.first) == x.second);
    }
}