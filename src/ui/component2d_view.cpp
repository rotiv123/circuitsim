//
// Created by vitor on 22-08-2018.
//

#include "component2d_view.hpp"
#include "private/component2d_view.hh"

namespace circuitsim::ui {

    component2d_view::component2d_view(const impl *inner) noexcept
            : component_view{inner} {
    }
}