#pragma once

#include <string>

#include <spyia/encryption/encryptionType.hpp>

namespace Spyia::Encryption
{
    class EncryptionBase
    {
      public:
        explicit EncryptionBase(EncryptionType encryptionType);
        virtual ~EncryptionBase() = default;

        const EncryptionType &getEncryptionType();
        virtual std::string encryptContent(const std::string &content) {};
        virtual const std::string &getKey(){};
        virtual const std::string &getIv() {};
        virtual bool hasIv() {};
      private:
        EncryptionType m_encryptionType;

    };
}
