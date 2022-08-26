#pragma once

#include <string>
#include <vector>
#include <utility>
#include <memory>

#include <spyia/secretFile.hpp>
#include <spyia/outputStorage.hpp>

namespace Spyia
{
    class StegHandler
    {
      public:
        StegHandler(SecretFile &sf, OutputStorage &os, std::unique_ptr<Encryption::EncryptionBase> encryption);
        StegHandler(SecretFile &sf, OutputStorage &os);
        void generateHeaders();
        void hide();
      private:
        const SecretFile &m_secretFile;
        OutputStorage &m_outputStorage;
        std::unique_ptr<Encryption::EncryptionBase> m_encryption;
        std::vector<std::string> headers;
    };
}