//
// Created by vitor on 16-08-2018.
//

#include "dc_context_view.hpp"
#include "private/dc_context.hh"

namespace circuitsim {

    dc_context_view::dc_context_view(impl *x) noexcept
            : impl_{x} {
    }

    dc_context_view::dc_context_view(dc_context_view &&) noexcept = default;

    dc_context_view::~dc_context_view() = default;

    void dc_context_view::stamp_resistance(int n1, int n2, double r) {
        impl_->stamp_resistance(n1, n2, r);
    }

    void dc_context_view::stamp_voltage(int pn, int nn, double v) {
        impl_->stamp_voltage(pn, nn, v);
    }
}