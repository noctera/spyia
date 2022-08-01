# Styia

Styia is a C++ lib for steganography

REQUIREMENTS

- OpenCV installed

## Example

```cpp
#include <styia/Steganography.hpp>
#include <iostream>

int main() {
    // hiding secret message
    styia::leastBit::encodeText("/path_to_input_image/input.png", "/path_to_output_image/output.png", "My secret Message");

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
	GIT_REPOSITORY	https://github.com/noctera/styia.git
	GIT_TAG		origin/main
)
FetchContent_MakeAvailable(CppSteg)

target_link_libraries(
	<your_target_name>
	PUBLIC CppSteg
)
```

## External

- Cmake files and folder structure taken from this project [5cript/roar](https://github.com/5cript/roar)
