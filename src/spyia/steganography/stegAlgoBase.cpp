#include <spyia/steganography/stegAlgoBase.hpp>

using namespace Spyia::Steganography;

StegAlgoBase::StegAlgoBase(StegType stegType, unsigned long bitStorageDivider)
    : m_stegType(stegType), m_bitStorageDivider(bitStorageDivider) {}

const StegType& StegAlgoBase::getStegAlgoType()
{
    return m_stegType;
}

unsigned long StegAlgoBase::getBitStorageDivider() const
{
    return m_bitStorageDivider;
}
