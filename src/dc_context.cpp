//
// Created by vitor on 16-08-2018.
//

#include "dc_context.hpp"
#include "private/dc_context.hh"

namespace circuitsim {

    dc_context::dc_context(std::size_t n, std::size_t m) noexcept
            : impl_{std::make_unique<impl>(n, m)} {

    }

    dc_context::dc_context(dc_context &&) noexcept = default;

    dc_context::~dc_context() = default;

    void dc_context::stamp_resistance(int n1, int n2, double r) {
        impl_->stamp_resistance(n1, n2, r);
    }

    void dc_context::stamp_voltage(int pn, int nn, double v) {
        impl_->stamp_voltage(pn, nn, v);
    }
}