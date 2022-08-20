#pragma once

#include <string>

#include <spyia/encryption/encryptionTypes.hpp>

namespace Spyia
{
    class EncryptionBase
    {
      protected:
        explicit EncryptionBase(EncryptionType encryptionType);
      public:
        const EncryptionType &getEncryptionType();
        virtual std::string encryptContent(const std::string &content);
      private:
        EncryptionType m_encryptionType;
    };
}
