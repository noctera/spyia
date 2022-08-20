#pragma once

#include <iostream>
#include <string>
#include <tuple>

#include <spyia/encryption/encryptionBase.hpp>
#include <spyia/encryption/encryptionTypes.hpp>

namespace Spyia
{
    class EncryptionAes: public EncryptionBase
    {
      public:
        EncryptionAes(std::string key, std::string iv);

        const std::string &getKey();
        const std::string &getIv();
        std::string encryptContent(const std::string &content) override;
      private:
        std::string m_key;
        std::string m_iv;
    };
}