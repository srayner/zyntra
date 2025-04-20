#pragma once

#include "../system_state.h"

class NanoController : public Controller {
   public:
    NanoController();
    void initPins() override;
};
