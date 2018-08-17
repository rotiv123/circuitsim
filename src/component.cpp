//
// Created by vitor on 15-08-2018.
//

#include "component.hpp"
#include "private/component.hh"

namespace circuitsim {

    component::component(std::unique_ptr<impl> inner) noexcept
            : impl_{inner.release()} {
    }

    component::component(component &&) noexcept = default;

    component::~component() = default;

    std::string_view component::symbol() const {
        return impl_->symbol();
    }

    std::string_view component::name() const {
        return impl_->name();
    }

    double component::value() const {
        return impl_->value();
    }

    int component::port(unsigned ix) const {
        return impl_->port(ix);
    }

    void component::port(unsigned ix, int val) {
        impl_->port(ix, val);
    }

    void component::stamp(dc_context &ctx) const {
        impl_->stamp(ctx);
    }

    void component::value(double val) {
        impl_->value(val);
    }
}