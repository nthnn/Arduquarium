#ifndef MODULE_PH4502C_H
#define MODULE_PH4502C_H

#include "module_config.h"

class PH4502C {
    public:
    PH4502C(int _to_pin, int _po_pin): to_pin(_to_pin), po_pin(_po_pin) { }

    float read_ph_level();
    float read_temperature();

    private:
    int to_pin, po_pin;
};

#endif