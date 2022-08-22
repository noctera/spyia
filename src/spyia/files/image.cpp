#include <spyia/files/image.hpp>
#include <spyia/files/fileType.hpp>
#include <iostream>

#include <fstream>

namespace Spyia::FileType
{
    Image::Image(const std::string &imgPath, const Spyia::FileTypes &fileType)
        : FileTypeBase(fileType), m_image(cv::imread(imgPath)), m_maxImgBits(m_image.rows * m_image.cols * m_image.channels()) {
        if(m_image.empty()) {
            throw std::invalid_argument("Could not open image");
        }

        std::ifstream ifs(imgPath, std::ios::binary);
        if(!ifs)
        {
            throw std::invalid_argument("Could not open secret file");
        }
        m_binaryContent.assign((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    }

    const std::string& Image::getBinaryContent() const
    {
        return m_binaryContent;
    }
}