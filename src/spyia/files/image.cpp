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

        std::ifstream ifs(imgPath, std::ios::binary);
        if(!ifs)
        {
            throw std::invalid_argument("Could not open secret file");
        }
        m_binaryContent.assign((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

        m_contentBitsCount = m_binaryContent.length() * 8;
    }

    const std::string& Image::getBinaryContent() const
    {
        return m_binaryContent;
    }
}