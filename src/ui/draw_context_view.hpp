//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_DRAW_CONTEXT_VIEW_HPP
#define CIRCUITSIM_DRAW_CONTEXT_VIEW_HPP

#include <circuitsim/config/export.h>
#include <string_view>

namespace circuitsim::ui {

    class CIRCUITSIM_API draw_context_view {
    public:
        struct CIRCUITSIM_INTERNAL concept;

        CIRCUITSIM_INTERNAL explicit draw_context_view(concept *) noexcept;

        void line(float x1, float y1, float x2, float y2);

        void rect(float x, float y, float w, float h);

        void circle(float cx, float cy, float r);

    private:

        concept *impl_;
    };
}


#endif //CIRCUITSIM_DRAW_CONTEXT_VIEW_HPP
