#include <spyia/files/fileTypeBase.hpp>

using namespace Spyia;
using namespace Spyia::File;

FileTypeBase::FileTypeBase(FileType fileType)
    : m_fileType(fileType) {}

const FileType& FileTypeBase::getFileType()
{
    return m_fileType;
}

unsigned long FileTypeBase::getContentBitsCount() const
{
    return m_contentBitsCount;
}
