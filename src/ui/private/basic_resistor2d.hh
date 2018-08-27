//
// Created by vitor on 25-08-2018.
//

#ifndef CIRCUITSIM_BASIC_RESISTOR2D_HH
#define CIRCUITSIM_BASIC_RESISTOR2D_HH

#include <array>
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

        using points_type = std::array<ui::point2d, 2>;

        static const points_type &ports() {
            static constexpr points_type t{ui::point2d{-2, 0},
                                           ui::point2d{2, 0}};
            return t;
        }

        static const points_type &hints() {
            static constexpr points_type t{ui::point2d{-1, 0},
                                           ui::point2d{1, 0}};
            return t;
        }

        static void draw(const Derived &, ui::draw_context_view &ctx) {
            ctx.line(-2, 0, -1.4f, 0);
            ctx.rect(-1.4f, -0.3f, 2.8f, 0.6f);
            ctx.line(1.4f, 0, 2, 0);
        }
    };
}

#endif //CIRCUITSIM_BASIC_RESISTOR2D_HH
