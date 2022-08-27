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
    Encryption::AesCbc encryption("tjtjtjtjtjtjtjtj");

    SecretFile secretFile("/home/julian/Desktop/logo512.png", File::FileType::PNG);

    std::cout << "1. needed bits: " << secretFile.getNeededBits() << std::endl;

    // secretFile.setEncryption(std::make_unique<Encryption::AesCbc>(encryption));

    // secretFile.encrypt();
    //std::cout << "Is encrypted: " << secretFile.isEncrypted() << std::endl;
    std::cout << "2. needed bits: " << secretFile.getNeededBits() << std::endl;

    HideHandler hideHandler(secretFile);

    File::Image secretImage("/run/media/julian/Volume/Bilder/Unbenannt.png", File::FileType::PNG);

    hideHandler.addFile(std::make_unique<File::Image>(secretImage), std::make_unique<Steganography::Lsb>());
    hideHandler.addFile(std::make_unique<File::Image>(secretImage), std::make_unique<Steganography::Lsb>());

    hideHandler.generateHeaders();


    std::cout << "test";
}