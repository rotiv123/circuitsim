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
                : name_{std::move(name)}, ports_{} {
            std::fill(std::begin(ports_), std::end(ports_), default_port_value<Derived>);
        }

        std::string_view name() const {
            return name_;
        }

        int port(unsigned ix) const {
            return ix < NPorts ? ports_[ix] : -1;
        }

        void port(unsigned ix, int val) {
            ports_[ix] = val;
        }

        static constexpr std::string_view symbol() {
            return component_traits<Derived>::symbol();
        }

        constexpr bool can_stamp() const {
            return has_stamp_fn<Derived>;
        }

        void stamp(dc_context_view &ctx) const {
            do_stamp(*static_cast<const Derived *>(this), ctx);
        }

    private:
        std::string name_;
        std::array<int, NPorts> ports_;
    };
}


#endif //PROJECT_BASIC_COMPONENT_HH
