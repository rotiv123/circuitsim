//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_HH
#define CIRCUITSIM_COMPONENT_HH

#include "../component.hpp"
#include "primitives.hh"

namespace circuitsim {

    struct component::impl {

        explicit impl(primitive p) : storage_{std::move(p)} {
        }

        std::string_view name() const {
            return get_name(storage_);
        }

        int port(unsigned ix) {
            return get_port(storage_, ix);
        }

        void port(unsigned ix, int val) {
            set_port(storage_, ix, val);
        }

    private:
        primitive storage_;
    };

}


#endif //CIRCUITSIM_COMPONENT_HH
