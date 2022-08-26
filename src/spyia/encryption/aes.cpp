#include <spyia/encryption/aes.hpp>

#include <cryptopp/cryptlib.h>
#include <cryptopp/rijndael.h>
#include <cryptopp/modes.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/hex.h>

using namespace Spyia::Encryption;
using namespace CryptoPP;

AesCbc::AesCbc(const std::string& key)
    : EncryptionBase(EncryptionType::AES_CBC)
{
    if(key.length() != 16) {
        throw std::invalid_argument( "key must have a length of 16" );
    }
    m_key = key;

    // generate iv and convert it to string
    AutoSeededRandomPool prng;
    SecByteBlock iv(AES::BLOCKSIZE);
    prng.GenerateBlock(iv, iv.size());
    std::string tempIv = std::string(reinterpret_cast<const char*>(iv.data()), iv.size());
    StringSource ss1(
        tempIv,
        true,
        new HexEncoder(new StringSink(m_iv)) // HexEncoder
    ); // StringSource

}

AesCbc::AesCbc(const std::string& key, const std::string& iv)
    : EncryptionBase(EncryptionType::AES_CBC)
{
    if(key.length() != 16 || iv.length() != 16) {
        throw std::invalid_argument( "key and iv must have a length of 16" );
    }
    m_key = key;
}

const std::string& AesCbc::getKey()
{
    return m_key;
}

const std::string& AesCbc::getIv()
{
    return m_iv;
}

std::string AesCbc::encryptContent(const std::string &content)
{


    AutoSeededRandomPool prng;
    HexEncoder encoder(new FileSink(std::cout));

    CryptoPP::SecByteBlock key(reinterpret_cast<const CryptoPP::byte*>(&m_key[0]), m_key.size());
    CryptoPP::SecByteBlock iv(reinterpret_cast<const CryptoPP::byte*>(&m_key[0]), m_key.size());

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