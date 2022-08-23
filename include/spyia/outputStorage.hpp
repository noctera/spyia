#pragma once

#include <string>
#include <vector>
#include <utility>
#include <memory>
#include <spyia/steganography/stegAlgoBase.hpp>
#include <spyia/files/fileTypeBase.hpp>

namespace Spyia
{
    class OutputStorage
    {
      public:
        void addFile(std::unique_ptr<File::FileTypeBase> file, std::unique_ptr<Steganography::StegAlgoBase> stegAlgo);
      private:
        std::vector<std::pair<std::unique_ptr<File::FileTypeBase>, std::unique_ptr<Steganography::StegAlgoBase>>> fileStorage;
    };
}