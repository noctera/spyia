#pragma once

#include <string>
#include <spyia/utils/encryption/encryptionTypes.hpp>

namespace Spyia
{
    class SecretFile
    {
        public:
          SecretFile() = default;
          explicit SecretFile(const std::string& filePath);

          void print() const;
          const std::string& getContent() const;

          // encryption methods
          void encrypt_aes_cbc(const std::string &key);

        private:
          std::string m_content;
          std::string m_encryptedContent;
          std::string m_iv;
          Spyia::EncryptionType m_encryptionType;
    };
}