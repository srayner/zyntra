#include "command_builder.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

int main() {
  std::string input;

  while (true) {
    std::cout << "Enter command (JSON format): ";
    std::getline(std::cin, input);

    if (input == "exit") {
      break;
    }

    try {
      json j = json::parse(input);

      if (!j.is_object()) {
        std::cout << "Invalid input: Must be a JSON object!" << std::endl;
        continue;
      }

      std::vector<uint8_t> command = createCommandFromJson(j);

      // Output the command as a byte sequence
      std::cout << "Byte sequence: ";
      for (auto byte : command) {
        std::cout << "0x" << std::setw(2) << std::setfill('0') << std::hex
                  << (int)byte << " ";
      }
      std::cout << std::endl;

    } catch (const json::exception &e) {
      std::cout << "Invalid JSON format: " << e.what() << std::endl;
    } catch (const std::runtime_error &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }

  return 0;
}
