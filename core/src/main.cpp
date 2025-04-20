#include <iostream>
#include <sstream>
#include <thread>

#include "system_command.h"
#include "web_server.h"

int main() {
    std::thread webServerThread([]() { startWebServer(); });

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

        for (auto& cmd : systemCommands) {
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
