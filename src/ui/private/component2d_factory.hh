//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT2D_FACTORY_HH
#define CIRCUITSIM_COMPONENT2D_FACTORY_HH


#include <cassert>
#include <string>
#include <functional>
#include <unordered_map>
#include "primitives2d.hh"
#include "../component2d_factory.hpp"

namespace circuitsim::ui {

    using primitive2d_creator = std::function<primitive2d(std::string&&)>;

    class component2d_factory::impl {
    public:
        using component_type = primitive2d;

        impl() noexcept : blue_prints_{} {
            blue_prints_[component_traits<resistor2d>::symbol()] = [](std::string &&name) {
                return make_primitive2d<resistor2d>(std::move(name));
            };
            blue_prints_[component_traits<voltage_source2d>::symbol()] = [](std::string &&name) {
                return make_primitive2d<voltage_source2d>(std::move(name));
            };
        }

        primitive2d create(std::string_view symbol, std::string name) const {
            return blue_prints_.at(symbol)(std::move(name));
        }

    private:

        std::unordered_map<std::string_view, primitive2d_creator> blue_prints_;
    };

}

#endif //CIRCUITSIM_COMPONENT2D_FACTORY_HH
