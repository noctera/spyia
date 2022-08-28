#pragma once

#include <spyia/files/fileType.hpp>

#include <string>
#include <vector>

namespace Spyia::File {
    class FileTypeBase {
      public:
        explicit FileTypeBase(FileType fileType);

        const FileType &getFileType();
        int getManipulableBitsCount() const;
        virtual void hideHeader(std::string header, std::vector<int> positions) {};
      protected:
        int m_manipulableBitsCount = 0;
      private:
        const FileType m_fileType;
    };
}