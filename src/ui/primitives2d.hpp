//
// Created by vitor on 25-08-2018.
//

#ifndef CIRCUITSIM_PRIMITIVES2D_HPP
#define CIRCUITSIM_PRIMITIVES2D_HPP

#include <circuitsim/config/export.h>
#include <string>
#include "point2d.hpp"

namespace circuitsim::ui {

    class circuit2d;

    CIRCUITSIM_API std::string add_resistor(circuit2d &, double, point2d);

    CIRCUITSIM_API std::string add_resistor(circuit2d &, double, point2d, int);

    CIRCUITSIM_API std::string add_voltage_source(circuit2d &, double, point2d);

    CIRCUITSIM_API std::string add_voltage_source(circuit2d &, double, point2d, int);

}


#endif //CIRCUITSIM_PRIMITIVES2D_HPP
