#include "../catch.hpp"
#include "../src/command_builder.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

TEST_CASE("Create packet from JSON for move_servo", "[createPacketFromJson]") {
    // Simulate the user input
    json input = {
        {"command", "move_servo"},
        {"servo_id", 3},
        {"position", 90}
    };

    // Call the high-level function
    auto packet = createCommandFromJson(input);

    // Now check the packet content
    REQUIRE(packet.size() == 6); // Start + Type + Length + Payload[2] + Checksum

    REQUIRE(packet[0] == 0xAA); // Start byte
    REQUIRE(packet[1] == 0x01); // Command ID (move_servo = 0x01)
    REQUIRE(packet[2] == 0x02); // Payload length: 2 bytes (servo_id, position)
    REQUIRE(packet[3] == 0x03); // servo_id = 3
    REQUIRE(packet[4] == 0x5A); // position = 90 (0x5A in hex)
    REQUIRE(packet[5] == (packet[1] ^ packet[2] ^ packet[3] ^ packet[4])); // Checksum
}
