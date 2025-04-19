#pragma once
#include "command_schema.h"
#include <nlohmann/json.hpp>

std::vector<uint8_t> createCommandFromJson(const nlohmann::json& j);
