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

namespace circuitsim {

    using primitive_creator = std::function<primitive(std::string)>;

    struct component_factory::impl {

        impl() noexcept : blue_prints_{} {
            blue_prints_[ground::symbol()] = [](std::string &&name) {
                return make_primitive<ground>(std::move(name));
            };
            blue_prints_[resistor::symbol()] = [](std::string &&name) {
                return make_primitive<resistor>(std::move(name));
            };
            blue_prints_[voltage_source::symbol()] = [](std::string &&name) {
                return make_primitive<voltage_source>(std::move(name));
            };
        }

        primitive create(std::string_view symbol, std::string name) const {
            return blue_prints_.at(symbol)(std::move(name));
        }

    private:
        std::unordered_map<std::string_view, primitive_creator> blue_prints_;
    };

}


#endif //CIRCUITSIM_COMPONENT_FACTORY_HH
