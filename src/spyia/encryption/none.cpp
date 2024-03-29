#include <spyia/encryption/none.hpp>
#include <stdexcept>

using namespace Spyia::Encryption;

None::None() : EncryptionBase(EncryptionType::NONE) {}

bool None::hasIv()
{
    return false;
}

std::string None::encryptContent(const std::string& content)
{
    // if no encryption algorithm is set, return the content unencrypted
    return content;
}