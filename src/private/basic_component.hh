//
// Created by vitor on 13-08-2018.
//

#ifndef PROJECT_BASIC_COMPONENT_HH
#define PROJECT_BASIC_COMPONENT_HH

#include <cassert>
#include <array>
#include <algorithm>
#include <string>

namespace circuitsim {

    template<class Component>
    struct component_traits {
        static constexpr std::string_view symbol() {
            return Component::symbol();
        }
    };

    template<class Derived, std::size_t NPorts>
    struct basic_component {
        explicit basic_component(std::string name) noexcept
                : name_{std::move(name)}, ports_{}, value_{} {
            std::fill(std::begin(ports_), std::end(ports_), -1);
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
            return ports_[ix];
        }

        void port(unsigned ix, int val) {
            ports_[ix] = val;
        }

        std::string_view symbol() const {
            return component_traits<Derived>::symbol();
        }

    private:
        std::string name_;
        std::array<int, NPorts> ports_;
        double value_;
    };

}


#endif //PROJECT_BASIC_COMPONENT_HH
