#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Pin {
    std::string type;
    int pin_number;
    std::string state;
};

class Controller {
   public:
    std::string type;
    std::vector<Pin> pins;

    virtual ~Controller() = default;
    virtual void initPins() = 0;

    std::string toString() const { return type; }
};

extern std::vector<std::unique_ptr<Controller>> controllers;
