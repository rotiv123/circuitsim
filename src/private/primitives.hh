//
// Created by vitor on 12-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_VAR_T_HH
#define CIRCUITSIM_COMPONENT_VAR_T_HH

#include <variant>
#include "ground.hh"
#include "resistor.hh"
#include "voltage_source.hh"

namespace circuitsim {

    using primitive = std::variant<ground, resistor, voltage_source>;

    template<class T, typename ...Args>
    primitive make_primitive(Args ...args) {
        return primitive{T{std::forward<Args>(args)...}};
    }

    inline std::string_view get_name(const primitive &c) {
        return std::visit([](const auto &x) { return x.name(); }, c);
    }

    inline int get_port(const primitive &c, unsigned ix) {
        return std::visit([=](const auto &x) { return x.port(ix); }, c);
    }

    inline void set_port(primitive &c, unsigned ix, int val) {
        std::visit([=](auto &x) { return x.port(ix, val); }, c);
    }
}


#endif //CIRCUITSIM_COMPONENT_VAR_T_HH
