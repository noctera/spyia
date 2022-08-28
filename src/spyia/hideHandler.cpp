#include <spyia/hideHandler.hpp>
#include <spyia/encryption/none.hpp>
#include <spyia/utils/utils.hpp>

#include <iostream>

using namespace Spyia;

HideHandler::HideHandler(SecretFile& sf, std::unique_ptr<Encryption::EncryptionBase> encryption)
    : m_secretFile(sf), m_headerEncryption(std::move(encryption)) {}

void HideHandler::addFile(std::unique_ptr<File::FileTypeBase> file, std::unique_ptr<Steganography::StegAlgoBase> stegAlgo)
{
    // calculate how many bits can be stored per file and steganography algorithm
    int maxBits = file->getManipulableBitsCount() / stegAlgo->getBitStorageDivider();
    m_fileStorage.emplace_back(std::move(file), std::move(stegAlgo), maxBits);
}

// get individual headers from each output file which can be encrypted later
std::vector<std::string> HideHandler::getFileHeaders() const
{
    std::vector<std::string> fileHeaders;
    int fileAmount = m_fileStorage.size();

    // check if IV was used for file
    std::string iv = "x";
    if(m_secretFile.hasUsedIV()) {
        iv = m_secretFile.getEncryptionIV();
    }


    for(std::size_t i = 0; i < fileAmount; ++i) {
        fileHeaders.emplace_back(std::get<1>(m_fileStorage[i])->generateHeader(i + 1, fileAmount, m_secretFile.getFileType(), m_secretFile.getEncryptionAlgo(), iv));
    }

    return fileHeaders;
}

void HideHandler::generateHeaders()
{
    // generate individual headers for files in outputStorage
    std::vector<std::string> fileHeaders = getFileHeaders();

    // generate unencrypted header front and append encrypted header to it
    for(std::size_t i = 0; i < m_fileStorage.size(); ++i) {
        // check if IV was used for file
        std::string iv = "x";
        if(m_headerEncryption->hasIv()) {
            iv = m_headerEncryption->getIv();
        }

        // encrypt headers if header encryption method was set
        std::string header = fileHeaders[i];
        if(m_headerEncryption->getEncryptionType() != Encryption::EncryptionType::NONE) {
            header = m_headerEncryption->encryptContent(fileHeaders[i]);
        }
        std::string fullHeader = std::to_string(header.length()) + "-" + encryptionTypeToString(m_headerEncryption->getEncryptionType()) + ":" + iv + "###" + header;
        headers.emplace_back(fullHeader);
    }
}

std::size_t HideHandler::getMaxStorableBits() const
{

}

void HideHandler::hide()
{

}