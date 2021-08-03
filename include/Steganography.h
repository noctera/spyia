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
        // mirror bitset in order to get the right direction. Don't ask me why c++ is flipping the bitset when iterating over it
        auto convertedBits = std::bitset<8>(input[i]);
        for (int ii = convertedBits.size() - 1; ii >= 0; --ii) {
            bits.push_back(convertedBits[ii]);
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

char binToText(std::string input) {
    char temp = 0;
    for (int i = 0; i < 8; i++) {
        if ('1' == input.at(i)) {
            temp += pow(2, 7 - i);
        }
    }

    return temp;
}

void leastSignificantBitEncode(std::string imagePath, std::string text) {
    cv::Mat img = cv::imread(imagePath);

    // check how many pixels must be manipulated to fit the text
    int maxTextNum = text.size() * 8;

    int neededPixels = (maxTextNum % 3 == 0) ? maxTextNum / 3 : maxTextNum / 3 + 1;

    std::vector<int> binConvertedText = textToBin(text);
    for (auto binConv : binConvertedText) {
        std::cout << binConv;
    }
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

std::string leastSignificantBitDecode(std::string imagePath) {
    cv::Mat img = cv::imread(imagePath);

    int bitCounter = 0;
    std::string bits = "";
    std::string fullText = "";

    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            // if number of needed pixels is reached stop iterating
            cv::Vec3b& intensity = img.at<cv::Vec3b>(i, j);
            for (int k = 0; k < img.channels(); k++) {
                std::string binConvertedValue = decToBin(int(intensity.val[k]));

                bits += binConvertedValue[7];

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
    return fullText;
}
} // namespace steg