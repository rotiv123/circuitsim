//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_RESISTOR2D_HH
#define CIRCUITSIM_RESISTOR2D_HH

#include <initializer_list>
#include "basic_component2d.hh"
#include "../../private/resistor.hh"
#include "../draw_context_view.hpp"

namespace circuitsim {
    namespace ui {

        class resistor2d : public basic_component2d<resistor2d, resistor> {
        public:
            using base = basic_component2d<resistor2d, resistor>;
            using base::base;
        };

    }

    template<>
    struct component_traits<ui::resistor2d> : public component_traits<resistor> {

        static constexpr std::initializer_list<ui::point2d> ports() {
            return {{-2, 0},
                    {2,  0}};
        }

        static void draw(const ui::resistor2d &, ui::draw_context_view &ctx) {
            ctx.line(-2, 0, -1.4f, 0);
            ctx.rect(-1.4f, -0.3f, 2.8f, 0.6f);
            ctx.line(1.4f, 0, 2, 0);
        }
    };
}


#endif //CIRCUITSIM_RESISTOR2D_HH
