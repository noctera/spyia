#include <iostream>

#include <spyia/files/image.hpp>
#include <spyia/secretFile.hpp>
#include <spyia/steganography/stegTypes.hpp>
#include <spyia/encryption/aes.hpp>
#include <spyia/encryption/none.hpp>

int main()
{
    Spyia::FileType::Image secretImage("/home/julian/Desktop/logo192.png", Spyia::FileTypes::PNG);
    // Spyia::Encryption::None encryption;
    Spyia::Encryption::AesCbc encryption("djwdktdldetdjtsj");
    Spyia::SecretFile secretFile(secretImage, encryption);

    // std::cout << secretFile.getContent() << std::endl;

    secretFile.encrypt();
    std::cout << secretFile.getEncryptedContent() << std::endl;
}