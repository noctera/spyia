#pragma once

#include <spyia/files/fileTypes.hpp>

#include <string>

namespace Spyia::FileType {
    class FileTypeBase {
      public:
        explicit FileTypeBase(FileTypes fileType);

        const FileTypes &getFileType();
        virtual const std::string& getBinaryContent() const {};
      protected:
        const FileTypes m_fileType;
    };
}