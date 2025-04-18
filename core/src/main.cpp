#include <iostream>
#include "checksum.h"

int main() {
    std::cout << "Hello, Zyntra World!" << std::endl;

    // Example data to calculate checksum
    uint8_t testData[] = { 0xAA, 0x02, 0x32, 0x05, 0x90 };

    // Calculate checksum
    uint8_t checksum = calculateChecksum(testData, sizeof(testData));

    // Display result
    std::cout << "Calculated checksum: 0x" 
              << std::hex << static_cast<int>(checksum) << std::endl;

    return 0;
}