//
// Created by vitor on 12-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_FACTORY_HH
#define CIRCUITSIM_COMPONENT_FACTORY_HH

#include <cassert>
#include <string>
#include <functional>
#include <unordered_map>
#include "primitives.hh"
#include "../component_factory.hpp"
#include "component.hh"

namespace circuitsim {

    template <class T> class basic_circuit;
    using primitive_creator = std::function<primitive(std::string)>;

    struct component_factory::impl {

        using component_type = component_view::impl;

        impl() noexcept : blue_prints_{} {
            blue_prints_[component_traits<resistor>::symbol()] = [](std::string &&name) {
                return make_primitive<resistor>(std::move(name));
            };
            blue_prints_[component_traits<voltage_source>::symbol()] = [](std::string &&name) {
                return make_primitive<voltage_source>(std::move(name));
            };
        }

        component_view::impl create(std::string_view symbol, std::string name) const {
            return component_view::impl{blue_prints_.at(symbol)(std::move(name))};
        }

    private:
        friend class basic_circuit<component_factory::impl>;
        std::unordered_map<std::string_view, primitive_creator> blue_prints_;
    };

}


#endif //CIRCUITSIM_COMPONENT_FACTORY_HH
