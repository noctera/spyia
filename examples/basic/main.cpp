#include <iostream>

#include <spyia/files/image.hpp>
#include <spyia/secretFile.hpp>
#include <spyia/steganography/stegType.hpp>
#include <spyia/encryption/aes.hpp>
#include <spyia/encryption/none.hpp>
#include <spyia/hideHandler.hpp>
#include <spyia/steganography/lsb/lsb.hpp>
#include <spyia/utils/utils.hpp>
#include <algorithm>

using namespace Spyia;

int main()
{
    Encryption::AesCbc encryption("dasisteintest123");

    SecretFile secretFile("/home/julian/Desktop/logo512.png", File::FileType::PNG);

    std::cout << "1. needed bits: " << secretFile.getNeededBits() << std::endl;

    // secretFile.setEncryption(std::make_unique<Encryption::AesCbc>(encryption));

    // secretFile.encrypt();
    //std::cout << "Is encrypted: " << secretFile.isEncrypted() << std::endl;
    std::cout << "2. needed bits: " << secretFile.getNeededBits() << std::endl;

    HideHandler hideHandler("/home/julian/Desktop/test", secretFile, std::make_unique<Encryption::AesCbc>(encryption));

    File::Image outputImage1("/home/julian/Desktop/logo512.png", File::FileType::PNG);
    File::Image outputImage2("/run/media/julian/Volume/Bilder/test.png", File::FileType::PNG);

    hideHandler.addFile(std::make_unique<File::Image>(outputImage1), std::make_unique<Steganography::Lsb>());
    hideHandler.addFile(std::make_unique<File::Image>(outputImage1), std::make_unique<Steganography::Lsb>());
    hideHandler.addFile(std::make_unique<File::Image>(outputImage2), std::make_unique<Steganography::Lsb>());

    std::cout << "Max Storable Bits: " << hideHandler.getMaxStorableBits() << '\n';
    std::cout << "Max Storable Bits: " << hideHandler.getMaxStorableBitsForFile(0) << '\n';

    hideHandler.hide();
}