//
// Created by vitor on 15-08-2018.
//

#include "component_view.hpp"
#include "private/component_view.hh"

namespace circuitsim {

    component_view::component_view(const concept *inner) noexcept
            : impl_{inner} {
    }

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

    bool component_view::can_stamp() const {
        return impl_->can_stamp();
    }

    void component_view::stamp(dc_context_view &ctx) const {
        impl_->stamp(ctx);
    }
}