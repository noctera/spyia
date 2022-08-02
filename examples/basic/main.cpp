#include <iostream>

#include <spyia/fileTypes/image.hpp>
#include <spyia/stegHandler.hpp>
#include <spyia/secretFile.hpp>

int main()
{
    Spyia::StegHandler stegHandler("/home/julian/Desktop/Test");
    stegHandler.addSecretFile(Spyia::SecretFile("/home/julian/Desktop/logo192.png"));
    stegHandler.encrypt_aes_cbc();

    // stegHandler.addOutputFile(Spyia::FileType::Image("path"), Spyia::Method::LSB);
    // stegHandler.addOutputFile(Spyia::FileType::Image("path"), Spyia::Method::LSB);

    // Spyia::Secret secret(Spyia::Type::)

    

    // Spyia::SecretFile secretFile("/home/julian/Desktop/logo192.png");
    // secretFile.aes_encrypt();

    // Spyia::OutputStorage outputStorage("/home/julian/Test/", secretFile);
    // outputStorage.addFile(Spyia::FileType::Image("/path"), Spyia::Technique::LSB);
    // outputStorage.addFile(Spyia::FileType::Image("path"), Spyia::Technique::LSB);

    // outputStorage.hide();

    // std::cout << aes_encrypt(secretFile.getContent()) << std::endl;
    // Spyia::FileType::Image image("/home/julian/Desktop/input.jpg");
}