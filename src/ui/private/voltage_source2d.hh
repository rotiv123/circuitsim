//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_VOLTAGE_SOURCE2D_HH
#define CIRCUITSIM_VOLTAGE_SOURCE2D_HH


#include "basic_component2d.hh"
#include "../../private/voltage_source.hh"
#include "../draw_context_view.hpp"

namespace circuitsim {
    namespace ui {

        class voltage_source2d : public basic_component2d<voltage_source2d, voltage_source> {
        public:
            using base = basic_component2d<voltage_source2d, voltage_source>;
            using base::base;
        };
    }

    template<>
    struct component_traits<ui::voltage_source2d> : public component_traits<voltage_source> {

        static constexpr std::initializer_list<ui::point2d> ports() {
            return {{0, 2},
                    {0, -2}};
        }

        static void draw(const ui::voltage_source2d &, ui::draw_context_view &ctx) {
            ctx.circle(0, 0, 1.2f);
            ctx.line(0, 1, 0, 0.3f);
            ctx.line(-0.35f, 0.65f, 0.35f, 0.65f);
            ctx.line(-0.35f, -0.65f, 0.35f, -0.65f);
            ctx.line(0, 2, 0, 1.2f);
            ctx.line(0, -2, 0, -1.2f);
        }
    };
}


#endif //CIRCUITSIM_VOLTAGE_SOURCE2D_HH
