#include <spyia/files/image.hpp>
#include <spyia/files/fileType.hpp>
#include <spyia/utils/utils.hpp>
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

    void Image::manipulate(int position, int bitPosition, char value)
    {
        // calculate position in image (took me way too much time)
        int col = position / (m_image.rows * 3);
        int row = (position % (m_image.rows * 3)) / 3;
        int channel = position % 3;

        auto& intensity = m_image.at<cv::Vec3b>(col, row);
        manipulateByte(intensity.val[channel], bitPosition, value);
    }
}