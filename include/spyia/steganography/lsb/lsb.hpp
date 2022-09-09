#pragma once

#include <string>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>

#include <spyia/steganography/stegAlgoBase.hpp>
#include <spyia/encryption/encryptionType.hpp>
#include <spyia/files/fileType.hpp>
#include <spyia/files/fileTypeBase.hpp>

namespace Spyia::Steganography
{
    class Lsb : public StegAlgoBase
    {
      public:
        Lsb();
        std::string generateHeader(int position, int maxFiles, int storedBits, File::FileType fileType, Spyia::Encryption::EncryptionType encryptionType, const std::string &iv) const override;

        void hideHeader(File::FileTypeBase& file, const std::string &header, const std::vector<int> &positions) override;

        void hideSecret(File::FileTypeBase& file, const std::string& secret, const std::vector<int> &reservedBits) override;
    };
}