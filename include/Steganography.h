#pragma once
#include <bitset>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

namespace steg {

std::vector<int> textToBin(const std::string& input) {
    std::vector<int> bits;

    for (std::size_t i = 0; i < input.size(); ++i) {
        auto convertedBits = std::bitset<8>(input[i]);

        for (int m = 0; m < convertedBits.size(); ++m) {
            bits.push_back(convertedBits[m]);
        }
    }
    return bits;
}

std::string decToBin(const int& input) {
    return std::bitset<8>(input).to_string();
}

unsigned char binToDec(std::string input) {
    return std::stoi(input, nullptr, 2);
}

void leastSignificantBitEncode(std::string imagePath, std::string text) {
    cv::Mat img = cv::imread(imagePath);

    // check how many pixels must be manipulated to fit the text
    int maxTextNum = text.size() * 8;

    int neededPixels = (maxTextNum % 3 == 0) ? maxTextNum / 3 : maxTextNum / 3 + 1;

    std::vector<int> binConvertedText = textToBin(text);
    int pixelCounter = 0;
    int counter = 0;
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            // if number of needed pixels is reached stop iterating
            if (pixelCounter > neededPixels) {
                break;
            }
            cv::Vec3b& intensity = img.at<cv::Vec3b>(i, j);
            for (int k = 0; k < img.channels(); k++) {
                std::string binConvertedValue = decToBin(int(intensity.val[k]));

                binConvertedValue.replace(7, 1, std::to_string(binConvertedText[counter]));

                // convert RGB values to binary and change last bit with text bit
                intensity.val[k] = binToDec(binConvertedValue);
                ++counter;
            }
            ++pixelCounter;
        }
    }

    cv::imwrite("output.png", img);
}
} // namespace steg