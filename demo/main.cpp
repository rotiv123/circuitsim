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

    auto v1 = add_voltage_source(c);
    auto v2 = add_voltage_source(c);
    auto r1 = add_resistor(c);
    auto r2 = add_resistor(c);
    auto r3 = add_resistor(c);
    auto r4 = add_resistor(c);

    c.set_value(v1, 9);
    c.set_value(v2, 9);
    c.set_value(r2, 200);
    c.set_value(r3, 200);

    c.ground(v1, 1);
    c.connect(v1, 0, r1, 0);
    c.connect(r1, 1, r2, 0);
    c.connect(r3, 0, r2, 0);
    c.ground(r2, 1);
    //c.ground(r3, 1);

    c.remove(v1);
    c.connect(r1, 0, v2, 0);
    c.ground(v2, 1);

    c.visit([](const component_view &x) {
        auto n1 = x.port(0);
        auto n2 = x.port(1);
        std::cout << x.name() << " " << n1 << " " << n2 << " " << x.value() << std::endl;
    });

    dc_solver dc;
    std::cout << std::endl << "dc solving..." << std::endl;
    if (!dc.solve(c)) {
        std::cout << "ups... :(" << std::endl;
    }

    return 0;
}