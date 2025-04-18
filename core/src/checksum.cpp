#include "checksum.h"

uint8_t calculateChecksum(const uint8_t* data, size_t length) {
    uint8_t checksum = 0x00;
    for (size_t i = 0; i < length; ++i) {
        checksum ^= data[i];
    }
    return checksum;
}
