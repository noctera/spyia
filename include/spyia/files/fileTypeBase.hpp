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

        virtual void manipulate(int position, int bitPosition, char value) {};

      protected:
        int m_manipulableBitsCount = 0;
      private:
        const FileType m_fileType;
    };
}