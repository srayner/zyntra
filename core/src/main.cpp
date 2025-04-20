#include <iostream>
#include <sstream>

#include "system_command.h"

int main() {
    while (true) {
        std::cout << "\nEnter command: ";
        std::string input;
        std::getline(std::cin, input);

        // Extract the first word (command)
        std::istringstream stream(input);
        std::string command;
        stream >> command;

        // Extract the remaining arguments
        std::vector<std::string> args;
        std::string arg;
        while (stream >> arg) {
            args.push_back(arg);  // Collect the arguments
        }

        if (command == "exit") {
            break;
        }

        bool found = false;

        std::cout << command << std::endl;
        for (auto& cmd : systemCommands) {
            std::cout << cmd.name << std::endl;
            if (cmd.name == command) {
                cmd.handler(args);
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Unknown command.\n";
        }
    }

    return 0;
}
