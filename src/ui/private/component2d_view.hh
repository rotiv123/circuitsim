//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT2D_VIEW_HH
#define CIRCUITSIM_COMPONENT2D_VIEW_HH

#include "../component2d_view.hpp"
#include "../../private/component_view.hh"
#include "basic_component2d_view.hh"
#include "primitives2d.hh"

namespace circuitsim::ui {

    struct component2d_view::concept : public component_view::concept {
        virtual const point2d &position() const = 0;

        virtual int rotation() const = 0;

        virtual void draw(draw_context_view &ctx) const = 0;
    };

    struct component2d_view_model : public basic_component2d_view<primitive2d, component2d_view::concept> {
        using base =  basic_component2d_view<primitive2d, component2d_view::concept>;
        using base::base;
    };
}


#endif //CIRCUITSIM_COMPONENT2D_VIEW_HH
