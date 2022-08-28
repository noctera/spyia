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
        HideHandler(const std::string &outputPath, SecretFile &sf, std::unique_ptr<Encryption::EncryptionBase> encryption);

        void addFile(std::unique_ptr<File::FileTypeBase> file, std::unique_ptr<Steganography::StegAlgoBase> stegAlgo);

        unsigned long getMaxStorableBits() const;
        unsigned long getMaxStorableBitsForFile(std::size_t index) const;

        void hide();
      private:
        std::vector<std::string> getFileHeaders() const;
        void generateHeaders();

        std::string m_outputPath;
        const SecretFile &m_secretFile;
        // tuple <file, stegAlgo, how many bits you can store>
        std::vector<std::tuple<std::unique_ptr<File::FileTypeBase>, std::unique_ptr<Steganography::StegAlgoBase>, unsigned long>> m_fileStorage;
        std::unique_ptr<Encryption::EncryptionBase> m_headerEncryption;
        std::vector<std::string> m_headers;
    };
}