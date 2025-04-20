#include <iostream>
#include <string>
#include <vector>

struct Pin {
    std::string type;
    int pin_number;
    std::string state;
};

struct Controller {
    std::string type;
    std::vector<Pin> pins;
};

extern std::vector<Controller> controllers;
