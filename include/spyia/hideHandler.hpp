#pragma once

#include <string>
#include <vector>
#include <utility>
#include <tuple>
#include <memory>
#include <spyia/steganography/stegAlgoBase.hpp>
#include <spyia/files/fileTypeBase.hpp>
#include <spyia/secretFile.hpp>

namespace Spyia
{
    class HideHandler
    {
      public:
        HideHandler(SecretFile &sf, std::unique_ptr<Encryption::EncryptionBase> encryption);

        void addFile(std::unique_ptr<File::FileTypeBase> file, std::unique_ptr<Steganography::StegAlgoBase> stegAlgo);

        std::size_t getMaxStorableBits() const;
        void generateHeaders();
        void hide();
      private:

        std::vector<std::string> getFileHeaders() const;

        const SecretFile &m_secretFile;
        // tuple <file, stegAlgo, how many bits you can store>
        std::vector<std::tuple<std::unique_ptr<File::FileTypeBase>, std::unique_ptr<Steganography::StegAlgoBase>, unsigned long>> m_fileStorage;
        std::unique_ptr<Encryption::EncryptionBase> m_headerEncryption;
        std::vector<std::string> headers;
    };
}