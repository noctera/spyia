#include <spyia/steganography/lsb/lsb.hpp>
#include <spyia/steganography/stegType.hpp>
#include <spyia/utils/utils.hpp>
#include <iostream>

using namespace Spyia;
using namespace Spyia::Steganography;

Lsb::Lsb() : StegAlgoBase(StegType::LSB, 8){}

std::string Lsb::generateHeader(int position, int maxFiles, File::FileType fileType, Spyia::Encryption::EncryptionType encryptionType, const std::string &iv) const
{
    // header example: f:1/3-AESCBC:iv-LSB
    return "f:" + std::to_string(position) + "/" + std::to_string(maxFiles) + "-" + fileTypeToString(fileType) + "-" + encryptionTypeToString(encryptionType) + ":" + iv + "-LSB";
}

void Lsb::hideHeader(cv::Mat &img, const std::string &header, const std::vector<int> &positions)
{
    std::cout << "Hide Header: ";
    for (auto &i : positions) {
        std::cout << i << " ";
    }

    int bitPosition = 0;
    int headerBitsStored = 0;

    std::cout << "Hide Header: ";

    // iterate over image pixels
    for (int i = 0; i < img.rows; i++) {
        // if number of needed pixels is reached stop iterating
        if (headerBitsStored >= header.size()) {
            break;
        }
        for (int j = 0; j < img.cols; j++) {
            // if number of needed pixels is reached stop iterating
            if (headerBitsStored >= header.size()) {
                break;
            }
            // fetch RGB values of pixel
            cv::Vec3b& intensity = img.at<cv::Vec3b>(i, j);
            for (int k = 0; k < img.channels(); k++) {
                if (headerBitsStored >= header.size()) {
                    break;
                }
                auto it = std::find(positions.begin(), positions.end(), bitPosition);
                // if name was found
                if(it != positions.end()) {
                    std::cout << std::distance(positions.begin(), it) << " ";
                    auto index = std::distance(positions.begin(), it);
                    char temp = header[index];
                    manipulateBit(intensity.val[k], temp);
                    ++headerBitsStored;
                }
                ++bitPosition;
            }
        }
    }
}

void Lsb::hide(const cv::Mat &img)
{
    std::cout << "hide image" << std::endl;
}