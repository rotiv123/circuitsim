//
// Created by vitor on 13-08-2018.
//

#ifndef PROJECT_RESISTOR_HH
#define PROJECT_RESISTOR_HH

#include <string_view>
#include "basic_component.hh"
#include "../dc_context_view.hpp"

namespace circuitsim {

    class resistor;

    template<>
    struct component_traits<resistor> {
        static constexpr std::string_view symbol() {
            return "R";
        }
    };

    struct resistor : public basic_component<resistor, 2> {
        using base = basic_component<resistor, 2>;

        explicit resistor(std::string name) noexcept
                : base{std::move(name)} {
            value(100);
        }

        void stamp(dc_context_view &ctx) const {
            ctx.stamp_resistance(port(0), port(1), value());
        }
    };

}


#endif //PROJECT_RESISTOR_HH
