//
// Created by vitor on 12-08-2018.
//

#include <iostream>
#include <circuitsim.h>
#include <circuit.hpp>
#include <primitives.hpp>

int main() {
    circuitsim_hello();

    using namespace circuitsim;

    circuit c{};

    add_voltage_source(c, "V1");
    add_resistor(c, "R1");
    add_resistor(c, "R2");

    ground(c, "V1", 0);
    connect(c, "V1", 1, "R1", 0);
    connect(c, "R1", 1, "R2", 0);
    ground(c, "R2", 1);

    return 0;
}