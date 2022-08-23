#include <iostream>

#include <spyia/files/image.hpp>
#include <spyia/secretFile.hpp>
#include <spyia/steganography/stegType.hpp>
#include <spyia/encryption/aes.hpp>
#include <spyia/encryption/none.hpp>
#include <spyia/outputStorage.hpp>
#include <spyia/steganography/lsb/lsb.hpp>

using namespace Spyia;

int main()
{
    File::Image secretImage("/home/julian/Desktop/logo192.png", File::FileType::PNG);
    // Spyia::Encryption::None encryption;
    SecretFile secretFile(std::make_unique<File::Image>(secretImage));
    secretFile.setEncryption(std::make_unique<Encryption::AesCbc>("tjtjtjtjtjtjtjtj"));
    std::cout << "Is encrypted: " << secretFile.isEncrypted() << std::endl;

    OutputStorage outputStorage;

    outputStorage.addFile(std::make_unique<File::Image> (secretImage), std::make_unique<Steganography::Lsb>());
    outputStorage.addFile(std::make_unique<File::Image> (secretImage), std::make_unique<Steganography::Lsb>());

    std::cout << "test" << std::endl;
    // secretFile.setFile(std::make_unique<Spyia::FileType::Image>("/home/julian/Desktop/logo512.png", FileTypes::PNG));

    // std::cout << secretFile.getContent() << std::endl;

    // secretFile.encrypt();
    // std::cout << secretFile.getEncryptedContent() << std::endl;
}