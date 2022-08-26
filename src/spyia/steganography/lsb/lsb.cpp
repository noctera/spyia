#include <spyia/steganography/lsb/lsb.hpp>
#include <spyia/steganography/stegType.hpp>
#include <iostream>


using namespace Spyia::Steganography;

Lsb::Lsb() : StegAlgoBase(StegType::LSB, 8){}

std::string Lsb::generateHeader(int position, int maxFiles) const
{
    return "f:" + std::to_string(position) + "/" + std::to_string(maxFiles) + "-LSB";
}

void Lsb::hide(cv::Mat img)
{
    std::cout << "hide image" << std::endl;
}