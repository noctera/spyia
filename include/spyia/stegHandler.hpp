#pragma once

#include <string>
#include <vector>
#include <spyia/secretFile.hpp>
#include <spyia/outputStorage.hpp>
#include <spyia/fileTypes/image.hpp>
#include <spyia/utils/encryption/encryptionTypes.hpp>
#include <spyia/steganography/stegTypes.hpp>

namespace Spyia
{
    class StegHandler
    {
      public:
        explicit StegHandler(std::string outputPath);
        StegHandler(std::string outputPath, Spyia::SecretFile secretFile, Spyia::OutputStorage outputStorage);

        void addSecretFile(const Spyia::SecretFile &secretFile);

        // void addOutputFile(Spyia::FileType::Image &image, const Spyia::StegTypes &stegType);
        // void hide();

      private:
        const std::string m_outputPath;
        Spyia::SecretFile m_secretFile;
        Spyia::OutputStorage m_outputStorage;
    };
}