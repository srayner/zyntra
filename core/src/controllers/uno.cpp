#include "uno.h"

UnoController::UnoController() {
    type = "uno";
    initPins();
}

void UnoController::initPins() {
    pins.push_back({"digital", 0, "LOW"});
    pins.push_back({"digital", 1, "LOW"});
}