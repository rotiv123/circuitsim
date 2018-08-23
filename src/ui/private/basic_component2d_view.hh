//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_BASIC_COMPONENT2D_VIEW_HH
#define CIRCUITSIM_BASIC_COMPONENT2D_VIEW_HH

#include "../point2d.hpp"
#include "../../private/basic_component_view.hh"

namespace circuitsim::ui {

    template<class Primitive, class Concept>
    struct basic_component2d_view : public basic_component_view<Primitive, Concept> {
        using base = basic_component_view<Primitive, Concept>;
        using base::base;

        const point2d &position() const {
            return get_position(*base::impl_);
        }
    };

}


#endif //CIRCUITSIM_BASIC_COMPONENT2D_VIEW_HH
