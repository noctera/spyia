#include <spyia/outputStorage.hpp>

#include <fstream>
#include <iostream>
#include <bitset>

namespace Spyia
{
    void OutputStorage::addImage(const Spyia::FileType::Image &image, const Spyia::StegTypes stegType, int prop)
    {
        m_imageStorage.emplace_back(image, stegType, prop);
    }
}