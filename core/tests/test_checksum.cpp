#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../src/checksum.h"

TEST_CASE("Checksum calculation") {
    SECTION("Basic Test") {
        uint8_t testData[] = { 0xAA, 0x03, 0x32, 0x05, 0x90 };
        REQUIRE(calculateChecksum(testData, sizeof(testData)) == 0x0E);
    }

    SECTION("Empty Data") {
        uint8_t testData[] = {};
        REQUIRE(calculateChecksum(testData, sizeof(testData)) == 0x00);
    }

    SECTION("Single Byte") {
        uint8_t testData[] = { 0x01 };
        REQUIRE(calculateChecksum(testData, sizeof(testData)) == 0x01);
    }

    SECTION("Multiple Identical Bytes") {
        uint8_t testData[] = { 0xFF, 0xFF, 0xFF };
        REQUIRE(calculateChecksum(testData, sizeof(testData)) == 0xFF);
    }

    SECTION("Checksum Edge Case") {
        uint8_t testData[] = { 0xFF, 0x00, 0xFF, 0x00 };
        REQUIRE(calculateChecksum(testData, sizeof(testData)) == 0x00);
    }
}
