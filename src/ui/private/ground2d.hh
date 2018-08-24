//
// Created by vitor on 24-08-2018.
//

#ifndef CIRCUITSIM_GOUND2D_HH
#define CIRCUITSIM_GOUND2D_HH

#include "basic_component2d.hh"
#include "draw_context_view.hh"

namespace circuitsim {
    namespace ui {
        class ground2d : public basic_component2d<ground2d, basic_component<ground2d, 1>> {
        public:
            using base = basic_component2d<ground2d, basic_component<ground2d, 1>>;
            using base::base;
        };
    }

    template<>
    struct component_traits<ui::ground2d> {

        static constexpr std::string_view symbol() {
            return "0";
        }

        static constexpr int default_port_value() {
            return 0;
        }

        static constexpr std::initializer_list<ui::point2d> ports() {
            return {{0, 1}};
        }

        static constexpr ui::box2d bbox() {
            return {1.4f, 2};
        }

        static void draw(ui::draw_context_view &ctx) {
            ctx.line(0, 1, 0, 0);
            ctx.line(-0.7f, 0, 0.7f, 0);
            ctx.line(-0.5f, -0.2f, 0.5f, -0.2f);
            ctx.line(-0.2f, -0.4f, 0.2f, -0.4f);
        }
    };
}


#endif //CIRCUITSIM_GOUND2D_HH
