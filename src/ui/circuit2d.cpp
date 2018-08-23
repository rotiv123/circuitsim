//
// Created by vitor on 22-08-2018.
//

#include "circuit2d.hpp"
#include "component2d_view.hpp"
#include "private/circuit2d.hh"

namespace circuitsim::ui {

    circuit2d::circuit2d() noexcept
            : circuit2d{std::make_unique<impl>()} {
    }

    circuit2d::circuit2d(std::unique_ptr<concept> &&x) noexcept
            : circuit{std::unique_ptr<circuit::concept>{x.get()}},
              impl_{x.release()} {

    }

    circuit2d::circuit2d(circuit2d &&) noexcept = default;

    circuit2d::~circuit2d() = default;

    void circuit2d::visit(const std::function<void(const component2d_view &)> &f) const {
        impl_->visit(f);
    }

}