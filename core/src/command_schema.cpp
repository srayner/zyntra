#include "command_schema.h"

std::vector<Command> commandSchema = {
    {"set_pin_mode", 0x10, {{"pin", "integer", "null"}, {"mode", "integer", "null"}}},
    {"servo_move", 0x32, {{"servo_id", "integer", "null"}, {"position", "integer", "null"}}}};
