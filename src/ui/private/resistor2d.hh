//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_RESISTOR2D_HH
#define CIRCUITSIM_RESISTOR2D_HH

#include "basic_component2d.hh"
#include "../../private/resistor.hh"

namespace circuitsim {
    namespace ui {

        class resistor2d : public basic_component2d<resistor2d, resistor> {
        public:
            using base = basic_component2d<resistor2d, resistor>;
            using base::base;
        };

    }

    template<>
    struct component_traits<ui::resistor2d> : public component_traits<resistor> {

    };
}


#endif //CIRCUITSIM_RESISTOR2D_HH
