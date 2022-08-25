#include <spyia/files/image.hpp>
#include <spyia/files/fileType.hpp>
#include <iostream>

namespace Spyia::File
{
    Image::Image(const std::string &imgPath, const FileType &fileType)
        : FileTypeBase(fileType), m_image(cv::imread(imgPath)) {
        if(m_image.empty()) {
            throw std::invalid_argument("Could not open image");
        }

        // check how many bits can be manipulated in general
        // Image: RGB Channel -> 3 (255, 255, 255) -> (11111111, 11111111, 11111111) -> RGB Channel * 8
        m_manipulableBitsCount = (m_image.rows * m_image.cols * m_image.channels()) * 8;
    }
}