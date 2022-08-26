#include <spyia/stegHandler.hpp>
#include <spyia/encryption/none.hpp>

using namespace Spyia;

StegHandler::StegHandler(SecretFile &sf, OutputStorage &os, std::unique_ptr<Encryption::EncryptionBase> encryption)
    : m_secretFile(sf), m_outputStorage(os), m_encryption(std::move(encryption))
{
    // add SecretFile encryption type to OutputStorage in order to generate headers
    m_outputStorage.addSecretFileEncryptionMode(m_secretFile.getEncryptionMode());
}

StegHandler::StegHandler(SecretFile &sf, OutputStorage &os)
    : m_secretFile(sf), m_outputStorage(os), m_encryption(std::make_unique<Encryption::None>(Encryption::None()))
{
    // add SecretFile encryption type to OutputStorage in order to generate headers
}

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