//
// Created by vitor on 15-08-2018.
//

#include "primitives.hpp"
#include "circuit.hpp"
#include "private/primitives.hh"

namespace circuitsim {

    std::string add_resistor(circuit &c) {
        return c.add(component_traits<resistor>::symbol());
    }

    std::string add_resistor(circuit &c, double val) {
        auto name = c.add(component_traits<resistor>::symbol());
        c.value(name, val);
        return name;
    }

    std::string add_voltage_source(circuit &c) {
        return c.add(component_traits<voltage_source>::symbol());
    }

    std::string add_voltage_source(circuit &c, double val) {
        auto name = c.add(component_traits<voltage_source>::symbol());
        c.value(name, val);
        return name;
    }
}