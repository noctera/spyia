#include "../include/Steganography.h"
#include <chrono>
#include <iomanip>
#include <iostream>

using namespace cv;

int main(int argc, char** argv) {
    std::string name = "";
    for (int i = 0; i < 50000; ++i) {
        name += "t";
    }
    // Starting time for the clock
    auto start = std::chrono::high_resolution_clock::now();

    // Simulate doing work
    steg::leastSignificantBitEncode("/home/julian/steganography/src/steno_2.png", name);

    // Ending time for the clock
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Start time: " << std::chrono::duration_cast<std::chrono::microseconds>(start.time_since_epoch()).count() << std::endl;
    std::cout << "End time: " << std::chrono::duration_cast<std::chrono::microseconds>(stop.time_since_epoch()).count() << std::endl;
    std::cout << "Time taken by insertion sort: " << duration.count() << " microseconds" << std::endl;
    // std::string image_path = samples::findFile("image.jpg");
}