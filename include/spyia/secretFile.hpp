#pragma once

#include <string>
#include <memory>
#include <spyia/encryption/encryptionBase.hpp>
#include <spyia/files/fileTypeBase.hpp>

namespace Spyia
{
    class SecretFile
    {
        public:
          SecretFile() = delete;
          SecretFile(std::unique_ptr<File::FileTypeBase> file);
          SecretFile(std::unique_ptr<File::FileTypeBase> file, std::unique_ptr<Encryption::EncryptionBase> encryption);

          std::string getByteCode() const;

          void setFile(std::unique_ptr<File::FileTypeBase> file);
          void setEncryption(std::unique_ptr<Encryption::EncryptionBase> encryption);

          bool isEncrypted() const;

          unsigned long getNeededBits() const;

          // encryption methods
          void encrypt();

        private:
          std::unique_ptr<File::FileTypeBase> m_file;
          std::unique_ptr<Encryption::EncryptionBase> m_encryption;

          std::string m_encryptedContent;
    };
}