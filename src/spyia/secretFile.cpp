#include <spyia/secretFile.hpp>
#include <spyia/encryption/none.hpp>
#include <spyia/encryption/encryptionType.hpp>
#include <spyia/utils/conversions.hpp>

#include <iostream>

using namespace Spyia;

SecretFile::SecretFile(std::unique_ptr<File::FileTypeBase> file, std::unique_ptr<Encryption::EncryptionBase> encryption)
        : m_file(std::move(file)), m_encryption(std::move(encryption)) {}

SecretFile::SecretFile(std::unique_ptr<File::FileTypeBase> file)
        : m_file(std::move(file)), m_encryption(std::make_unique<Encryption::EncryptionBase>(Encryption::None())) {}

std::string SecretFile::getByteCode() const
{
    // if no encryption is set, return blank content of file
    if(m_encryption->getEncryptionType() == Encryption::EncryptionType::NONE) {
        return Conversion::textToBin(m_file->getBinaryContent());
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

void SecretFile::setFile(std::unique_ptr<File::FileTypeBase> file)
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

unsigned long SecretFile::getNeededBits() const
{
    if(m_encryption->getEncryptionType() == Encryption::EncryptionType::NONE) {
        return m_file->getContentBitsCount();
    }
    else {
        return m_encryptedContent.length() * 8;
    }
}

void SecretFile::encrypt() {
    m_encryptedContent = m_encryption->encryptContent(m_file->getBinaryContent());
}