//
// Created by vitor on 25-08-2018.
//

#ifndef CIRCUITSIM_WITH_VALUE_HH
#define CIRCUITSIM_WITH_VALUE_HH

#include <cassert>
#include <string>
#include "component_traits.hh"

namespace circuitsim {

    template<class T>
    double value(const T &) {
        return 0;
    }

    template<class T>
    void value(T &, double) {
    }

    template<class Derived, class Base>
    struct component_with_value : public Base {
        explicit component_with_value(std::string name) noexcept
                : Base{std::move(name)}, value_{default_value < Derived > } {
        }

        friend double value(const Derived &x) {
            return x.value_;
        }

        friend void value(Derived &x, double val) {
            assert(val != 0);
            x.value_ = val;
        }

    private:
        double value_;
    };
}

#endif //CIRCUITSIM_WITH_VALUE_HH
