#include <spyia/hideHandler.hpp>
#include <spyia/encryption/none.hpp>
#include <spyia/utils/utils.hpp>

#include <iostream>

using namespace Spyia;

HideHandler::HideHandler(const std::string &outputPath, SecretFile& sf, std::unique_ptr<Encryption::EncryptionBase> encryption)
    : m_outputPath(outputPath), m_secretFile(sf), m_headerEncryption(std::move(encryption))
{
    if(m_headerEncryption->getEncryptionType() == Encryption::EncryptionType::NONE) {
        throw std::invalid_argument("header has to be encrypted");
    }
}

void HideHandler::addFile(std::unique_ptr<File::FileTypeBase> file, std::unique_ptr<Steganography::StegAlgoBase> stegAlgo)
{
    // calculate how many bits can be stored per file and steganography algorithm
    int maxBits = file->getManipulableBitsCount() / stegAlgo->getBitStorageDivider();
    m_fileStorage.emplace_back(std::move(file), std::move(stegAlgo), maxBits);

    // regenerate all headers
    generateHeaders();
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
    std::vector<std::string> tempFullHeaders;
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
        header = m_headerEncryption->encryptContent(fileHeaders[i]);
        std::string fullHeader = std::to_string(header.length()) + "-" + encryptionTypeToString(m_headerEncryption->getEncryptionType()) + ":" + iv + "###" + header;
        tempFullHeaders.emplace_back(fullHeader);
    }
    m_headers = tempFullHeaders;
}

unsigned long HideHandler::getMaxStorableBits() const
{
    unsigned long storableBits = 0;
    for(std::size_t i = 0; i < m_fileStorage.size(); ++i) {
        // subtract bits needed by header
        storableBits += (std::get<2>(m_fileStorage[i]) - m_headers[i].length() * 8);
    }
    return storableBits;
}

unsigned long HideHandler::getMaxStorableBitsForFile(std::size_t index) const
{
    return std::get<2>(m_fileStorage[index]) - m_headers[index].length() * 8;
}

void HideHandler::hide()
{
    // divide SecretFile into n parts
    divideString(m_secretFile.getByteCode(), m_fileStorage.size());

    for(std::size_t i = 0; i < m_fileStorage.size(); ++i) {
        // generate header positions
        std::vector<int> headerPositions = generateNumbersBySeed(m_headerEncryption->getKey(), m_headers[i].length() * 8, 0, getMaxStorableBitsForFile(i));

        // hide header
        std::get<0>(m_fileStorage[i])->hideHeader(m_headers[i], headerPositions);

        // hide SecretFile part in file while watching out for the reserved bits of header

    }


}