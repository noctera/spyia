#pragma once

#include <spyia/files/fileTypeBase.hpp>
#include <spyia/files/fileTypes.hpp>

#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>

namespace Spyia::FileType
{
    class Image: public FileTypeBase
    {
        public:
        Image(const std::string &imgPath, const Spyia::FileTypes &fileType);

        const std::string &getBinaryContent() const override;

        private:
        cv::Mat m_image;
        std::string m_binaryContent;
        // maximum number of image bits that can be manipulated
        const int m_maxImgBits = 0;
        // bits needed if you want to hide this image
        const int m_neededBits = 0;
    };
}