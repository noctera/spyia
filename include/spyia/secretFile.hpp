#pragma once

#include <string>
#include <memory>
#include <spyia/encryption/encryptionBase.hpp>
#include <spyia/files/fileTypeBase.hpp>
#include <spyia/files/fileType.hpp>

namespace Spyia
{
    class SecretFile
    {
        public:
          SecretFile() = delete;
          SecretFile(const std::string &filePath, File::FileType fileType);
          SecretFile(const std::string &filePath, File::FileType fileType, std::unique_ptr<Encryption::EncryptionBase> encryption);

          std::string getByteCode() const;

          void setFile(const std::string &filePath);
          void setEncryption(std::unique_ptr<Encryption::EncryptionBase> encryption);

          bool isEncrypted() const;
          bool hasUsedIV() const;

          unsigned long getNeededBits() const;
          std::string getEncryptionKey() const;
          std::string getEncryptionIV() const;

          // encryption methods
          void encrypt();

        private:
          File::FileType m_fileType;
          std::unique_ptr<Encryption::EncryptionBase> m_encryption;

          std::string m_content;
          std::string m_encryptedContent;
    };
}