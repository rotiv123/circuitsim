//
// Created by vitor on 25-08-2018.
//

#ifndef CIRCUITSIM_BASIC_RESISTOR_HH
#define CIRCUITSIM_BASIC_RESISTOR_HH


#include <string_view>
#include "basic_component.hh"
#include "component_with_value.hh"
#include "../dc_context_view.hpp"

namespace circuitsim {

    template<class Derived>
    class basic_resistor : public component_with_value<Derived, basic_component<Derived, 2>> {
    public:
        using base = component_with_value<Derived, basic_component<Derived, 2>>;
        using base::base;
    };

    template<class Resistor>
    struct resistor_traits {

        static constexpr std::string_view symbol() {
            return "R";
        }

        static constexpr double default_value() {
            return 100;
        }

        static void stamp(const Resistor &x, dc_context_view &ctx) {
            ctx.stamp_resistance(x.port(0), x.port(1), value(x));
        }
    };

}

#endif //CIRCUITSIM_BASIC_RESISTOR_HH
