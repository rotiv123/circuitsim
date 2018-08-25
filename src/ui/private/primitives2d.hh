//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_PRIMITIVES2D_HH
#define CIRCUITSIM_PRIMITIVES2D_HH

#include <variant>
#include "ground2d.hh"
#include "wire2d.hh"
#include "resistor2d.hh"
#include "voltage_source2d.hh"

namespace circuitsim::ui {

    class draw_context_view;

    using primitive2d = std::variant<ground2d, wire2d, resistor2d, voltage_source2d>;

    template<class T, typename ...Args>
    primitive2d make_primitive2d(Args ...args) {
        return primitive2d{T{std::forward<Args>(args)...}};
    }

    template<class Primitive2d>
    const point2d &get_position(const Primitive2d &c) {
        return std::visit([](const auto &x) -> const auto & { return x.position(); }, c);
    }

    template<class Primitive2d>
    void set_position(Primitive2d &c, point2d val) {
        std::visit([=](auto &x) { x.position(val); }, c);
    }

    template<class Primitive2d>
    point2d get_position(const Primitive2d &c, unsigned ix) {
        return std::visit([=](const auto &x) -> auto { return x.position(ix); }, c);
    }

    template<class Primitive2d>
    void set_position(Primitive2d &c, unsigned ix, point2d val) {
        std::visit([=](auto &x) { x.position(ix, val); }, c);
    }

    template<class Primitive2d>
    int get_rotation(const Primitive2d &c) {
        return std::visit([](const auto &x) { return x.rotation(); }, c);
    }

    template<class Primitive2d>
    void set_rotation(Primitive2d &c, int val) {
        std::visit([=](auto &x) { x.rotation(val); }, c);
    }

    template<class Primitive2d>
    void draw(const Primitive2d &c, draw_context_view &ctx) {
        std::visit([&](const auto &x) { return x.draw(ctx); }, c);
    }

}


#endif //CIRCUITSIM_PRIMITIVES2D_HH
