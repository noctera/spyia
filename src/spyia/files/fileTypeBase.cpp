#include <spyia/files/fileTypeBase.hpp>

using namespace Spyia;
using namespace Spyia::FileType;

FileTypeBase::FileTypeBase(FileTypes fileType)
    : m_fileType(fileType) {}

const FileTypes& FileTypeBase::getFileType()
{
    return m_fileType;
}
