#include "nano.h"

NanoController::NanoController() {
    type = "nano";
    initPins();
}

void NanoController::initPins() {
    pins.push_back({"digital", 0, "LOW"});
    pins.push_back({"digital", 1, "LOW"});
}
