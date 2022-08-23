#include <spyia/steganography/stegAlgoBase.hpp>

using namespace Spyia::Steganography;

StegAlgoBase::StegAlgoBase(StegType stegType)
{
    m_stegType = stegType;
}

const StegType& StegAlgoBase::getStegAlgoType()
{
    return m_stegType;
}