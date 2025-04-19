#pragma once

#include <string>
#include <vector>
#include <cstdint>

struct Argument {
    std::string name;
    std::string type;
    std::string default_value;
};

struct Command {
    std::string name;
    uint8_t command_id;
    std::vector<Argument> arguments;
};

extern std::vector<Command> commandSchema;