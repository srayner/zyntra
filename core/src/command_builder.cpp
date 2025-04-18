#include "command_builder.h"
#include "checksum.h"

std::vector<uint8_t> buildCommand(uint8_t commandType, const std::vector<uint8_t>& payload) {
    std::vector<uint8_t> packet;

    const uint8_t START_BYTE = 0xAA;

    packet.push_back(START_BYTE);
    packet.push_back(commandType);
    packet.push_back(static_cast<uint8_t>(payload.size()));

    // Insert payload if any
    packet.insert(packet.end(), payload.begin(), payload.end());

    // Calculate checksum (all bytes after START_BYTE, before checksum)
    uint8_t checksum = calculateChecksum(&packet[1], packet.size() - 1);
    packet.push_back(checksum);

    return packet;
}
