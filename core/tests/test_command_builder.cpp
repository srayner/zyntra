#include "../catch.hpp"
#include "../src/command_builder.h"

TEST_CASE("Build simple command packet", "[command_builder]") {
    std::vector<uint8_t> payload = { 0x03, 0x5A }; // servo 3, angle 90
    auto packet = buildCommand(0x01, payload);

    REQUIRE(packet.size() == 6);
    REQUIRE(packet[0] == 0xAA); // Start byte
    REQUIRE(packet[1] == 0x01); // Command type
    REQUIRE(packet[2] == 0x02); // Payload length
    REQUIRE(packet[3] == 0x03); // Payload[0]
    REQUIRE(packet[4] == 0x5A); // Payload[1]
    // Last byte is checksum - you can manually calculate or trust calculateChecksum
    REQUIRE(packet[5] == (packet[1] ^ packet[2] ^ packet[3] ^ packet[4]));
}
