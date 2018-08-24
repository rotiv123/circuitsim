//
// Created by vitor on 23-08-2018.
//

#include "svg_painter.hpp"
#include "ui/private/svg_painter.hh"

namespace circuitsim::ui {

    svg_painter::svg_painter() noexcept : impl_{std::make_unique<impl>()} {}

    svg_painter::svg_painter(svg_painter &&) noexcept = default;

    svg_painter::~svg_painter() = default;

    svg_painter &svg_painter::operator=(svg_painter &&) noexcept = default;

    std::string svg_painter::draw(const circuit2d &c) {
        return impl_->draw(c);
    }

}