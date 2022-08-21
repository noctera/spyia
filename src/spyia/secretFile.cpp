#include <spyia/secretFile.hpp>
#include <spyia/encryption/none.hpp>
#include <spyia/encryption/encryptionTypes.hpp>

#include <iostream>

using namespace Spyia;
    SecretFile::SecretFile(FileType::FileTypeBase& file, Encryption::EncryptionBase& encryption)
        : m_file(file), m_encryption(encryption) {}

    std::string SecretFile::getContent() const {
        return m_file.getBinaryContent();
    }

    const std::string& SecretFile::getEncryptedContent() const {
        if(m_encryption.getEncryptionType() == Encryption::EncryptionType::NONE) {
            throw std::invalid_argument("No encryption method set");
        }
        else if(m_encryptedContent.empty()) {
            throw std::invalid_argument("You have to encrypt your file first");
        }
        return m_encryptedContent;
    }

    void SecretFile::encrypt() {
        m_encryptedContent = m_encryption.encryptContent(m_file.getBinaryContent());
    }