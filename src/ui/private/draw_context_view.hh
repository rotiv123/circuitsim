//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_DRAW_CONTEXT_VIEW_HH
#define CIRCUITSIM_DRAW_CONTEXT_VIEW_HH

#include "../draw_context_view.hpp"

namespace circuitsim::ui {

    struct draw_context_view::concept {
        virtual ~concept() = default;

        virtual void line(float x1, float y1, float x2, float y2) = 0;

        virtual void rect(float x, float y, float w, float h) = 0;
    };

}

#endif //CIRCUITSIM_DRAW_CONTEXT_VIEW_HH
