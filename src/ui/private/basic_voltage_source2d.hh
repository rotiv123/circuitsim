//
// Created by vitor on 25-08-2018.
//

#ifndef CIRCUITSIM_BASIC_VOLTAGE_SOURCE2D_HH
#define CIRCUITSIM_BASIC_VOLTAGE_SOURCE2D_HH


#include "drawable.hh"
#include "with_position.hh"
#include "../../private/basic_voltage_source.hh"
#include "draw_context_view.hh"

namespace circuitsim::ui {

    template<class Derived>
    class basic_voltage_source2d : public with_position<Derived, drawable < Derived, basic_voltage_source < Derived>>

    > {
    public:
    using base = with_position <Derived, drawable<Derived, basic_voltage_source < Derived>>>;
    using base::base;
};

template<class Derived>
struct voltage_source2d_traits : public voltage_source_traits<Derived> {

    static constexpr std::initializer_list<ui::point2d> ports() {
        return {{0, 2},
                {0, -2}};
    }

    static void draw(const Derived &, ui::draw_context_view &ctx) {
        ctx.circle(0, 0, 1.2f);
        ctx.line(0, 1, 0, 0.3f);
        ctx.line(-0.35f, 0.65f, 0.35f, 0.65f);
        ctx.line(-0.35f, -0.65f, 0.35f, -0.65f);
        ctx.line(0, 2, 0, 1.2f);
        ctx.line(0, -2, 0, -1.2f);
    }
};
}


#endif //CIRCUITSIM_BASIC_VOLTAGE_SOURCE2D_HH
