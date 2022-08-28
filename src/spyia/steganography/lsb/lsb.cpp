#include <spyia/steganography/lsb/lsb.hpp>
#include <spyia/steganography/stegType.hpp>
#include <spyia/utils/utils.hpp>
#include <iostream>

using namespace Spyia;
using namespace Spyia::Steganography;

Lsb::Lsb() : StegAlgoBase(StegType::LSB, 8){}

std::string Lsb::generateHeader(int position, int maxFiles, File::FileType fileType, Spyia::Encryption::EncryptionType encryptionType, const std::string &iv) const
{
    // header example: f:1/3-AESCBC:iv-LSB
    return "f:" + std::to_string(position) + "/" + std::to_string(maxFiles) + "-" + fileTypeToString(fileType) + "-" + encryptionTypeToString(encryptionType) + ":" + iv + "-LSB";
}

void Lsb::hide(cv::Mat img)
{
    std::cout << "hide image" << std::endl;
}