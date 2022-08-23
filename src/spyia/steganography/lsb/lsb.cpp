#include <spyia/steganography/lsb/lsb.hpp>
#include <spyia/steganography/stegType.hpp>
#include <iostream>


using namespace Spyia::Steganography;

Lsb::Lsb() : StegAlgoBase(StegType::LSB){}

void Lsb::hide(cv::Mat img)
{
    std::cout << "hide image" << std::endl;
}