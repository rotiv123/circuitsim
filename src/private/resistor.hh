//
// Created by vitor on 13-08-2018.
//

#ifndef PROJECT_RESISTOR_HH
#define PROJECT_RESISTOR_HH

#include <string_view>
#include "basic_component.hh"
#include "../dc_context_view.hpp"

namespace circuitsim {

    class resistor : public basic_component<resistor, 2> {
    public:
        using base = basic_component<resistor, 2>;
        using base::base;
    };

    template<>
    struct component_traits<resistor> {

        static constexpr std::string_view symbol() {
            return "R";
        }

        static constexpr double default_value() {
            return 100;
        }

        static void stamp(const resistor &x, dc_context_view &ctx) {
            ctx.stamp_resistance(x.port(0), x.port(1), x.value());
        }
    };

}


#endif //PROJECT_RESISTOR_HH
