

#include "system_command.h"

#include <iostream>

#include "controller_commands.h"

std::vector<SystemCommand> systemCommands = {
    {"list_controllers",
     {},
     [](const std::vector<std::string>&) { listControllers(); }},
    {"add_controller",
     {"controller_type"},
     [](const std::vector<std::string>& args) {
         if (!args.empty()) {
             addController(
                 args[0]);  // Pass the first argument (controller type)
         } else {
             std::cerr << "Error: Missing controller type argument.\n";
         }
     }},
    {"delete_controller",
     {"controller_id"},
     [](const std::vector<std::string>& args) {
         if (args.size() == 1) {
             int controllerId = std::stoi(args[0]);
             removeController(
                 controllerId);  // Convert string to int for controller_id
         } else {
             std::cerr << "Error: Missing or invalid controller ID argument.\n";
         }
     }},
    {"list_pins",
     {"controller_id"},
     [](const std::vector<std::string>& args) {
         if (args.size() == 1) {
             int controllerId = std::stoi(args[0]);
             listPins(controllerId);  // Convert string to int for controller_id
         } else {
             std::cerr << "Error: Missing or invalid controller ID argument.\n";
         }
     }},
    {"show_pin_config",
     {"controller_id", "pin_id"},
     [](const std::vector<std::string>& args) {
         if (args.size() >= 2) {
             int controllerId = std::stoi(args[0]);
             int pinId = std::stoi(args[1]);
             showPinConfig(controllerId, pinId);  // Convert strings to int
         } else {
             std::cerr << "Error: Missing or invalid arguments for "
                          "controller_id and pin_id.\n";
         }
     }},
    {"show_pin_state",
     {"controller_id", "pin_id"},
     [](const std::vector<std::string>& args) {
         if (args.size() >= 2) {
             int controllerId = std::stoi(args[0]);
             int pinId = std::stoi(args[1]);
             showPinState(controllerId, pinId);  // Convert strings to int
         } else {
             std::cerr << "Error: Missing or invalid arguments for "
                          "controller_id and pin_id.\n";
         }
     }}};
