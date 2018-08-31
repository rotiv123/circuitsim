//
// Created by vitor on 24-08-2018.
//

#ifndef CIRCUITSIM_GOUND2D_HH
#define CIRCUITSIM_GOUND2D_HH

#include <array>
#include "../point2d.hpp"
#include "../../private/basic_component.hh"
#include "drawable.hh"
#include "with_position.hh"
#include "draw_context_view.hh"
#include "component2d_traits.hh"

namespace circuitsim {
    namespace ui {
        class ground2d final : public with_position<ground2d, drawable<ground2d, basic_component<ground2d, 1>>> {
        public:
            using base = with_position<ground2d, drawable<ground2d, basic_component<ground2d, 1>>>;
            using base::base;
        };
    }

    template<>
    struct component_traits<ui::ground2d> final : public ui::component2d_traits<ui::ground2d> {

        static constexpr std::string_view symbol() {
            return "*Ground*";
        }

        static constexpr int default_port_value() {
            return 0;
        }

        using points_type = std::array<ui::point2d, 1>;

        static const points_type &ports() {
            static constexpr points_type t{ui::point2d{0, 1}};
            return t;
        }

        static const points_type &hints() {
            static constexpr points_type t{ui::point2d{0, 1}};
            return t;
        }

        static void draw(const ui::ground2d &, ui::draw_context_view &ctx) {
            ctx.line(0, 1, 0, 0);
            ctx.line(-0.7f, 0, 0.7f, 0);
            ctx.line(-0.5f, -0.2f, 0.5f, -0.2f);
            ctx.line(-0.2f, -0.4f, 0.2f, -0.4f);
        }
    };
}


#endif //CIRCUITSIM_GOUND2D_HH
