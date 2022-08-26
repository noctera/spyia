#include <spyia/secretFile.hpp>
#include <spyia/encryption/none.hpp>
#include <spyia/encryption/encryptionType.hpp>
#include <spyia/utils/conversions.hpp>
#include <spyia/utils/fileOperations.hpp>

#include <iostream>
#include <fstream>

using namespace Spyia;

SecretFile::SecretFile(const std::string &filePath, File::FileType fileType)
    : m_fileType(fileType), m_encryption(std::make_unique<Encryption::EncryptionBase>(Encryption::None()))
{
    m_content.assign(fileToBinary(filePath));
}

SecretFile::SecretFile(const std::string &filePath, File::FileType fileType, std::unique_ptr<Encryption::EncryptionBase> encryption)
        : m_fileType(fileType), m_encryption(std::move(encryption))
{
    m_content.assign(fileToBinary(filePath));
}

std::string SecretFile::getByteCode() const
{
    // if no encryption is set, return blank content of file
    if(m_encryption->getEncryptionType() == Encryption::EncryptionType::NONE) {
        return Conversion::textToBin(m_content);
    }
    // if m_encryptionContent is empty encrypt with .encrypt() first
    else if(m_encryption->getEncryptionType() != Encryption::EncryptionType::NONE && m_encryptedContent.empty()) {
        throw std::invalid_argument("You have to encrypt your file first");
    }
    // if encryption is set, return encrypted content
    else {
        return Conversion::textToBin(m_encryptedContent);
    }

}

void SecretFile::setFile(const std::string &filePath)
{
    m_content.assign(fileToBinary(filePath));
}

void SecretFile::setEncryption(std::unique_ptr<Encryption::EncryptionBase> encryption)
{
    m_encryption = std::move(encryption);
}

bool SecretFile::isEncrypted() const
{
    return m_encryption->getEncryptionType() != Encryption::EncryptionType::NONE;
}

bool SecretFile::hasUsedIV() const
{
    return m_encryption->getEncryptionType() == Encryption::EncryptionType::AES_CBC;
}

unsigned long SecretFile::getNeededBits() const
{
    if(m_encryption->getEncryptionType() == Encryption::EncryptionType::NONE) {
        return m_content.length() * 8;
    }
    else {
        return m_encryptedContent.length() * 8;
    }
}

std::string SecretFile::getEncryptionKey() const
{
    return m_encryption->getKey();
}

std::string SecretFile::getEncryptionIV() const
{
    return m_encryption->getIv();
}

void SecretFile::encrypt() {
    m_encryptedContent = m_encryption->encryptContent(m_content);
}