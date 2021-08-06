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
    REQUIRE(steg::textToBin("A") == std::vector<int>{0, 1, 0, 0, 0, 0, 0, 1});
    REQUIRE(steg::textToBin("B") == std::vector<int>{0, 1, 0, 0, 0, 0, 1, 0});
    REQUIRE(steg::textToBin("C") == std::vector<int>{0, 1, 0, 0, 0, 0, 1, 1});
    REQUIRE(steg::textToBin("D") == std::vector<int>{0, 1, 0, 0, 0, 1, 0, 0});
    REQUIRE(steg::textToBin("E") == std::vector<int>{0, 1, 0, 0, 0, 1, 0, 1});
    REQUIRE(steg::textToBin("F") == std::vector<int>{0, 1, 0, 0, 0, 1, 1, 0});
    REQUIRE(steg::textToBin("G") == std::vector<int>{0, 1, 0, 0, 0, 1, 1, 1});
    REQUIRE(steg::textToBin("H") == std::vector<int>{0, 1, 0, 0, 1, 0, 0, 0});
    REQUIRE(steg::textToBin("I") == std::vector<int>{0, 1, 0, 0, 1, 0, 0, 1});
    REQUIRE(steg::textToBin("J") == std::vector<int>{0, 1, 0, 0, 1, 0, 1, 0});
    REQUIRE(steg::textToBin("K") == std::vector<int>{0, 1, 0, 0, 1, 0, 1, 1});
    REQUIRE(steg::textToBin("L") == std::vector<int>{0, 1, 0, 0, 1, 1, 0, 0});
    REQUIRE(steg::textToBin("M") == std::vector<int>{0, 1, 0, 0, 1, 1, 0, 1});
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
    REQUIRE(steg::textToBin("Z") == std::vector<int>{00100000});
}
