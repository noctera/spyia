#include <CppSteg/steganography.hpp>
#include <iostream>

int main() {
    // hiding secret message
    steg::leastSignificantBitEncode("/home/julian/steganography/input.png", "/home/julian/steganography/output.png", "My secret Message");

    // decode message from manipulated picture
    std::cout << steg::leastSignificantBitDecode("/home/julian/steganography/output.png") << std::endl;
}