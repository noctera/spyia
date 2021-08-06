#include "CppSteg/steganography.hpp"
#include <catch2/catch.hpp>
#include <string>
#include <vector>

TEST_CASE("Check if conversions from ASCII letters to binary are successful", "[textToBin]") {
    REQUIRE(steg::textToBin("a") == std::vector<int>{0, 1, 1, 0, 0, 0, 0, 1});
    REQUIRE(steg::textToBin("b") == std::vector<int>{0, 1, 1, 0, 0, 0, 1, 0});
    REQUIRE(steg::textToBin("c") == std::vector<int>{0, 1, 1, 0, 0, 0, 1, 1});
    REQUIRE(steg::textToBin("d") == std::vector<int>{0, 1, 1, 0, 0, 1, 0, 0});
    REQUIRE(steg::textToBin("e") == std::vector<int>{0, 1, 1, 0, 0, 1, 0, 1});
    REQUIRE(steg::textToBin("f") == std::vector<int>{0, 1, 1, 0, 0, 1, 1, 0});
    REQUIRE(steg::textToBin("g") == std::vector<int>{0, 1, 1, 0, 0, 1, 1, 1});
    REQUIRE(steg::textToBin("h") == std::vector<int>{0, 1, 1, 0, 1, 0, 0, 0});
    REQUIRE(steg::textToBin("i") == std::vector<int>{0, 1, 1, 0, 1, 0, 0, 1});
    REQUIRE(steg::textToBin("j") == std::vector<int>{0, 1, 1, 0, 1, 0, 1, 0});
    REQUIRE(steg::textToBin("k") == std::vector<int>{0, 1, 1, 0, 1, 0, 1, 1});
    REQUIRE(steg::textToBin("l") == std::vector<int>{0, 1, 1, 0, 1, 1, 0, 0});
    REQUIRE(steg::textToBin("m") == std::vector<int>{0, 1, 1, 0, 1, 1, 0, 1});
    REQUIRE(steg::textToBin("n") == std::vector<int>{0, 1, 1, 0, 1, 1, 1, 0});
    REQUIRE(steg::textToBin("o") == std::vector<int>{0, 1, 1, 0, 1, 1, 1, 1});
    REQUIRE(steg::textToBin("p") == std::vector<int>{0, 1, 1, 1, 0, 0, 0, 0});
    REQUIRE(steg::textToBin("q") == std::vector<int>{0, 1, 1, 1, 0, 0, 0, 1});
    REQUIRE(steg::textToBin("r") == std::vector<int>{0, 1, 1, 1, 0, 0, 1, 0});
    REQUIRE(steg::textToBin("s") == std::vector<int>{0, 1, 1, 1, 0, 0, 1, 1});
    REQUIRE(steg::textToBin("t") == std::vector<int>{0, 1, 1, 1, 0, 1, 0, 0});
    REQUIRE(steg::textToBin("u") == std::vector<int>{0, 1, 1, 1, 0, 1, 0, 1});
    REQUIRE(steg::textToBin("v") == std::vector<int>{0, 1, 1, 1, 0, 1, 1, 0});
    REQUIRE(steg::textToBin("w") == std::vector<int>{0, 1, 1, 1, 0, 1, 1, 1});
    REQUIRE(steg::textToBin("x") == std::vector<int>{0, 1, 1, 1, 1, 0, 0, 0});
    REQUIRE(steg::textToBin("y") == std::vector<int>{0, 1, 1, 1, 1, 0, 0, 1});
    REQUIRE(steg::textToBin("z") == std::vector<int>{0, 1, 1, 1, 1, 0, 1, 0});
}
