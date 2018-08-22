//
// Created by vitor on 22-08-2018.
//

#include "component2d_factory.hpp"
#include "private/component2d_factory.hh"
#include "private/component2d.hh"

namespace circuitsim::ui {

    component2d_factory::component2d_factory() noexcept
            : impl_{std::make_unique<impl>()} {

    }

    component2d_factory::component2d_factory(component2d_factory &&) noexcept = default;

    component2d_factory::~component2d_factory() = default;
}