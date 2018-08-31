//
// Created by vitor on 25-08-2018.
//

#ifndef CIRCUITSIM_BASIC_VOLTAGE_SOURCE2D_HH
#define CIRCUITSIM_BASIC_VOLTAGE_SOURCE2D_HH

#include <array>
#include "drawable.hh"
#include "with_position.hh"
#include "rotatable.hh"
#include "../../private/basic_voltage_source.hh"
#include "draw_context_view.hh"
#include "component2d_traits.hh"

namespace circuitsim::ui {

    template<class Derived>
    class basic_voltage_source2d :
            public rotatable<Derived, with_position < Derived, drawable < Derived, basic_voltage_source < Derived>>

    >> {
    public:
    using base = rotatable <Derived, with_position<Derived, drawable < Derived, basic_voltage_source < Derived>>>>;
    using base::base;
};

template<class Derived>
struct voltage_source2d_traits :
        public component2d_traits<Derived, voltage_source_traits < Derived>> {

using points_type = std::array<ui::point2d, 2>;

static const points_type &ports() {
    static constexpr points_type t{ui::point2d{0, 2},
                                   ui::point2d{0, -2}};
    return t;
}

static const points_type &hints() {
    static constexpr points_type t{ui::point2d{0, 1},
                                   ui::point2d{0, -1}};
    return t;
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
