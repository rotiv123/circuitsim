//
// Created by vitor on 15-08-2018.
//

#include "component_factory.hpp"
#include "private/component_factory.hh"

namespace circuitsim {

    component_factory::component_factory() noexcept
            : impl_{std::make_unique<impl>()} {

    }

    component_factory::component_factory(component_factory &&) noexcept = default;

    component_factory::~component_factory() = default;

    component_factory &component_factory::operator=(component_factory &&) noexcept = default;
}