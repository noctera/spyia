#pragma once

#include <string>
#include <vector>
#include <tuple>
#include <spyia/fileTypes/image.hpp>
#include <spyia/steganography/stegTypes.hpp>

namespace Spyia
{
    class OutputStorage
    {
      public:
        OutputStorage() = default;

        void addImage(const Spyia::FileType::Image &image, const Spyia::StegTypes stegType, int prop = 0);

      private:
        std::vector<std::tuple<Spyia::FileType::Image, Spyia::StegTypes, int>> m_imageStorage;
    };
}