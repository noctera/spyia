#pragma once

#include <string>


#include <spyia/steganography/stegType.hpp>

namespace Spyia::Steganography
{
    class StegAlgoBase
    {
      public:
        explicit StegAlgoBase(StegType stegType, unsigned long bitStorageDivider);
        const StegType &getStegAlgoType();
        unsigned long getBitStorageDivider() const;
      private:
        StegType m_stegType;
        unsigned long m_bitStorageDivider = 0;
    };
}
