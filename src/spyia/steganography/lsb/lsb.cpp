#include <spyia/steganography/lsb/lsb.hpp>
#include <spyia/steganography/stegType.hpp>
#include <spyia/files/fileTypeBase.hpp>
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

void Lsb::hideHeader(File::FileTypeBase& file, const std::string &header, const std::vector<int> &positions)
{
    for(std::size_t i = 0; i < positions.size(); ++i) {
        file.manipulate(positions[i], 7, header[i]);
    }
}

void Lsb::hide(File::FileTypeBase& file)
{
    std::cout << "hide image" << std::endl;
}