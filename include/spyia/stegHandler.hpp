#pragma once

#include <string>
#include <vector>
#include <utility>
#include <memory>

#include <spyia/secretFile.hpp>
#include <spyia/outputStorage.hpp>

namespace Spyia
{
    class StegHandler
    {
      public:
        StegHandler(const SecretFile &sf, const OutputStorage &os);
      private:

        const SecretFile &m_secretFile;
        const OutputStorage &m_outputStorage;

    };
}