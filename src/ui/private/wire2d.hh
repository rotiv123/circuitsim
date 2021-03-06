//
// Created by vitor on 24-08-2018.
//

#ifndef CIRCUITSIM_WIRE2D_HH
#define CIRCUITSIM_WIRE2D_HH

#include "../point2d.hpp"
#include "../../private/basic_component.hh"
#include "drawable.hh"
#include "draw_context_view.hh"
#include "component2d_traits.hh"

namespace circuitsim {
    namespace ui {

        class wire2d final : public drawable<wire2d, basic_component < wire2d, 0>>

    {
        public:
        using base = drawable <wire2d, basic_component<wire2d, 0>>;
        using base::base;

        const point2d &end1() const {
            return end1_;
        }

        const point2d &end2() const {
            return end2_;
        }

        friend point2d position(const wire2d &x, unsigned ix) {
            return ix == 0 ? x.end1_ : x.end2_;
        }

        friend void position(wire2d &x, unsigned ix, point2d val) {
            if (ix == 0) {
                x.end1_ = val;
            } else {
                x.end2_ = val;
            }
        }

        friend point2d hint(const wire2d &, unsigned) {
            // TODO calc wire hint vec for port ix
            return point2d{};
        }

        private:
        point2d end1_;
        point2d end2_;
    };
}

template<>
struct component_traits<ui::wire2d> final : public ui::component2d_traits<ui::wire2d> {

    static constexpr std::string_view symbol() {
        return "*Wire*";
    }

    static void draw(const ui::wire2d &src, ui::draw_context_view &ctx) {
        auto[x1, y1] = src.end1();
        auto[x2, y2] = src.end2();
        ctx.line(x1, y1, x2, y2);
    }
};
}


#endif //CIRCUITSIM_WIRE2D_HH
