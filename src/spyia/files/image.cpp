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
        int tempPosition = 0;
        for (int i = 0; i < m_image.rows; i++) {
            // if number of needed pixels is reached stop iterating
            for (int j = 0; j < m_image.cols; j++) {
                // fetch RGB values of pixel
                cv::Vec3b& intensity = m_image.at<cv::Vec3b>(i, j);
                for (int k = 0; k < m_image.channels(); k++) {
                    if(tempPosition == position)
                    {
                        manipulateByte(intensity.val[k], bitPosition, value);
                    }
                    ++tempPosition;
                }
            }
        }
    }
}