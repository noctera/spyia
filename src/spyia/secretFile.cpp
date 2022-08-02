#include <spyia/secretFile.hpp>
#include <spyia/utils/encryption/aes.hpp>

#include <fstream>
#include <iostream>
#include <bitset>

namespace Spyia
{
    SecretFile::SecretFile(const std::string &filePath) {
        std::ifstream ifs(filePath, std::ios::binary);
        if(!ifs) {
            throw std::invalid_argument("Could not open secret file");
        }
        m_content.assign((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    }

    const std::string& SecretFile::getContent() const {
        return m_encryptedContent;
    }

    void SecretFile::print() const {
        std::cout << m_content << std::endl;
        int size = 0;
        for (std::size_t i = 0; i < m_content.size(); ++i)
        {
            size += 8;
        }
        std::cout << size << std::endl;
    }

    void SecretFile::encrypt_aes_cbc() {
        const auto [encoded, iv] = aes_cbc_encrypt(m_content, "dasisteintest123");
        m_encryptedContent = encoded;
        m_iv = iv;
    }
}