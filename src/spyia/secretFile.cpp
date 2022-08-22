#include <spyia/secretFile.hpp>
#include <spyia/encryption/none.hpp>
#include <spyia/encryption/encryptionTypes.hpp>

#include <iostream>

using namespace Spyia;

SecretFile::SecretFile(std::unique_ptr<FileType::FileTypeBase> file, std::unique_ptr<Encryption::EncryptionBase> encryption)
        : m_file(std::move(file)), m_encryption(std::move(encryption)) {}

SecretFile::SecretFile(std::unique_ptr<FileType::FileTypeBase> file)
        : m_file(std::move(file)), m_encryption(std::make_unique<Encryption::EncryptionBase>(Encryption::None())) {}

std::string SecretFile::getContent() const {
    return m_file->getBinaryContent();
}

const std::string& SecretFile::getEncryptedContent() const {
    if(m_encryption->getEncryptionType() == Encryption::EncryptionType::NONE) {
        throw std::invalid_argument("No encryption method set");
    }
    else if(m_encryptedContent.empty()) {
        throw std::invalid_argument("You have to encrypt your file first");
    }
    return m_encryptedContent;
}

void SecretFile::setFile(std::unique_ptr<FileType::FileTypeBase> file)
{
    m_file = std::move(file);
}

void SecretFile::setEncryption(std::unique_ptr<Encryption::EncryptionBase> encryption)
{
    m_encryption = std::move(encryption);
}

bool SecretFile::isEncrypted() const
{
    return m_encryption->getEncryptionType() != Encryption::EncryptionType::NONE;
}

void SecretFile::encrypt() {
    m_encryptedContent = m_encryption->encryptContent(m_file->getBinaryContent());
}