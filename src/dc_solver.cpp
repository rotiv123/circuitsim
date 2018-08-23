//
// Created by vitor on 15-08-2018.
//

#include "dc_solver.hpp"
#include "circuit.hpp"
#include "private/dc_solver.hh"

namespace circuitsim {

    dc_solver::dc_solver() noexcept : impl_{std::make_unique<impl>()} {}

    dc_solver::dc_solver(dc_solver &&) noexcept = default;

    dc_solver::~dc_solver() = default;

    dc_solver &dc_solver::operator=(dc_solver &&) noexcept = default;

    bool dc_solver::solve(const circuit &c) {
        return impl_->solve(c);
    }

    void dc_solver::visit(const std::function<void(const data_point &)> &f) const {
        impl_->visit(f);
    }
}