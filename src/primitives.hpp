//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_PRIMITIVES_HPP
#define CIRCUITSIM_PRIMITIVES_HPP


#include <circuitsim/config/export.h>
#include <string>

namespace circuitsim {

    class circuit;

    CIRCUITSIM_API void add_resistor(circuit&, std::string name);

    CIRCUITSIM_API void add_voltage_source(circuit&, std::string name);

}

#endif //CIRCUITSIM_PRIMITIVES_HPP
