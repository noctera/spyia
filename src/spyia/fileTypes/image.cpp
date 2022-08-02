#include <spyia/fileTypes/image.hpp>
#include <spyia/fileTypes/fileTypes.hpp>

namespace Spyia::FileType
{
    Image::Image(const std::string &imgPath) : m_image(cv::imread(imgPath)), m_maxImgBits(m_image.rows * m_image.cols * m_image.channels()) {
        if(m_image.empty()) {
            throw std::invalid_argument("Could not open image");
        }
    }

    void Image::printFile() const {

    }
}