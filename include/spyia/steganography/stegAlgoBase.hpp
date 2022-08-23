#pragma once

#include <string>


#include <spyia/steganography/stegType.hpp>

namespace Spyia::Steganography
{
    class StegAlgoBase
    {
      public:
        explicit StegAlgoBase(StegType stegType);
        const StegType &getStegAlgoType();

      protected:
        StegType m_stegType;

    };
}
