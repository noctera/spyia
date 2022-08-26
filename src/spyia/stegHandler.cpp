#include <spyia/stegHandler.hpp>

using namespace Spyia;

StegHandler::StegHandler(const SecretFile &sf, const OutputStorage &os, std::unique_ptr<Encryption::EncryptionBase> encryption)
    : m_secretFile(sf), m_outputStorage(os), m_encryption(std::move(encryption)) {}

void StegHandler::generateHeaders()
{
    unsigned long bitsPerFile = m_secretFile.getNeededBits() / m_outputStorage.getOutputFileCount();
    // generate individual headers for files in outputStorage
    std::vector<std::string> fileHeaders = m_outputStorage.getFileHeader(bitsPerFile);
    bool usedIV = m_secretFile.hasUsedIV();
    std::string iv;
    if(usedIV) {
        iv = m_secretFile.getEncryptionIV();
    }
    for(std::size_t i = 1; i <= m_outputStorage.getOutputFileCount(); ++i) {
        // std::string header = .generateHeader(i, m_outputStorage.getFileCount(); bitsPerFile);
        std::string fullHeader = "dfjdskfsj";// std::to_string(headers.size()) + "###";
    }
}

void StegHandler::hide()
{

}