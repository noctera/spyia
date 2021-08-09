#pragma once
#include <bitset>
#include <exception>
#include <filesystem>
#include <iostream>
#include <map>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>
#include <vector>

namespace steg {

std::string textToBin(const std::string& input) {
    std::string bitStr = "";

    for (std::size_t i = 0; i < input.size(); ++i) {
        bitStr += std::bitset<8>(input[i]).to_string();
    }
    return bitStr;
}

// the header consists of 32 bits that indicate the length of the text
std::string createHeader(int stringLength) {
    return std::bitset<32>(stringLength).to_string();
}
std::string decToBin(const int& input) {
    return std::bitset<8>(input).to_string();
}

unsigned char binToDec(const std::string& input) {
    return std::bitset<8>(input).to_ulong();
}

char binToText(const std::string& input) {
    return std::bitset<8>(input).to_ulong();
}

int decodeHeader(std::string header) {
    std::bitset<32> temp(header);
    return static_cast<int>(temp.to_ulong());
}

void manipulateBit(unsigned char& pixel, const char& bit) {
    std::string binConvertedValue = decToBin(pixel);

    // manipulate last bit of binary number
    binConvertedValue[7] = bit;

    // change out color value
    pixel = binToDec(binConvertedValue);
}


void leastSignificantBitEncode(std::string imagePath, std::string outputPath, std::string input) {
    try {
        cv::Mat img = cv::imread(imagePath);

        if (img.empty()) {
            throw std::invalid_argument("Could not open image");
        }

        // calculate maximum amount of bits to change and check if text fits into it
        int maxImgBits = img.rows * img.cols * img.channels();
        // check how many pixels must be manipulated to fit the text (+ 32 for the header)
        int neededBits = input.size() * 8 + 32;

        if (maxImgBits < neededBits) {
            throw std::length_error("Text does not fit in image");
        }

        int bitCounter = 0;

        // create header for hidden text and append bits of the letters
        std::string binConvertedText = createHeader(input.length());
        binConvertedText += textToBin(input);

        // iterate over image pixels
        for (int i = 0; i < img.rows; i++) {
            // if number of needed pixels is reached stop iterating
            if (bitCounter >= neededBits) {
                break;
            }
            for (int j = 0; j < img.cols; j++) {
                // if number of needed pixels is reached stop iterating
                if (bitCounter >= neededBits) {
                    break;
                }
                // fetch RGB values of pixel
                cv::Vec3b& intensity = img.at<cv::Vec3b>(i, j);
                for (int k = 0; k < img.channels(); k++) {
                    if (bitCounter >= neededBits) {
                        break;
                    }
                    // convert color value to binary number
                    manipulateBit(intensity.val[k], binConvertedText[bitCounter]);
                    ++bitCounter;
                }
            }
        }

        cv::imwrite(outputPath, img);
    } catch (const std::exception& e) { // reference to the base of a polymorphic object
        std::cout << e.what();          // information from length_error printed
    }
}

std::string leastSignificantBitDecode(std::string imagePath) {
    cv::Mat img = cv::imread(imagePath);

    if (img.empty()) {
        throw std::invalid_argument("Could not open image");
    }

    int bitCounter = 0;
    int maxConvertedBits = 0;
    int headerCounter = 0;
    std::string header = "";
    std::string bits = "";
    std::string fullText = "";
    int length = 0;

    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            if (maxConvertedBits > length) {
                break;
            }
            // if number of needed pixels is reached stop iterating
            cv::Vec3b& intensity = img.at<cv::Vec3b>(i, j);
            for (int k = 0; k < img.channels(); k++) {
                if (maxConvertedBits > length) {
                    break;
                }
                std::string binConvertedValue = decToBin(intensity.val[k]);
                // as long as 37 bits are not reached store all 37 bits in a string

                if (headerCounter == 32) {
                    length = decodeHeader(header) * 8;
                    // std::cout << "filetype: " << jasdflkasfj["filetype"] << std::endl << "colorSpace: " <<
                    // jasdflkasfj["colorSpace"] << std::endl << "length: " << jasdflkasfj["length"] << std::endl;
                    ++headerCounter;
                }

                if (headerCounter < 32) {
                    header += binConvertedValue[7];
                    ++headerCounter;
                } else {
                    // when header bits are fetched extract the normal text
                    bits += binConvertedValue[7];
                    ++maxConvertedBits;
                    ++bitCounter;
                    // if 8 bits were extracted convert them to a string
                    if (bitCounter == 8) {
                        fullText += binToText(bits);
                        bitCounter = 0;
                        bits = "";
                    }
                }
            }
        }
    }
    return fullText;
}
} // namespace steg