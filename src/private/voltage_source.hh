//
// Created by vitor on 13-08-2018.
//

#ifndef CIRCUITSIM_VOLTAGE_SOURCE_HH
#define CIRCUITSIM_VOLTAGE_SOURCE_HH

#include "basic_component.hh"
#include "../dc_context.hpp"

namespace circuitsim {

    class voltage_source;

    template<>
    struct component_traits<voltage_source> {
        static constexpr std::string_view symbol() {
            return "V";
        }
    };

    struct voltage_source : public basic_component<voltage_source, 2> {
        using base = basic_component<voltage_source, 2>;

        explicit voltage_source(std::string name) noexcept
        : base{std::move(name)} {
            value(5);
        }

        void stamp(dc_context &ctx) const {
            ctx.stamp_voltage(port(0), port(1), value());
        }
    };

}


#endif //CIRCUITSIM_VOLTAGE_SOURCE_HH
