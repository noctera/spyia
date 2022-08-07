#include <iostream>

#include <spyia/fileTypes/image.hpp>
#include <spyia/stegHandler.hpp>
#include <spyia/secretFile.hpp>
#include <spyia/steganography/stegTypes.hpp>
#include <spyia/outputStorage.hpp>

int main()
{
    Spyia::SecretFile secretFile("/home/julian/Desktop/logo192.png");
    secretFile.encrypt_aes_cbc("dasIstEinTest123");

    Spyia::OutputStorage outputStorage;
    outputStorage.addImage(Spyia::FileType::Image("/home/julian/Desktop/logo512.png"), Spyia::StegTypes::LSB );

    Spyia::StegHandler stegHandler("/home/julian/Desktop/Test", secretFile, outputStorage);
}