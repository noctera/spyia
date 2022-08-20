#include <spyia/encryption/encryptionBase.hpp>

using namespace Spyia;

EncryptionBase::EncryptionBase(EncryptionType encryptionType)
    : m_encryptionType(encryptionType) {}

const EncryptionType& EncryptionBase::getEncryptionType()
{
    return m_encryptionType;
}