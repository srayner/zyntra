#include "mega.h"

MegaController::MegaController() {
    type = "mega";
    initPins();
}

void MegaController::initPins() {
    pins.push_back({"digital", 0, "LOW"});
    pins.push_back({"digital", 1, "LOW"});
}