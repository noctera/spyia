#pragma once

#include <iostream>
#include <string>
#include <tuple>

#include <spyia/encryption/encryptionBase.hpp>
#include <spyia/encryption/encryptionType.hpp>

#include <cryptopp/rijndael.h>

namespace Spyia::Encryption
{
    class AesCbc: public EncryptionBase
    {
      public:
        explicit AesCbc(const std::string& key);
        AesCbc(const std::string& key, const std::string& iv);

        const std::string &getKey();
        const std::string &getIv();
        std::string encryptContent(const std::string &content) override;
      private:
        std::string m_key;
        std::string m_iv;
    };
}