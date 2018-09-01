//
// Created by vitor on 23-08-2018.
//

#include "circuit2d_painter.hpp"
#include "ui/private/circuit2d_painter.hh"

namespace circuitsim::ui {

    circuit2d_painter::circuit2d_painter() noexcept : impl_{std::make_unique<impl>()} {}

    circuit2d_painter::circuit2d_painter(circuit2d_painter &&) noexcept = default;

    circuit2d_painter::~circuit2d_painter() = default;

    circuit2d_painter &circuit2d_painter::operator=(circuit2d_painter &&) noexcept = default;

    void circuit2d_painter::draw(const circuit2d &c, draw_context_view &ctx) {
        impl_->draw(c, ctx);
    }

}