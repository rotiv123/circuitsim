//
// Created by vitor on 25-08-2018.
//

#include "primitives2d.hpp"
#include "circuit2d.hpp"
#include "../primitives.hpp"

namespace circuitsim::ui {

    std::string add_resistor(circuit2d &c, double v, point2d p) {
        return add_resistor(c, v, p, 0);
    }


    std::string add_resistor(circuit2d &c, double v, point2d p, int r) {
        auto name = add_resistor(c, v);
        auto[x, y] = p;
        c.move_to(name, x, y);
        c.rotate(name, r);
        return name;
    }

    std::string add_voltage_source(circuit2d &c, double v, point2d p) {
        return add_voltage_source(c, v, p, 0);
    }

    std::string add_voltage_source(circuit2d &c, double v, point2d p, int r) {
        auto name = add_voltage_source(c, v);
        auto[x, y] = p;
        c.move_to(name, x, y);
        c.rotate(name, r);
        return name;
    }

}