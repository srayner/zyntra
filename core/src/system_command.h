#pragma once

#include <functional>
#include <string>
#include <vector>

struct SystemCommand {
    std::string name;
    std::vector<std::string> expected_args;
    std::function<void(const std::vector<std::string>&)> handler;
};

extern std::vector<SystemCommand> systemCommands;
