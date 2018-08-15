//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_GROUND_HH
#define CIRCUITSIM_GROUND_HH

#include <cassert>
#include <string_view>
#include "basic_component.hh"

namespace circuitsim {

    struct ground : public basic_component<ground, 1> {
        using base = basic_component<ground, 1>;

        explicit ground(std::string name) noexcept
                : base{std::move(name)} {
            port(0, 0);
        }

        static constexpr std::string_view symbol() {
            return "0";
        }

    private:
        friend base;

        void check_set_port(unsigned ix, int val) const {
            base::check_set_port(ix, val);
            assert(val == 0);
        }
    };

}


#endif //CIRCUITSIM_GROUND_HH
