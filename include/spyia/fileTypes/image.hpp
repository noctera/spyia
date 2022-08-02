#pragma once

#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>

namespace Spyia::FileType
{
    class Image
    {
        public:
        Image(const std::string &imgPath);
        void printFile() const;

        private:
        cv::Mat m_image;
        // maximum number of image bits that can be manipulated
        const int m_maxImgBits = 0;
        // bits needed if you want to hide this image
        const int m_neededBits = 0;
    };
}