#pragma once

#include "../system_state.h"

class MegaController : public Controller {
   public:
    MegaController();
    void initPins() override;
};