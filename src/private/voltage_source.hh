//
// Created by vitor on 13-08-2018.
//

#ifndef CIRCUITSIM_VOLTAGE_SOURCE_HH
#define CIRCUITSIM_VOLTAGE_SOURCE_HH

#include "basic_component.hh"
#include "../dc_context_view.hpp"

namespace circuitsim {

    class voltage_source : public basic_component<voltage_source, 2> {
    public:
        using base = basic_component<voltage_source, 2>;
        using base::base;
    };

    template<>
    struct component_traits<voltage_source> {
        static constexpr std::string_view symbol() {
            return "V";
        }

        static constexpr double default_value() {
            return 5;
        }

        static void stamp(const voltage_source &x, dc_context_view &ctx) {
            ctx.stamp_voltage(x.port(0), x.port(1), x.value());
        }
    };

}


#endif //CIRCUITSIM_VOLTAGE_SOURCE_HH
