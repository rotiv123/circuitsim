//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_CIRCUIT2D_PAINTER_HH
#define CIRCUITSIM_CIRCUIT2D_PAINTER_HH

#include "ui/circuit2d_painter.hpp"
#include "../circuit2d.hpp"
#include "draw_context_view.hh"
#include "point2d.hh"

namespace circuitsim::ui {

    class circuit2d_painter::impl {
    public:
        void draw(const circuit2d &c, draw_context_view &ctx) {
            c.visit([&](const component2d_view &x) {
                auto[px, py] =  x.position();
                ctx.begin(px, py, x.rotation());
                x.draw(ctx);
                ctx.end();
            });
        }
    };
}


#endif //CIRCUITSIM_CIRCUIT2D_PAINTER_HH
