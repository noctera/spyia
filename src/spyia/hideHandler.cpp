#include <spyia/hideHandler.hpp>
#include <spyia/encryption/none.hpp>
#include <spyia/utils/utils.hpp>
#include <spyia/utils/conversions.hpp>

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
    generateFullHeaders();
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
    // get size of secret file part to store the length of it in the header
    std::vector<std::string> secretFilePartsSize = divideString(m_secretFile.getByteCode(), m_fileStorage.size());


    for(std::size_t i = 0; i < fileAmount; ++i) {
        fileHeaders.push_back(std::get<1>(m_fileStorage.at(i))->generateHeader(i + 1, fileAmount, secretFilePartsSize.at(i).length(), m_secretFile.getFileType(), m_secretFile.getEncryptionAlgo(), iv));
    }

    return fileHeaders;
}

void HideHandler::generateFullHeaders()
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
        std::string header = fileHeaders.at(i);
        header = m_headerEncryption->encryptContent(fileHeaders.at(i));
        std::string fullHeader = std::to_string(header.length()) + "-" + encryptionTypeToString(m_headerEncryption->getEncryptionType()) + ":" + iv + "###" + header;
        tempFullHeaders.push_back(Conversion::textToBin(fullHeader));
    }
    m_headers = tempFullHeaders;
}

unsigned long HideHandler::getMaxStorableBits() const
{
    unsigned long storableBits = 0;
    for(std::size_t i = 0; i < m_fileStorage.size(); ++i) {
        // subtract bits needed by header
        storableBits += (std::get<2>(m_fileStorage.at(i)) - m_headers.at(i).length() * 8);
    }
    return storableBits;
}

unsigned long HideHandler::getMaxStorableBitsForFile(std::size_t index) const
{
    return std::get<2>(m_fileStorage.at(index)) - m_headers.at(index).length();
}

void HideHandler::hide()
{
    std::cout << "SecretFileSize: " << m_secretFile.getByteCode().length() << std::endl;

    // divide SecretFile into n parts
    std::vector<std::string> secretParts = divideString(m_secretFile.getByteCode(), m_fileStorage.size());

    // check if any secretFilePath is too big for an output file
    for(auto &secretPart : secretParts) {
        std::cout << "Size: " << secretPart.length() << std::endl;
    }

    // just check for secret part size, as header size has already been subtracted
    for(std::size_t i = 0; i < secretParts.size(); ++i) {
        if(secretParts.at(i).length() > getMaxStorableBitsForFile(i)) {
            throw std::overflow_error("Secret part is too big for file " + std::to_string(i) + ". Please add another one");
        }
    }

    for(std::size_t i = 0; i < m_fileStorage.size(); ++i) {
        std::cout << "File "  << i << std::endl;
        // generate header positions
        std::vector<int> headerPositions = generateNumbersBySeed(m_headerEncryption->getKey(), m_headers.at(i).length(), 0, getMaxStorableBitsForFile(i));

        // hide header
        std::get<1>(m_fileStorage.at(i))->hideHeader(*(std::get<0>(m_fileStorage.at(i))), m_headers.at(i), headerPositions);

        // hide secret file while taking care of the reserved bits
        std::get<1>(m_fileStorage.at(i))->hideSecret(*(std::get<0>(m_fileStorage.at(i))), secretParts.at(i), headerPositions);
    }
    std::cout << "finished" << std::endl;
}