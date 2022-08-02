#pragma once

#include <cryptopp/cryptlib.h>
#include <cryptopp/rijndael.h>
#include <cryptopp/modes.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/hex.h>

#include <iostream>
#include <string>
#include <tuple>

std::tuple<std::string, std::string> aes_cbc_encrypt(const std::string& input, const std::string &secret)
{
    using namespace CryptoPP;

    AutoSeededRandomPool prng;
    HexEncoder encoder(new FileSink(std::cout));

    SecByteBlock key(reinterpret_cast<const byte*>(&secret[0]), secret.size());
    SecByteBlock iv(AES::BLOCKSIZE);

    prng.GenerateBlock(key, key.size());
    prng.GenerateBlock(iv, iv.size());
    
    std::string cipher, encoded, individualVector;

    /*********************************\
    \*********************************/

    try
    {
        CBC_Mode< AES >::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource s(input, true, 
            new StreamTransformationFilter(e,
                new StringSink(cipher)
            ) // StreamTransformationFilter
        ); // StringSource
    }
    catch(const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

     // Pretty print
    StringSource ss2(
        iv,
        true,
        new HexEncoder(new StringSink(individualVector)) // HexEncoder
    ); // StringSource

    individualVector = reinterpret_cast<const char*>(iv.data()), iv.size();

    return std::make_tuple(encoded, individualVector);
}