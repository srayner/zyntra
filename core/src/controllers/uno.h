#pragma once

#include "../system_state.h"

class UnoController : public Controller {
   public:
    UnoController();
    void initPins() override;
};