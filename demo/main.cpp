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
    auto v2 = add_voltage_source(c, "V2");
    auto r1 = add_resistor(c, "R1");
    auto r2 = add_resistor(c, "R2");
    auto r3 = add_resistor(c, "R3");
    auto r4 = add_resistor(c, "R4");

    set_value(c, v1, 10);

    ground(c, v1, 1);
    connect(c, v1, 0, r1, 0);
    connect(c, r1, 1, r2, 0);
    connect(c, r3, 0, r2, 0);
    ground(c, r2, 1);
    //ground(c, r3, 1);

    dc_solver dc;
    if (!dc.solve(c)) {
        std::cout << "ups... :(" << std::endl;
    }

    return 0;
}