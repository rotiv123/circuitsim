//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_BASIC_COMPONENT2D_HH
#define CIRCUITSIM_BASIC_COMPONENT2D_HH

#include <string>
#include "../../private/component_traits.hh"
#include "point2d.hh"

namespace circuitsim::ui {

    class draw_context_view;

    template<class T, class Traits = component_traits<T>>
    point2d hint(const T &x, unsigned ix) {
        return ix < Traits::hints().size() ? Traits::hints()[ix] : point2d{};
    }

    template<class Derived, class Base>
    class drawable : public Base {
    public:
        explicit drawable(std::string name)
                : Base{std::move(name)} {
        }

        void draw(draw_context_view &ctx) const {
            return component_traits<Derived>::draw(*static_cast<const Derived *>(this), ctx);
        }
    };

}


#endif //CIRCUITSIM_BASIC_COMPONENT2D_HH
