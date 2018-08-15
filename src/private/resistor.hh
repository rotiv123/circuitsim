//
// Created by vitor on 13-08-2018.
//

#ifndef PROJECT_RESISTOR_HH
#define PROJECT_RESISTOR_HH

#include <string_view>
#include "basic_component.hh"

namespace circuitsim {

    struct resistor : public basic_component<resistor, 2> {
        using base = basic_component<resistor, 2>;
        using base::base;

        static constexpr std::string_view symbol() {
            return "R";
        }
    };

}


#endif //PROJECT_RESISTOR_HH
