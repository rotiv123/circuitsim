//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT2D_VIEW_HH
#define CIRCUITSIM_COMPONENT2D_VIEW_HH

#include "../../private/component_view.hh"
#include "../component2d_view.hpp"
#include "component2d_view.hh"
#include "primitives2d.hh"
#include "basic_component2d_view.hh"

namespace circuitsim::ui {

    struct component2d_view::impl : public component_view::impl {

    };

    struct component2d : public basic_component2d_view<primitive2d, component2d_view::impl> {
        using base =  basic_component2d_view<primitive2d, component2d_view::impl>;
        using base::base;
    };
}


#endif //CIRCUITSIM_COMPONENT2D_VIEW_HH
