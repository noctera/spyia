#pragma once

#include <spyia/files/fileTypeBase.hpp>
#include <spyia/files/fileType.hpp>

#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>

namespace Spyia::File
{
    class Image: public FileTypeBase
    {
        public:
        Image(const std::string &imgPath, const FileType &fileType);

        const std::string &getBinaryContent() const override;

        private:
        cv::Mat m_image;
        std::string m_binaryContent;

    };
}