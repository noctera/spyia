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
        file.manipulate(positions.at(i), 7, header.at(i));
    }
}

void Lsb::hideSecret(File::FileTypeBase& file, const std::string& secret, const std::vector<int> &reservedBits)
{
    std::size_t maximum = secret.length();
    std::size_t secretPosition = 0;

   for(std::size_t i = 0; i < maximum; ++i) {
       std::cout << i << "/" << maximum << std::endl;
       if(std::find(reservedBits.begin(), reservedBits.end(), i) != reservedBits.end()) {
           // if position is already reserved by header skip it
           ++maximum;
       }
       else {
           // if not manipulate it
           file.manipulate(i, 7, secret.at(secretPosition));
           ++secretPosition;
       }
   }
}