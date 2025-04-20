#include <iostream>
#include <string>
#include <vector>

#include "system_state.h"

std::vector<Controller> controllers;

void addController(const std::string& type) {
    Controller newController;
    newController.type = type;

    if (type == "nano") {
        newController.pins.push_back({"digital", 0, "LOW"});
        newController.pins.push_back({"digital", 1, "LOW"});
    } else if (type == "uno") {
        newController.pins.push_back({"digital", 0, "LOW"});
        newController.pins.push_back({"analog", 1, "0"});
    } else if (type == "mega") {
        newController.pins.push_back({"digital", 0, "LOW"});
        newController.pins.push_back({"servo", 9, "0"});
    }

    controllers.push_back(newController);
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
        std::cout << "Controller " << i << ": " << controllers[i].type
                  << std::endl;
    }
}

void listPins(int controllerIndex) {
    if (controllerIndex < 0 || controllerIndex >= controllers.size()) {
        std::cout << "Invalid controller index." << std::endl;
        return;
    }

    const Controller& ctrl = controllers[controllerIndex];
    for (size_t i = 0; i < ctrl.pins.size(); ++i) {
        std::cout << "Pin " << i << " | Type: " << ctrl.pins[i].type
                  << " | Number: " << ctrl.pins[i].pin_number
                  << " | State: " << ctrl.pins[i].state << std::endl;
    }
}

void showPinConfig(int controllerIndex, int pinIndex) {
    if (controllerIndex < 0 || controllerIndex >= controllers.size()) {
        std::cout << "Invalid controller index." << std::endl;
        return;
    }

    const Controller& ctrl = controllers[controllerIndex];
    if (pinIndex < 0 || pinIndex >= ctrl.pins.size()) {
        std::cout << "Invalid pin index." << std::endl;
        return;
    }

    const Pin& pin = ctrl.pins[pinIndex];
    std::cout << "Pin Config - Type: " << pin.type
              << ", Number: " << pin.pin_number << std::endl;
}

void showPinState(int controllerIndex, int pinIndex) {
    if (controllerIndex < 0 || controllerIndex >= controllers.size()) {
        std::cout << "Invalid controller index." << std::endl;
        return;
    }

    const Controller& ctrl = controllers[controllerIndex];
    if (pinIndex < 0 || pinIndex >= ctrl.pins.size()) {
        std::cout << "Invalid pin index." << std::endl;
        return;
    }

    const Pin& pin = ctrl.pins[pinIndex];
    std::cout << "Pin State - State: " << pin.state << std::endl;
}
