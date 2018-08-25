//
// Created by vitor on 25-08-2018.
//

#ifndef CIRCUITSIM_BASIC_VOLTAGE_SOURCE_HH
#define CIRCUITSIM_BASIC_VOLTAGE_SOURCE_HH

#include "basic_component.hh"
#include "component_with_value.hh"
#include "../dc_context_view.hpp"

namespace circuitsim {

    template<class Derived>
    class basic_voltage_source : public component_with_value<Derived, basic_component < Derived, 2>>

{
    public:
    using base = component_with_value <Derived, basic_component<Derived, 2>>;
    using base::base;
};

template<class Derived>
struct voltage_source_traits {
    static constexpr std::string_view symbol() {
        return "V";
    }

    static constexpr double default_value() {
        return 5;
    }

    static void stamp(const Derived &x, dc_context_view &ctx) {
        ctx.stamp_voltage(x.port(0), x.port(1), value(x));
    }
};

}

#endif //CIRCUITSIM_BASIC_VOLTAGE_SOURCE_HH
