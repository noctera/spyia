#pragma once

#include <string>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>

#include <spyia/steganography/stegType.hpp>
#include <spyia/encryption/encryptionType.hpp>
#include <spyia/files/fileType.hpp>
#include <spyia/files/fileTypeBase.hpp>

namespace Spyia::Steganography
{
    class StegAlgoBase
    {
      public:
        explicit StegAlgoBase(StegType stegType, int bitStorageDivider);
        const StegType &getStegAlgoType();
        int getBitStorageDivider() const;
        virtual std::string generateHeader(int position, int maxFiles, int storedBits, File::FileType fileType, Encryption::EncryptionType encryptionType, const std::string &iv) const {};

        // hide header
        virtual void hideHeader(File::FileTypeBase& file, const std::string &header, const std::vector<int> &positions) {};
        // hide information
        virtual void hideSecret(File::FileTypeBase& file, const std::string& secret, const std::vector<int> &reservedBits) {};
      private:
        StegType m_stegType;
        int m_bitStorageDivider = 0;
    };
}
