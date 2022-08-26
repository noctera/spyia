#include <spyia/hideHandler.hpp>
#include <spyia/encryption/none.hpp>

using namespace Spyia;

HideHandler::HideHandler(SecretFile &sf)
    : m_secretFile(sf), m_headerEncryption(std::make_unique<Encryption::None>(Encryption::None())) {}

HideHandler::HideHandler(SecretFile& sf, std::unique_ptr<Encryption::EncryptionBase> encryption)
    : m_secretFile(sf), m_headerEncryption(std::move(encryption)) {}

void HideHandler::addFile(std::unique_ptr<File::FileTypeBase> file, std::unique_ptr<Steganography::StegAlgoBase> stegAlgo)
{
    // calculate how many bits can be stored per file and steganography algorithm
    int maxBits = file->getManipulableBitsCount() / stegAlgo->getBitStorageDivider();
    m_fileStorage.emplace_back(std::move(file), std::move(stegAlgo), maxBits);
}

std::size_t HideHandler::getOutputFileCount() const
{
    return m_fileStorage.size();
}

std::vector<std::string> HideHandler::getFileHeaders() const
{
    std::vector<std::string> fileHeaders;
    int fileAmount = m_fileStorage.size();
    for(std::size_t i = 0; i < fileAmount; ++i) {
        fileHeaders.emplace_back(std::get<1>(m_fileStorage[i])->generateHeader(i + 1, fileAmount));
    }
}

void HideHandler::generateHeaders()
{
    unsigned long bitsPerFile = m_secretFile.getNeededBits() / m_outputStorage.getOutputFileCount();
    // generate individual headers for files in outputStorage
    std::vector<std::string> fileHeaders = m_outputStorage.getFileHeaders();

    // push secret file encryption algorithm (and IV if available) to the front of the headers
    bool usedIV = m_secretFile.hasUsedIV();
    std::string iv;
    if(usedIV) {
        iv = m_secretFile.getEncryptionIV();
    }

    // encrypt headers if header encryption method was set

    // generate unencrypted header front and append encrypted header to it
    for(std::size_t i = 1; i <= m_outputStorage.getOutputFileCount(); ++i) {
        // std::string header = .generateHeader(i, m_outputStorage.getFileCount(); bitsPerFile);
        std::string fullHeader = "dfjdskfsj";// std::to_string(headers.size()) + "###";
    }
}

std::size_t HideHandler::getMaxStorableBits() const
{

}

void HideHandler::hide()
{

}