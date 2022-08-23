#pragma once

#include <spyia/files/fileType.hpp>

#include <string>

namespace Spyia::File {
    class FileTypeBase {
      public:
        explicit FileTypeBase(FileType fileType);

        const FileType &getFileType();
        virtual const std::string& getBinaryContent() const {};
        int getFileBits();
      protected:
        const FileType m_fileType;
        // number of bits that file needs if it is stored somewhere
        int m_fileBits = 0;
    };
}