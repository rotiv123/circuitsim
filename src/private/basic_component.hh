//
// Created by vitor on 13-08-2018.
//

#ifndef PROJECT_BASIC_COMPONENT_HH
#define PROJECT_BASIC_COMPONENT_HH

#include <cassert>
#include <array>
#include <algorithm>
#include <string>
#include "component_traits.hh"

namespace circuitsim {

    class dc_context_view;

    template<class Derived, std::size_t NPorts>
    struct basic_component {
        explicit basic_component(std::string name) noexcept
                : name_{std::move(name)}, ports_{}, value_{default_value()} {
            std::fill(std::begin(ports_), std::end(ports_), default_port_value());
        }

        std::string_view name() const {
            return name_;
        }

        double value() const {
            return value_;
        }

        void value(double val) {
            assert(val != 0);
            value_ = val;
        }

        int port(unsigned ix) const {
            return ix < NPorts ? ports_[ix] : default_port_value();
        }

        void port(unsigned ix, int val) {
            ports_[ix] = val;
        }

        std::string_view symbol() const {
            return component_traits<Derived>::symbol();
        }

        constexpr bool can_stamp() const {
            return has_stamp_fn_v<Derived>;
        }

        void stamp(dc_context_view &ctx) const {
            component_traits<Derived>::stamp(*static_cast<const Derived *>(this), ctx);
        }

    private:
        std::string name_;
        std::array<int, NPorts> ports_;
        double value_;

        constexpr static double default_value() {
            return default_value_v<Derived>;
        }

        constexpr static int default_port_value() {
            return default_port_value_v<Derived>;
        }
    };
}


#endif //PROJECT_BASIC_COMPONENT_HH
