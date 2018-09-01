//
// Created by vitor on 31-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT2D_TRAITS_HH
#define CIRCUITSIM_COMPONENT2D_TRAITS_HH

#include <tuple>
#include <algorithm>
#include "point2d.hh"
#include "draw_context_view.hh"
#include "AABB.hh"

namespace circuitsim::ui {

    struct bb_context_view_model final : public draw_context_view::concept {

        void begin(float, float, float) final {
            min_ = {};
            max_ = {};
        }

        void line(float x1, float y1, float x2, float y2) final {
            update_min_max(x1, y1);
            update_min_max(x2, y2);
        }

        void rect(float x, float y, float w, float h) final {
            update_min_max(x, y);
            update_min_max(x + w, y + h);
        }

        void circle(float cx, float cy, float r) final {
            update_min_max(cx - r, cy + r);
            update_min_max(cx + r, cy + r);
            update_min_max(cx - r, cy - r);
            update_min_max(cx + r, cy - r);
        }

        void end() final {
        }

        AABB end_g(point2d p, int r) {
            auto[x, y] = rotate(p, r);
            auto[minx, miny] = min_;
            auto[maxx, maxy] = max_;
            return {minx + x, miny + y, maxx + x, maxy + y};
        }

    private:
        std::tuple<float, float> min_, max_;

        void update_min_max(float x, float y) {
            auto&[minx, miny] = min_;
            auto&[maxx, maxy] = max_;
            minx = std::min(minx, x);
            maxx = std::max(maxx, x);
            miny = std::min(miny, y);
            maxy = std::max(maxy, y);
        }
    };

    template<class Component2D>
    AABB bbox(const Component2D &src) {
        bb_context_view_model ctx{};
        draw_context_view ctx_view{&ctx};
        ctx.begin(0, 0, 0);
        Component2D::draw(ctx_view);
        return ctx.end_g(src.position(), src.rotation());
    }

    template<class Derived, class Base = void>
    struct component2d_traits : public Base {
        static AABB bbox(const Derived &src) {
            return circuitsim::ui::bbox(src);
        }
    };

    template<class Derived>
    struct component2d_traits<Derived, void> {
        static AABB bbox(const Derived &src) {
            return circuitsim::ui::bbox(src);
        }
    };
}

#endif //CIRCUITSIM_COMPONENT2D_TRAITS_HH
