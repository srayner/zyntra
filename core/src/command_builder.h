#pragma once

#include <vector>
#include <cstdint>

std::vector<uint8_t> buildCommand(uint8_t commandType, const std::vector<uint8_t>& payload);
