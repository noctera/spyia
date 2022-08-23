#pragma once

#include <string>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>

#include <spyia/steganography/stegAlgoBase.hpp>

namespace Spyia::Steganography
{
    class Lsb : public StegAlgoBase
    {
      public:
        Lsb();
        void hide(cv::Mat img);
    };
}