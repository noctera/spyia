#pragma once

#include <string>


#include <spyia/steganography/stegType.hpp>
#include <spyia/encryption/encryptionType.hpp>

namespace Spyia::Steganography
{
    class StegAlgoBase
    {
      public:
        explicit StegAlgoBase(StegType stegType, int bitStorageDivider);
        const StegType &getStegAlgoType();
        int getBitStorageDivider() const;
        virtual std::string generateHeader(int position, int maxFiles, Encryption::EncryptionType encryptionType, const std::string &iv) const {};
      private:
        StegType m_stegType;
        int m_bitStorageDivider = 0;
    };
}
