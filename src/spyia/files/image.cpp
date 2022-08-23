#include <spyia/files/image.hpp>
#include <spyia/files/fileType.hpp>
#include <iostream>

#include <fstream>

namespace Spyia::File
{
    Image::Image(const std::string &imgPath, const FileType &fileType)
        : FileTypeBase(fileType), m_image(cv::imread(imgPath)) {
        if(m_image.empty()) {
            throw std::invalid_argument("Could not open image");
        }

        m_fileBits = (m_image.rows * m_image.cols * m_image.channels()) * 8;

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