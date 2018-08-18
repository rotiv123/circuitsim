//
// Created by vitor on 15-08-2018.
//

#include "component_view.hpp"
#include "private/component.hh"

namespace circuitsim {

    component_view::component_view(const impl *inner) noexcept
            : impl_{inner} {
    }

    component_view::component_view(const component_view &) noexcept = default;

    component_view::~component_view() = default;

    std::string_view component_view::symbol() const {
        return impl_->symbol();
    }

    std::string_view component_view::name() const {
        return impl_->name();
    }

    double component_view::value() const {
        return impl_->value();
    }

    int component_view::port(unsigned ix) const {
        return impl_->port(ix);
    }

    void component_view::stamp(dc_context &ctx) const {
        impl_->stamp(ctx);
    }
}