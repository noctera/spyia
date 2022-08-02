#include <spyia/stegHandler.hpp>
#include <iostream>

namespace Spyia
{
    StegHandler::StegHandler(const std::string &outputPath) : m_outputPath(outputPath){}

    void StegHandler::addSecretFile(const Spyia::SecretFile &secretFile) {
        m_secretFile = secretFile;
        secretFile.getContent();
    }

    void StegHandler::encrypt_aes_cbc() {
        m_secretFile.encrypt_aes_cbc();
    }
}