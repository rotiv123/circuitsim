//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_BASIC_COMPONENT2D_HH
#define CIRCUITSIM_BASIC_COMPONENT2D_HH

#include <algorithm>
#include <string>
#include "../point2d.hpp"
#include "../../private/basic_component.hh"

namespace circuitsim::ui {

    class draw_context_view;

    namespace detail {
        template<typename Component, class Traits = component_traits <Component>>
        point2d position(const Component &c, unsigned ix,
                         check<point2d (*)(const Component &, unsigned), &Traits::position> *) {
            return Traits::position(c, ix);
        }

        template<typename Component, class Traits = component_traits <Component>>
        point2d position(const Component &c, unsigned ix, ...) {
            auto list = Traits::ports();
            auto i = 0u;
            for (auto it : list) {
                if (i++ == ix) {

                    auto[x, y] = it;
                    auto rot = c.rotation();
                    rot = rot > 0 ? rot % 360 : (360 - (rot % 360));
                    switch (rot) {
                        case 90:
                            std::swap(x, y);
                            break;
                        case 270:
                            std::swap(x, y);
                            y *= -1;
                            break;
                        case 180:
                            x *= -1;
                            break;
                        default:
                            break;
                    }

                    auto[px, py] = c.position();
                    return {px + x, py + y};
                }
            }

            return c.position();
        }

        template<typename Component, class Traits = component_traits <Component>>
        void position(Component &c, unsigned ix, point2d val,
                      check<void (*)(Component &, unsigned, point2d), &Traits::position> *) {
            Traits::position(c, ix, val);
        }

        template<typename Component, class Traits = component_traits <Component>>
        void position(Component &, unsigned, point2d, ...) {
        }
    }

    template<class Derived, class Base>
    class basic_component2d : public Base {
    public:
        explicit basic_component2d(std::string name)
                : Base{std::move(name)}, position_{}, rotation_{} {

        }

        const point2d &position() const {
            return position_;
        }

        point2d position(unsigned ix) const {
            return detail::position<Derived>(*static_cast<const Derived *>(this), ix, nullptr);
        }

        void position(point2d val) {
            position_ = std::move(val);
        }

        void position(unsigned ix, point2d val) {
            detail::position<Derived>(*static_cast<Derived *>(this), ix, val, nullptr);
        }

        int rotation() const {
            return rotation_;
        }

        void rotation(int val) {
            rotation_ = val;
        }

        void draw(draw_context_view &ctx) const {
            return component_traits<Derived>::draw(*static_cast<const Derived *>(this), ctx);
        }

    private:
        point2d position_;
        int rotation_;
    };

}


#endif //CIRCUITSIM_BASIC_COMPONENT2D_HH
