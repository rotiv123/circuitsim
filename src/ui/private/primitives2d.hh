//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_PRIMITIVES2D_HH
#define CIRCUITSIM_PRIMITIVES2D_HH

#include <variant>
#include "resistor2d.hh"

namespace circuitsim::ui {

    using primitive2d = std::variant<resistor2d>;

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

}


#endif //CIRCUITSIM_PRIMITIVES2D_HH
