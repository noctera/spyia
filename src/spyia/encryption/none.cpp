#include <spyia/encryption/none.hpp>
#include <stdexcept>

using namespace Spyia::Encryption;

None::None() : EncryptionBase(EncryptionType::NONE) {}

std::string None::encryptContent(const std::string& content)
{
    throw std::invalid_argument("No encryption method set");
}