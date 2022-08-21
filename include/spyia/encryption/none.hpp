#pragma once

#include <string>

#include <spyia/encryption/encryptionBase.hpp>

namespace Spyia::Encryption
{
    class None: public EncryptionBase
    {
      public:
        None();
        std::string encryptContent(const std::string &content) override;
    };
}