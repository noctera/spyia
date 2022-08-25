#pragma once

#include <spyia/files/fileType.hpp>

#include <string>

namespace Spyia::File {
    class FileTypeBase {
      public:
        explicit FileTypeBase(FileType fileType);

        const FileType &getFileType();
        int getManipulableBitsCount() const;
      protected:
        int m_manipulableBitsCount = 0;
      private:
        const FileType m_fileType;
    };
}