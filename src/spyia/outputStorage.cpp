#include <spyia/outputStorage.hpp>

using namespace Spyia;

void OutputStorage::addFile(std::unique_ptr<File::FileTypeBase> file, std::unique_ptr<Steganography::StegAlgoBase> stegAlgo)
{
    fileStorage.emplace_back(std::move(file), std::move(stegAlgo));
}