//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_RESISTOR2D_HH
#define CIRCUITSIM_RESISTOR2D_HH

#include "basic_resistor2d.hh"

namespace circuitsim {
    namespace ui {

        class resistor2d final : public basic_resistor2d<resistor2d> {
        public:
            using base = basic_resistor2d<resistor2d>;
            using base::base;
        };

    }

    template<>
    struct component_traits<ui::resistor2d> final : public ui::resistor2d_traits<ui::resistor2d> {
    };
}


#endif //CIRCUITSIM_RESISTOR2D_HH
