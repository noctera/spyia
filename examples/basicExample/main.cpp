#include <CppSteg/Steganography.hpp>
#include <iostream>
#include <chrono>
#include <map>
#include <string>
#include <vector>

int main() {
    // Starting time for the clock
    auto start = std::chrono::high_resolution_clock::now();
    cppsteg::leastBit::encodeText("/home/julian/CppSteg/input.png", "/home/julian/CppSteg/output.png", "12345678910");

    // Ending time for the clock
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Start time: " << std::chrono::duration_cast<std::chrono::microseconds>(start.time_since_epoch()).count() << std::endl;
    std::cout << "End time: " << std::chrono::duration_cast<std::chrono::microseconds>(stop.time_since_epoch()).count() << std::endl;
    std::cout << "Time taken by insertion sort: " << duration.count() << " microseconds" << std::endl;

    // decode message from manipulated picture
    std::cout << cppsteg::leastBit::decodeText("/home/julian/CppSteg/output.png") << std::endl;
}
