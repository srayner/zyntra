#include "command_builder.h"
#include "checksum.h"

static std::vector<uint8_t> buildCommand(uint8_t commandType,
                                         const std::vector<uint8_t> &payload) {
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

std::vector<uint8_t> createCommandFromJson(const nlohmann::json &j) {

  if (!j.contains("command")) {
    throw std::runtime_error("Command key missing in input JSON");
  }

  // Find the matching command in the schema
  std::string command_name = j["command"];
  Command *matchedCommand = nullptr;

  // Find matching command in the schema
  for (auto &command : commandSchema) {
    if (command.name == command_name) {
      matchedCommand = &command;
      break;
    }
  }

  if (!matchedCommand) {
    throw std::runtime_error("Command not found in schema");
  }

  // Validate and build the packet
  std::vector<uint8_t> payload;
  for (const auto &argument : matchedCommand->arguments) {
    if (j.contains(argument.name)) {
      // Validate type (assuming integers here for simplicity)
      if (argument.type == "integer") {
        payload.push_back(j[argument.name].get<uint8_t>());
      } else {
        throw std::runtime_error("Unsupported argument type");
      }
    } else {
      // Use default if present
      if (argument.default_value != "null") {
        payload.push_back(std::stoi(argument.default_value));
      }
    }
  }

  return buildCommand(matchedCommand->command_id, payload);
}