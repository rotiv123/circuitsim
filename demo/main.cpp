//
// Created by vitor on 12-08-2018.
//

#include <iostream>
#include <iomanip>
#include <circuitsim.h>
#include <circuit.hpp>
#include <ui/circuit2d.hpp>
#include <primitives.hpp>
#include <ui/primitives2d.hpp>
#include <dc_solver.hpp>
#include <ui/svg_painter.hpp>

void test1() {
    std::cout << "circuitsim version: " << circuitsim_version() << std::endl;

    using namespace circuitsim;
    using namespace circuitsim::ui;

    circuit2d c{};

    auto v1 = c.add("V");
    auto v2 = add_voltage_source(c);
    auto r1 = add_resistor(c);
    auto r2 = add_resistor(c);
    auto r3 = add_resistor(c);
    auto r4 = add_resistor(c);
    auto r5 = add_resistor(c);

    c.value(v1, 9);
    c.value(v2, 9);
    c.value(r2, 200);
    c.value(r3, 200);

    c.ground(v1, 1);
    c.connect(v1, 0, r1, 0);
    c.connect(r1, 1, r2, 0);
    c.connect(r3, 0, r2, 0);
    c.ground(r2, 1);
    c.connect(r5, 1, r5, 0);

    c.remove(v1);
    c.connect(r1, 0, v2, 0);
    c.ground(v2, 1);

    c.visit([](auto &&x) {
        auto n1 = x.port(0);
        auto n2 = x.port(1);
        std::cout << x.name() << " " << n1 << " " << n2 << " " << x.value() << std::endl;
    });
    std::cout << std::endl;

    svg_painter painter;
    std::cout << "drawing..." << std::endl;
    std::cout << painter.draw(c) << std::endl;

    dc_solver dc;
    std::cout << "dc solving..." << std::endl;
    if (!dc.solve(c)) {
        std::cout << "ups... :(" << std::endl;
    } else {
        dc.visit([](auto &&dp) {
            std::visit([](auto &&x) {
                using T = std::decay_t<decltype(x)>;
                if constexpr (std::is_same_v<T, circuitsim::node_voltage>) {
                    std::cout << "v_" << x.node_id << " = " << x.value << std::endl;
                } else if constexpr (std::is_same_v<T, circuitsim::voltage_source_current>) {
                    std::cout << "i_" << x.voltage_source_id << " = " << x.value << std::endl;
                }
            }, dp);
        });
    }
}

int main() {
    using namespace circuitsim;
    using namespace circuitsim::ui;

    circuit2d c{};

    auto v1 = add_voltage_source(c, 9, {-3, 0});
    auto r1 = add_resistor(c, 200, {0, 3});
    auto r2 = add_resistor(c, 200, {3, 0}, -90);

    c.ground_move_to(0, -4);

    c.ground(v1, 1);
    c.connect(v1, 0, r1, 0);
    c.connect(r1, 1, r2, 0);
    c.ground(r2, 1);

    svg_painter painter;
    std::cout << painter.draw(c) << std::endl;

    return 0;
}