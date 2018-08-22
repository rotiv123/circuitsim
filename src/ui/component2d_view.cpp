//
// Created by vitor on 22-08-2018.
//

#include "component2d_view.hpp"
#include "private/component2d.hh"

namespace circuitsim::ui {

    component2d_view::component2d_view(const component2d *inner) noexcept
            : src_{inner} {
    }

    component2d_view::component2d_view(const component2d_view &) noexcept = default;

    component2d_view::~component2d_view() = default;
}