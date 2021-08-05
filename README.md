# steganography

This is a single header "Least significant bit (LSB)" steganography lib to hide text in an image

## Example

```cpp
#include <CppSteg/steganography.hpp>
#include <iostream>

int main() {
    // hiding secret message
    steg::leastSignificantBitEncode("/path_to_input_image/input.png", "/path_to_output_image/output.png", "My secret Message");

    // decode message from manipulated picture
    std::cout << steg::leastSignificantBitDecode("/path_to_manipulated_image/output.png") << std::endl;
}
```
