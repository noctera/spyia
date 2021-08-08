#include <CppSteg/steganography.hpp>
#include <iostream>
#include <chrono>

int main() {
    // hiding secret message
    // Starting time for the clock

    std::string testString = "";
    for (int i = 0; i < 500000; ++i) {
        testString += "t";
    }

        auto start = std::chrono::high_resolution_clock::now();
    steg::leastSignificantBitEncode("/home/julian/CppSteg/input.png", "/home/julian/CppSteg/output.png", testString);

    // Ending time for the clock
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Start time: " << std::chrono::duration_cast<std::chrono::microseconds>(start.time_since_epoch()).count() << std::endl;
    std::cout << "End time: " << std::chrono::duration_cast<std::chrono::microseconds>(stop.time_since_epoch()).count() << std::endl;
    std::cout << "Time taken by insertion sort: " << duration.count() << " microseconds" << std::endl;

    // decode message from manipulated picture
    //std::cout << steg::leastSignificantBitDecode("/home/julian/CppSteg/output.png") << std::endl;
}