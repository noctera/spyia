#include <spyia/encryption/encryptionBase.hpp>

using namespace Spyia::Encryption;

EncryptionBase::EncryptionBase(EncryptionType encryptionType)
    : m_encryptionType(encryptionType) {}

const EncryptionType& EncryptionBase::getEncryptionType()
{
    return m_encryptionType;
}