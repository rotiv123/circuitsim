//
// Created by vitor on 25-08-2018.
//

#ifndef CIRCUITSIM_BASIC_RESISTOR2D_HH
#define CIRCUITSIM_BASIC_RESISTOR2D_HH


#include <initializer_list>
#include "drawable.hh"
#include "with_position.hh"
#include "rotatable.hh"
#include "../../private/basic_resistor.hh"
#include "draw_context_view.hh"

namespace circuitsim::ui {

    template<class Derived>
    class basic_resistor2d
            : public rotatable<Derived, with_position<Derived, drawable<Derived, basic_resistor<Derived>>>> {
    public:
        using base = rotatable<Derived, with_position<Derived, drawable<Derived, basic_resistor<Derived>>>>;
        using base::base;
    };

    template<class Derived>
    struct resistor2d_traits : public resistor_traits<Derived> {

        static constexpr std::initializer_list<ui::point2d> ports() {
            return {{-2, 0},
                    {2,  0}};
        }

        static void draw(const Derived &, ui::draw_context_view &ctx) {
            ctx.line(-2, 0, -1.4f, 0);
            ctx.rect(-1.4f, -0.3f, 2.8f, 0.6f);
            ctx.line(1.4f, 0, 2, 0);
        }
    };
}

#endif //CIRCUITSIM_BASIC_RESISTOR2D_HH
