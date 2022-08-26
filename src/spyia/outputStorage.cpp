#include <spyia/outputStorage.hpp>

using namespace Spyia;

void OutputStorage::addFile(std::unique_ptr<File::FileTypeBase> file, std::unique_ptr<Steganography::StegAlgoBase> stegAlgo)
{
    // calculate how many bits can be stored per file and steganography algorithm
    int maxBits = file->getManipulableBitsCount() / stegAlgo->getBitStorageDivider();
    m_fileStorage.emplace_back(std::move(file), std::move(stegAlgo), maxBits);
}

std::size_t OutputStorage::getOutputFileCount() const
{
    return m_fileStorage.size();
}

std::vector<std::string> OutputStorage::getFileHeaders() const
{
    std::vector<std::string> fileHeaders;
    int fileAmount = m_fileStorage.size();
    for(std::size_t i = 0; i < fileAmount; ++i) {
        fileHeaders.emplace_back(std::get<1>(m_fileStorage[i])->generateHeader(i + 1, fileAmount));
    }
}