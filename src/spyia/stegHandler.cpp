#include <spyia/stegHandler.hpp>
#include <iostream>
#include <utility>

namespace Spyia
{
    StegHandler::StegHandler(std::string outputPath) : m_outputPath(std::move(outputPath)){}
    StegHandler::StegHandler(std::string  outputPath, Spyia::SecretFile  secretFile, Spyia::OutputStorage  outputStorage)
        : m_outputPath(std::move(outputPath)), m_secretFile(std::move(secretFile)), m_outputStorage(std::move(outputStorage)) {}

    void StegHandler::addSecretFile(const Spyia::SecretFile &secretFile) {
        m_secretFile = secretFile;
        secretFile.getContent();
    }
}