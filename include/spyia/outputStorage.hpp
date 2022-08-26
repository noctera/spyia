#pragma once

#include <string>
#include <vector>
#include <utility>
#include <tuple>
#include <memory>
#include <spyia/steganography/stegAlgoBase.hpp>
#include <spyia/files/fileTypeBase.hpp>

namespace Spyia
{
    class OutputStorage
    {
      public:
        void addFile(std::unique_ptr<File::FileTypeBase> file, std::unique_ptr<Steganography::StegAlgoBase> stegAlgo);
        std::size_t getOutputFileCount() const;
        std::vector<std::string> getFileHeaders() const;
      private:
        // tuple <file, stegAlgo, how many bits you can store>
        std::vector<std::tuple<std::unique_ptr<File::FileTypeBase>, std::unique_ptr<Steganography::StegAlgoBase>, unsigned long>> m_fileStorage;
    };
}