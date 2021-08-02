#pragma once
#include <bitset>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

namespace steg {

std::vector<int> dec_to_bin(const std::string& input) {
    std::vector<int> bits;

    for (std::size_t i = 0; i < input.size(); ++i) {
        auto converted_bits = std::bitset<8>(input[i]);

        for (int m = 0; m < converted_bits.size(); ++m) {
            bits.push_back(converted_bits[m]);
        }
    }
    return bits;
}

std::string dec_to_bin(const int& input) {
    return std::bitset<8>(input).to_string();
}

unsigned char bin_to_dec(std::string input) {
    return std::stoi(input, nullptr, 2);
}

void least_significant_bit_encode(std::string image_path, std::string text) {
    cv::Mat img = cv::imread(image_path);

    // check how many pixels must be manipulated to fit the text
    int max_text_num = text.size() * 8;

    int needed_pixels = (max_text_num % 3 == 0) ? max_text_num / 3 : max_text_num / 3 + 1;
    std::cout << needed_pixels;

    std::vector<int> bin_converted_text = dec_to_bin(text);
    int pixel_counter = 0;
    int counter = 0;
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            // if number of needed pixels is reached stop iterating
            if (pixel_counter > needed_pixels) {
                break;
            }
            cv::Vec3b& intensity = img.at<cv::Vec3b>(i, j);
            for (int k = 0; k < img.channels(); k++) {
                std::string bin_converted_value = dec_to_bin(int(intensity.val[k]));

                bin_converted_value.replace(7, 1, std::to_string(bin_converted_text[counter]));

                // convert RGB values to binary and change last bit with text bit
                intensity.val[k] = bin_to_dec(bin_converted_value);
                ++counter;
            }
            ++pixel_counter;
        }
    }

    cv::imwrite("output.png", img);
}
} // namespace steg