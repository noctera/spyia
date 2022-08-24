#include <iostream>

#include <spyia/files/image.hpp>
#include <spyia/secretFile.hpp>
#include <spyia/steganography/stegType.hpp>
#include <spyia/encryption/aes.hpp>
#include <spyia/encryption/none.hpp>
#include <spyia/outputStorage.hpp>
#include <spyia/steganography/lsb/lsb.hpp>
#include <spyia/stegHandler.hpp>

using namespace Spyia;

int main()
{
    File::Image secretImage("/home/julian/Desktop/logo192.png", File::FileType::PNG);
    // Spyia::Encryption::None encryption;
    SecretFile secretFile(std::make_unique<File::Image>(secretImage));

    //std::cout << "1. needed bits: " << secretFile.getNeededBits() << std::endl;

    secretFile.setEncryption(std::make_unique<Encryption::AesCbc>("tjtjtjtjtjtjtjtj"));

    secretFile.encrypt();
    //std::cout << "Is encrypted: " << secretFile.isEncrypted() << std::endl;
    // std::cout << "2. needed bits: " << secretFile.getNeededBits() << std::endl;
    std::cout << secretFile.getByteCode() << std::endl;

    OutputStorage outputStorage;

    outputStorage.addFile(std::make_unique<File::Image>(secretImage), std::make_unique<Steganography::Lsb>());
    outputStorage.addFile(std::make_unique<File::Image>(secretImage), std::make_unique<Steganography::Lsb>());

    StegHandler stegHandler(secretFile, outputStorage);

    stegHandler.hide();

    std::cout << "test";
}