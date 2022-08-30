#pragma once

#include <string>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>

#include <spyia/steganography/stegType.hpp>
#include <spyia/encryption/encryptionType.hpp>
#include <spyia/files/fileType.hpp>

namespace Spyia::Steganography
{
    class StegAlgoBase
    {
      public:
        explicit StegAlgoBase(StegType stegType, int bitStorageDivider);
        const StegType &getStegAlgoType();
        int getBitStorageDivider() const;
        virtual std::string generateHeader(int position, int maxFiles, File::FileType fileType, Encryption::EncryptionType encryptionType, const std::string &iv) const {};

        // hide header
        virtual void hideHeader(cv::Mat &img, const std::string &header, const std::vector<int> &positions) {};
        // hide information
        virtual void hide(const cv::Mat &img) {};
      private:
        StegType m_stegType;
        int m_bitStorageDivider = 0;
    };
}
