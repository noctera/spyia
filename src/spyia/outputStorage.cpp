#include <spyia/outputStorage.hpp>

using namespace Spyia;

void OutputStorage::addFile(std::unique_ptr<File::FileTypeBase> file, std::unique_ptr<Steganography::StegAlgoBase> stegAlgo)
{
    // calculate how many bits can be stored per file and steganography algorithm
    unsigned long maxBits = file->getContentBitsCount() / stegAlgo->getBitStorageDivider();
    m_fileStorage.emplace_back(std::move(file), std::move(stegAlgo), maxBits);
}

std::size_t OutputStorage::getOutputFileCount() const
{
    return m_fileStorage.size();
}

std::size_t OutputStorage::getMaxStorableBits() const
{
    std::size_t tempCount = 0;
    for(const auto & it : m_fileStorage) {
        tempCount += std::get<2>(it);
    }

    return tempCount;
}