#include <iostream>

#include <spyia/files/image.hpp>
#include <spyia/secretFile.hpp>
#include <spyia/steganography/stegType.hpp>
#include <spyia/encryption/aes.hpp>
#include <spyia/encryption/none.hpp>

using namespace Spyia;

int main()
{
    FileType::Image secretImage("/home/julian/Desktop/logo192.png", File::FileType::PNG);
    // Spyia::Encryption::None encryption;
    SecretFile secretFile(std::make_unique<FileType::Image>(secretImage));
    secretFile.setEncryption(std::make_unique<Encryption::AesCbc>("tjtjtjtjtjtjtjtj"));
    std::cout << "Is encrypted: " << secretFile.isEncrypted() << std::endl;

    // secretFile.setFile(std::make_unique<Spyia::FileType::Image>("/home/julian/Desktop/logo512.png", FileTypes::PNG));

    // std::cout << secretFile.getContent() << std::endl;

    // secretFile.encrypt();
    // std::cout << secretFile.getEncryptedContent() << std::endl;
}