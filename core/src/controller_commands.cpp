#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "./controllers/mega.h"
#include "./controllers/nano.h"
#include "./controllers/uno.h"
#include "system_state.h"

std::vector<std::unique_ptr<Controller>> controllers;

void addController(const std::string& type) {
    if (type == "nano") {
        controllers.push_back(std::make_unique<NanoController>());
    } else if (type == "uno") {
        controllers.push_back(std::make_unique<UnoController>());
    } else if (type == "mega") {
        controllers.push_back(std::make_unique<MegaController>());
    } else {
        std::cerr << "Unknown controller type: " << type << std::endl;
    }
}

void removeController(int controllerIndex) {
    if (controllerIndex >= 0 && controllerIndex < controllers.size()) {
        controllers.erase(controllers.begin() + controllerIndex);
    } else {
        std::cout << "Invalid controller index." << std::endl;
    }
}

void listControllers() {
    for (size_t i = 0; i < controllers.size(); ++i) {
        std::cout << "Controller " << i << ": " << controllers[i]->toString()
                  << std::endl;
    }
}

void listPins(int controllerIndex) {
    if (controllerIndex < 0 || controllerIndex >= controllers.size()) {
        std::cout << "Invalid controller index." << std::endl;
        return;
    }

    Controller* ctrl = controllers[controllerIndex].get();
    std::cout << "Controller: " << ctrl->toString() << std::endl;

    for (size_t i = 0; i < ctrl->pins.size(); ++i) {
        std::cout << "Pin " << i << " | Type: " << ctrl->pins[i].type
                  << " | Number: " << ctrl->pins[i].pin_number
                  << " | State: " << ctrl->pins[i].state << std::endl;
    }
}

void showPinConfig(int controllerIndex, int pinIndex) {
    if (controllerIndex < 0 || controllerIndex >= controllers.size()) {
        std::cout << "Invalid controller index." << std::endl;
        return;
    }

    Controller* ctrl = controllers[controllerIndex].get();

    if (pinIndex < 0 || pinIndex >= ctrl->pins.size()) {
        std::cout << "Invalid pin index." << std::endl;
        return;
    }

    const Pin& pin = ctrl->pins[pinIndex];
    std::cout << "Pin Config - Type: " << pin.type
              << ", Number: " << pin.pin_number << std::endl;
}

void showPinState(int controllerIndex, int pinIndex) {
    if (controllerIndex < 0 || controllerIndex >= controllers.size()) {
        std::cout << "Invalid controller index." << std::endl;
        return;
    }

    Controller* ctrl = controllers[controllerIndex].get();

    if (pinIndex < 0 || pinIndex >= ctrl->pins.size()) {
        std::cout << "Invalid pin index." << std::endl;
        return;
    }

    const Pin& pin = ctrl->pins[pinIndex];
    std::cout << "Pin State - State: " << pin.state << std::endl;
}
