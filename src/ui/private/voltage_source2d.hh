//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_VOLTAGE_SOURCE2D_HH
#define CIRCUITSIM_VOLTAGE_SOURCE2D_HH


#include "basic_component2d.hh"
#include "../../private/voltage_source.hh"

namespace circuitsim::ui {
    class voltage_source2d;
}

namespace circuitsim {

    template<>
    struct component_traits<ui::voltage_source2d> : public component_traits<voltage_source> {

    };

    namespace ui {

        class voltage_source2d : public basic_component2d<voltage_source2d, voltage_source> {
        public:
            using base = basic_component2d<voltage_source2d, voltage_source>;
            using base::base;
        };

    }
}


#endif //CIRCUITSIM_VOLTAGE_SOURCE2D_HH
