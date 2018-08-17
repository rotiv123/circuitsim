//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_HH
#define CIRCUITSIM_COMPONENT_HH

#include "../component.hpp"
#include "../dc_context.hpp"
#include "primitives.hh"

namespace circuitsim {

    template<class T>
    class mutator {};

    template<>
    struct mutator<component> {
        static void port(component &c, unsigned ix, int val) {
            c.port(ix, val);
        }

        static void value(component &c, double val) {
            c.value(val);
        }
    };

    struct component::impl {

        explicit impl(primitive p) : storage_{std::move(p)} {
        }

        std::string_view symbol() const {
            return get_symbol(storage_);
        }

        std::string_view name() const {
            return get_name(storage_);
        }

        int port(unsigned ix) const {
            return get_port(storage_, ix);
        }

        void port(unsigned ix, int val) {
            set_port(storage_, ix, val);
        }

        void stamp(dc_context &ctx) const {
            circuitsim::stamp(storage_, ctx);
        }

        double value() const {
            return get_value(storage_);
        }

        void value(double val) {
            set_value(storage_, val);
        }

    private:
        primitive storage_;
    };

}


#endif //CIRCUITSIM_COMPONENT_HH
