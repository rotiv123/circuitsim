//
// Created by vitor on 23-08-2018.
//

#include "draw_context_view.hpp"
#include "private/draw_context_view.hh"

namespace circuitsim::ui {

    draw_context_view::draw_context_view(concept *x) noexcept
            : impl_{x} {
    }

    void draw_context_view::line(float x1, float y1, float x2, float y2) {
        impl_->line(x1, y1, x2, y2);
    }

    void draw_context_view::rect(float x, float y, float w, float h) {
        impl_->rect(x, y, w, h);
    }
}