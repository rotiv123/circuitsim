//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_PRIMITIVES_HPP
#define CIRCUITSIM_PRIMITIVES_HPP


#include <circuitsim/config/export.h>
#include <string>

namespace circuitsim {

    class circuit;

    CIRCUITSIM_API std::string add_resistor(circuit&);

    CIRCUITSIM_API std::string add_resistor(circuit &, double);

    CIRCUITSIM_API std::string add_voltage_source(circuit&);

    CIRCUITSIM_API std::string add_voltage_source(circuit &, double);
}

#endif //CIRCUITSIM_PRIMITIVES_HPP
