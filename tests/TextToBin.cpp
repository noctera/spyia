#include "CppSteg/steganography.hpp"
#include <catch2/catch.hpp>
#include <map>
#include <string>
#include <vector>

TEST_CASE("Check lowercase ASCII letters", "[textToBin]") {
    std::map<std::string, std::string> letterBinaryDict{{"a", "01100001"}, {"b", "01100010"}, {"c", "01100011"},
                                                        {"d", "01100100"}, {"e", "01100101"}, {"f", "01100110"},
                                                        {"g", "01100111"}, {"h", "01101000"}, {"i", "01101001"},
                                                        {"j", "01101010"}, {"k", "01101011"}, {"l", "01101100"},
                                                        {"m", "01101101"}, {"n", "01101110"}, {"o", "01101111"},
                                                        {"p", "01110000"}, {"q", "01110001"}, {"r", "01110010"},
                                                        {"s", "01110011"}, {"t", "01110100"}, {"u", "01110101"},
                                                        {"v", "01110110"}, {"w", "01110111"}, {"x", "01111000"},
                                                        {"y", "01111001"}, {"z", "01111010"}};

    for (auto const& [key, value] : letterBinaryDict) {
        REQUIRE(steg::textToBin(key) == value);
    }

}

TEST_CASE("Check upercase ASCII letters", "[textToBin]") {
    std::map<std::string, std::string> letterBinaryDict{{"A", "01000001"}, {"B", "01000010"}, {"C", "01000011"},
                                                        {"D", "01000100"}, {"E", "01000101"}, {"F", "01000110"},
                                                        {"G", "01000111"}, {"H", "01001000"}, {"I", "01001001"},
                                                        {"J", "01001010"}, {"K", "01001011"}, {"L", "01001100"},
                                                        {"M", "01001101"}, {"N", "01001110"}, {"O", "01001111"},
                                                        {"P", "01010000"}, {"Q", "01010001"}, {"R", "01010010"},
                                                        {"S", "01010011"}, {"T", "01010100"}, {"U", "01010101"},
                                                        {"V", "01010110"}, {"W", "01010111"}, {"X", "01011000"},
                                                        {"Y", "01011001"}, {"Z", "01011010"}};

    for (auto const& [key, value] : letterBinaryDict) {
        REQUIRE(steg::textToBin(key) == value);
    }
}

/*TEST_CASE("Check special ASCII letters", "[textToBin]") {
    std::map<std::string, std::string> letterBinaryDict{{" ", "01000001"}, {"!", "01000010"}, {"\"", "00100010"},
                                                        {"#", "01000100"}, {"$", "01000101"}, {"%", "01000110"},
                                                        {"&", "01000111"}, {"'", "01001000"}, {"(", "01001001"},
                                                        {")", "01001010"}, {"*", "01001011"}, {"+", "01001100"},
                                                        {",", "01001101"}, {"-", "01001110"}, {".", "01001111"},
                                                        {"/", "01010000"}, {"Q", "01010001"}, {"R", "01010010"},
                                                        {"S", "01010011"}, {"T", "01010100"}, {"U", "01010101"},
                                                        {"V", "01010110"}, {"W", "01010111"}, {"X", "01011000"},
                                                        {"Y", "01011001"}, {"Z", "01011010"}};

    for (auto const& [key, value] : letterBinaryDict) {
        REQUIRE(steg::textToBin(key) == value);
    }
}*/

TEST_CASE("Extra Test Case", "[textToBin]") {
    std::string testCase = steg::textToBin("Hello");
    SECTION(testCase) {
        REQUIRE(testCase == "0100100001100101011011000110110001101111");
    }
}
    /*
    REQUIRE(steg::textToBin("N") == std::vector<int>{0, 1, 0, 0, 1, 1, 1, 0});
    REQUIRE(steg::textToBin("O") == std::vector<int>{0, 1, 0, 0, 1, 1, 1, 1});
    REQUIRE(steg::textToBin("P") == std::vector<int>{0, 1, 0, 1, 0, 0, 0, 0});
    REQUIRE(steg::textToBin("Q") == std::vector<int>{0, 1, 0, 1, 0, 0, 0, 1});
    REQUIRE(steg::textToBin("R") == std::vector<int>{0, 1, 0, 1, 0, 0, 1, 0});
    REQUIRE(steg::textToBin("S") == std::vector<int>{0, 1, 0, 1, 0, 0, 1, 1});
    REQUIRE(steg::textToBin("T") == std::vector<int>{0, 1, 0, 1, 0, 1, 0, 0});
    REQUIRE(steg::textToBin("U") == std::vector<int>{0, 1, 0, 1, 0, 1, 0, 1});
    REQUIRE(steg::textToBin("V") == std::vector<int>{0, 1, 0, 1, 0, 1, 1, 0});
    REQUIRE(steg::textToBin("W") == std::vector<int>{0, 1, 0, 1, 0, 1, 1, 1});
    REQUIRE(steg::textToBin("X") == std::vector<int>{0, 1, 0, 1, 1, 0, 0, 0});
    REQUIRE(steg::textToBin("Y") == std::vector<int>{0, 1, 0, 1, 1, 0, 0, 1});
    REQUIRE(steg::textToBin("Z") == std::vector<int>{0, 1, 0, 1, 1, 0, 1, 0});
    REQUIRE(steg::textToBin(" ") == std::vector<int>{00100000});
    REQUIRE(steg::textToBin("Z") == std::vector<int>{00100000});
    REQUIRE(steg::textToBin("Z") == std::vector<int>{00100000});
    REQUIRE(steg::textToBin("Z") == std::vector<int>{00100000});
    REQUIRE(steg::textToBin("Z") == std::vector<int>{00100000});
    REQUIRE(steg::textToBin("Z") == std::vector<int>{00100000});
    REQUIRE(steg::textToBin("Z") == std::vector<int>{00100000});
    REQUIRE(steg::textToBin("Z") == std::vector<int>{00100000});*/
