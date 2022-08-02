#pragma once

#include <string>

namespace Spyia
{
    class SecretFile
    {
        public:
          SecretFile() = default;
          SecretFile(const std::string& filePath);

          void print() const;
          const std::string& getContent() const;

          // encryption methods
          void encrypt_aes_cbc();

        private:
          std::string m_content{""};
          std::string m_encryptedContent{""};
          std::string m_iv{""};
    };
}