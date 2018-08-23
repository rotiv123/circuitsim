//
// Created by vitor on 22-08-2018.
//

#include "component2d_view.hpp"
#include "private/component2d_view.hh"

namespace circuitsim::ui {

    component2d_view::component2d_view(const concept *inner) noexcept
            : component_view{inner} {
    }

    const point2d &component2d_view::position() const {
        return reinterpret_cast<const concept *>(impl_)->position();
    }
}