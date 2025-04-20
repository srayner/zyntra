#pragma once

#include <string>

void listControllers();
void addController(const std::string& controllerType);
void removeController(int controllerId);
void listPins(int controllerId);
void showPinConfig(int controllerId, int pinId);
void showPinState(int controllerId, int pinId);
