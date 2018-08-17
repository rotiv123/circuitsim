//
// Created by vitor on 15-08-2018.
//

#include "primitives.hpp"
#include "circuit.hpp"
#include "private/primitives.hh"

namespace circuitsim {

    std::string add_resistor(circuit &c, std::string name) {
        return c.add(component_traits<resistor>::symbol(), std::move(name));
    }

    std::string add_voltage_source(circuit &c, std::string name) {
        return c.add(component_traits<voltage_source>::symbol(), std::move(name));
    }

}