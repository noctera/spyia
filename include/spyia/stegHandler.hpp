#pragma once

#include <string>
#include <vector>
#include <spyia/secretFile.hpp>
#include <spyia/fileTypes/image.hpp>
#include <spyia/utils/encryption/encryptionTypes.hpp>
#include <spyia/steganography/stegTypes.hpp>

namespace Spyia
{
    class StegHandler
    {
      public:
        StegHandler(const std::string &outputPath);

        void addSecretFile(const Spyia::SecretFile &secretFile);

        void addOutputFile(Spyia::FileType::Image &image, const Spyia::StegTypes &stegType);

        // encryption methods
        void encrypt_aes_cbc();

        void hide();

      private:
        const std::string m_outputPath;
        Spyia::SecretFile m_secretFile;
        std::vector<Spyia::FileType::Image> m_outputFileStorage;
        Spyia::EncryptionType m_encryptionType;
    };
}