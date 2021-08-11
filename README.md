# steganography

This is a single header "Least significant bit (LSB)" steganography lib to hide text in an image

## Example

```cpp
#include <CppSteg/Steganography.hpp>
#include <iostream>

int main() {
    // hiding secret message
    cppsteg::leastBit::encodeText("/path_to_input_image/input.png", "/path_to_output_image/output.png", "My secret Message");

    // decode message from manipulated picture
    std::cout << cppsteg::leastBit::decodeText("/path_to_manipulated_image/output.png") << std::endl;
}
```


## Installation via Cmake

```cmake
cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(<your_project_name>)

include(FetchContent)

FetchContent_Declare(
	CppSteg
	GIT_REPOSITORY	https://github.com/noctera/CppSteg.git
	GIT_TAG		origin/main
)
FetchContent_MakeAvailable(CppSteg)

target_link_libraries(
	<your_target_name>
	PUBLIC CppSteg
)
