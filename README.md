# steganography

This is a single header "Least significant bit (LSB)" steganography lib to hide text in an image

## Example

```cpp
#include "../include/Steganography.h"
#include <iostream>

int main() {

    steg::leastSignificantBitEncode("/home/julian/steganography/src/input.png", "/home/julian/steganography/src/output.png", "My secret message");
    std::cout << steg::leastSignificantBitDecode("/home/julian/steganography/src/output.png") << std::endl;
}
```
