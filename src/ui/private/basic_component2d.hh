//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_BASIC_COMPONENT2D_HH
#define CIRCUITSIM_BASIC_COMPONENT2D_HH

#include <string>
#include "../point2d.hpp"
#include "../../private/component_traits.hh"

namespace circuitsim::ui {

    class draw_context_view;

    template<class Derived, class Base>
    class basic_component2d : public Base {
    public:
        explicit basic_component2d(std::string name)
                : Base{std::move(name)}, position_{}, rotation_{} {

        }

        const point2d &position() const {
            return position_;
        }

        void position(point2d val) {
            position_ = std::move(val);
        }

        int rotation() const {
            return rotation_;
        }

        void rotation(int val) {
            rotation_ = val;
        }

        void draw(draw_context_view &ctx) const {
            return component_traits<Derived>::draw(ctx);
        }

    private:
        point2d position_;
        int rotation_;
    };

}


#endif //CIRCUITSIM_BASIC_COMPONENT2D_HH
