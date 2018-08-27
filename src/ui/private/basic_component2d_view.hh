//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_BASIC_COMPONENT2D_VIEW_HH
#define CIRCUITSIM_BASIC_COMPONENT2D_VIEW_HH

#include "../point2d.hpp"
#include "../../private/basic_component_view.hh"

namespace circuitsim::ui {

    class draw_context_view;

    template<class Primitive2d>
    void draw(const Primitive2d &c, draw_context_view &ctx);

    template<class Primitive2d, class Concept>
    struct basic_component2d_view : public basic_component_view<Primitive2d, Concept> {
        using base = basic_component_view<Primitive2d, Concept>;
        using base::base;

        point2d position() const {
            return get_position(*base::impl_);
        }

        int rotation() const {
            return get_rotation(*base::impl_);
        }

        void draw(draw_context_view &ctx) const {
            circuitsim::ui::draw(*base::impl_, ctx);
        }
    };

}


#endif //CIRCUITSIM_BASIC_COMPONENT2D_VIEW_HH
