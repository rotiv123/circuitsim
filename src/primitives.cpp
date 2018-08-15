//
// Created by vitor on 15-08-2018.
//

#include "primitives.hpp"
#include "circuit.hpp"
#include "private/primitives.hh"

namespace circuitsim {

    void add_resistor(circuit &c, std::string name) {
        c.add(resistor::symbol(), std::move(name));
    }

    void add_voltage_source(circuit &c, std::string name) {
        c.add(voltage_source::symbol(), std::move(name));
    }

}