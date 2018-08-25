//
// Created by vitor on 13-08-2018.
//

#ifndef CIRCUITSIM_VOLTAGE_SOURCE_HH
#define CIRCUITSIM_VOLTAGE_SOURCE_HH

#include "basic_voltage_source.hh"

namespace circuitsim {

    class voltage_source final : public basic_voltage_source<voltage_source> {
    public:
        using base = basic_voltage_source<voltage_source>;
        using base::base;
    };

    template<>
    struct component_traits<voltage_source> final : public voltage_source_traits<voltage_source> {
    };

}


#endif //CIRCUITSIM_VOLTAGE_SOURCE_HH
