#include <spyia/encryption/aes.hpp>

#include <cryptopp/cryptlib.h>
#include <cryptopp/rijndael.h>
#include <cryptopp/modes.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/hex.h>

using namespace Spyia;

EncryptionAes::EncryptionAes(std::string key, std::string iv)
    : EncryptionBase(EncryptionType::AES_CBC), m_key(key), m_iv(iv)
{}

const std::string& EncryptionAes::getKey()
{
    return m_key;
}

const std::string& EncryptionAes::getIv()
{
    return m_iv;
}

std::string EncryptionAes::encryptContent(const std::string &content)
{
    using namespace CryptoPP;

    AutoSeededRandomPool prng;
    HexEncoder encoder(new FileSink(std::cout));

    SecByteBlock key(reinterpret_cast<const byte*>(&m_key[0]), m_key.size());
    SecByteBlock iv(AES::BLOCKSIZE);

    prng.GenerateBlock(key, key.size());
    prng.GenerateBlock(iv, iv.size());

    std::string cipher, cipherEncoded;

    // encrypt string with AES (CBC) algorithm
    try
    {
        CBC_Mode< AES >::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource s(content, true,
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

    // convert cipher output to printable version
    StringSource ss2(
        cipher,
        true,
        new HexEncoder(new StringSink(cipherEncoded)) // HexEncoder
    ); // StringSource

    return cipherEncoded;
}