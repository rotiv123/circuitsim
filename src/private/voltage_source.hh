//
// Created by vitor on 13-08-2018.
//

#ifndef CIRCUITSIM_VOLTAGE_SOURCE_HH
#define CIRCUITSIM_VOLTAGE_SOURCE_HH

#include "basic_component.hh"

namespace circuitsim {

    struct voltage_source : public basic_component<voltage_source, 2> {
        using base = basic_component<voltage_source, 2>;
        using base::base;

        static constexpr std::string_view symbol() {
            return "V";
        }
    };

}


#endif //CIRCUITSIM_VOLTAGE_SOURCE_HH
