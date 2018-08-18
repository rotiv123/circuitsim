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

    bool dc_solver::solve(const circuit &c) const {
        return impl_->solve(c);
    }
}