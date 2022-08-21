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
          SecretFile(FileType::FileTypeBase& file);
          SecretFile(FileType::FileTypeBase& file, Encryption::EncryptionBase& encryption);

          std::string getContent() const;
          const std::string& getEncryptedContent() const;

          // encryption methods
          void encrypt();

        private:
          FileType::FileTypeBase &m_file;
          Encryption::EncryptionBase &m_encryption;

          std::string m_encryptedContent;
    };
}