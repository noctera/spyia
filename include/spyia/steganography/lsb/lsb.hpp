#pragma once

#include <string>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>

#include <spyia/steganography/stegAlgoBase.hpp>
#include <spyia/encryption/encryptionType.hpp>
#include <spyia/files/fileType.hpp>

namespace Spyia::Steganography
{
    class Lsb : public StegAlgoBase
    {
      public:
        Lsb();
        std::string generateHeader(int position, int maxFiles, File::FileType fileType, Spyia::Encryption::EncryptionType encryptionType, const std::string &iv) const override;
        void hide(cv::Mat img);
    };
}