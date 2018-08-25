//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_VOLTAGE_SOURCE2D_HH
#define CIRCUITSIM_VOLTAGE_SOURCE2D_HH


#include "basic_voltage_source2d.hh"

namespace circuitsim {
    namespace ui {

        class voltage_source2d final : public basic_voltage_source2d<voltage_source2d> {
        public:
            using base = basic_voltage_source2d<voltage_source2d>;
            using base::base;
        };
    }

    template<>
    struct component_traits<ui::voltage_source2d> final : public ui::voltage_source2d_traits<ui::voltage_source2d> {
    };
}


#endif //CIRCUITSIM_VOLTAGE_SOURCE2D_HH
