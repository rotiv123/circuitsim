//
// Created by vitor on 15-08-2018.
//

#include <private/component.hh>
#include "component_factory.hpp"
#include "private/component_factory.hh"

namespace circuitsim {

    component_factory::component_factory() noexcept
            : impl_{std::make_unique<impl>()} {

    }

    component_factory::component_factory(component_factory &&) noexcept = default;

    component_factory::~component_factory() = default;

    component component_factory::create(std::string_view symbol, std::string name) const {
        return component{std::make_unique<component::impl>(impl_->create(symbol, std::move(name)))};
    }
}