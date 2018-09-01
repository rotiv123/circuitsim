//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_DRAW_CONTEXT_VIEW_HPP
#define CIRCUITSIM_DRAW_CONTEXT_VIEW_HPP

#include <circuitsim/config/export.h>

namespace circuitsim::ui {

    class CIRCUITSIM_API draw_context_view {
    public:

        struct CIRCUITSIM_API concept {
            virtual ~concept() = default;

            virtual void begin(float x, float y, float r) = 0;

            virtual void line(float x1, float y1, float x2, float y2) = 0;

            virtual void rect(float x, float y, float w, float h) = 0;

            virtual void circle(float cx, float cy, float r) = 0;

            virtual void end() = 0;
        };

        explicit draw_context_view(concept *) noexcept;

        void begin(float x, float y, float r);

        void line(float x1, float y1, float x2, float y2);

        void rect(float x, float y, float w, float h);

        void circle(float cx, float cy, float r);

        void end();

    private:

        concept *impl_;
    };
}


#endif //CIRCUITSIM_DRAW_CONTEXT_VIEW_HPP
