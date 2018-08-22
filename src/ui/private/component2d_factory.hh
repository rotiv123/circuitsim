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
#include "component2d.hh"

namespace circuitsim {
    template<class T>
    class basic_circuit;
}

namespace circuitsim::ui {

    using primitive2d_creator = std::function<primitive2d(std::string&&)>;

    class component2d_factory::impl {
    public:
        using component_type = component2d;

        impl() noexcept : blue_prints_{} {
            blue_prints_[component_traits<resistor2d>::symbol()] = [](std::string &&name) {
                return make_primitive2d<resistor2d>(std::move(name));
            };
        }

        component2d create(std::string_view symbol, std::string name) const {
            return component2d{blue_prints_.at(symbol)(std::move(name))};
        }

    private:
        friend class basic_circuit<component2d_factory::impl>;

        std::unordered_map<std::string_view, primitive2d_creator> blue_prints_;
    };

}

#endif //CIRCUITSIM_COMPONENT2D_FACTORY_HH
