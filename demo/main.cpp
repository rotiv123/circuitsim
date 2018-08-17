//
// Created by vitor on 12-08-2018.
//

#include <iostream>
#include <iomanip>
#include <circuitsim.h>
#include <circuit.hpp>
#include <primitives.hpp>
#include <dc_solver.hpp>

int main() {
    circuitsim_hello();

    using namespace circuitsim;

    circuit c{};

    auto v1 = add_voltage_source(c, "V1");
    auto r1 = add_resistor(c, "R1");
    auto r2 = add_resistor(c, "R2");

    set_value(c, v1, 5);
    set_value(c, r1, 100);
    set_value(c, r2, 100);

    ground(c, v1, 1);
    connect(c, v1, 0, r1, 0);
    connect(c, r1, 1, r2, 0);
    ground(c, r2, 1);

    dc_solver dc;
    dc.solve(c);

    return 0;
}