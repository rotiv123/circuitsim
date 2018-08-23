//
// Created by vitor on 12-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_VAR_T_HH
#define CIRCUITSIM_COMPONENT_VAR_T_HH

#include <variant>
#include "resistor.hh"
#include "voltage_source.hh"

namespace circuitsim {

    class dc_context_view;
    using primitive = std::variant<resistor, voltage_source>;

    template<class T, typename ...Args>
    primitive make_primitive(Args ...args) {
        return primitive{T{std::forward<Args>(args)...}};
    }

    template <class Primitive>
    std::string_view get_symbol(const Primitive &c) {
        return std::visit([](const auto &x) { return x.symbol(); }, c);
    }

    template <class Primitive>
    std::string_view get_name(const Primitive &c) {
        return std::visit([](const auto &x) { return x.name(); }, c);
    }

    template <class Primitive>
    int get_port(const Primitive &c, unsigned ix) {
        return std::visit([=](const auto &x) { return x.port(ix); }, c);
    }

    template <class Primitive>
    void set_port(Primitive &c, unsigned ix, int val) {
        std::visit([=](auto &x) { x.port(ix, val); }, c);
    }

    template <class Primitive>
    double get_value(const Primitive &c) {
        return std::visit([](const auto &x) { return x.value(); }, c);
    }

    template <class Primitive>
    void set_value(Primitive &c, double val) {
        std::visit([=](auto &x) { x.value(val); }, c);
    }

    template <class Primitive>
    void stamp(const Primitive &c, dc_context_view &ctx) {
        std::visit([&](const auto &x) { return x.stamp(ctx); }, c);
    }
}


#endif //CIRCUITSIM_COMPONENT_VAR_T_HH
