//
// Created by vitor on 24-08-2018.
//

#ifndef CIRCUITSIM_WIRE2D_HH
#define CIRCUITSIM_WIRE2D_HH


#include "basic_component2d.hh"
#include "draw_context_view.hh"

namespace circuitsim {
    namespace ui {
        class wire2d
                : public basic_component2d<wire2d, basic_component < wire2d, 2>>

    {
        public:
        using base = basic_component2d <wire2d, basic_component<wire2d, 2>>;
        using base::base;

        const point2d &end1() const {
            return end1_;
        }

        const point2d &end2() const {
            return end2_;
        }

        void end1(point2d val) {
            end1_ = val;
        }

        void end2(point2d val) {
            end1_ = val;
        }

        private:
        point2d end1_;
        point2d end2_;
    };
}

template<>
struct component_traits<ui::wire2d> {

    static ui::point2d position(const ui::wire2d &x, unsigned ix) {
        return ix == 0 ? x.end1() : x.end2();
    }

    static void position(ui::wire2d &x, unsigned ix, ui::point2d val) {
        if (ix == 0) {
            x.end1(val);
        } else {
            x.end2(val);
        }
    }

    static constexpr std::string_view symbol() {
        return "*Wire*";
    }

    static void draw(ui::draw_context_view &ctx) {

    }
};
}


#endif //CIRCUITSIM_WIRE2D_HH
