//
// Created by vitor on 25-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT2D_WITH_POSITION_HH
#define CIRCUITSIM_COMPONENT2D_WITH_POSITION_HH


#include <algorithm>
#include <string>
#include "../point2d.hpp"
#include "../../private/basic_component.hh"

namespace circuitsim::ui {

    template<class T>
    const point2d &position(const T &x) {
        static const point2d zero{};
        return zero;
    }

    template<typename T, class Traits = component_traits <T>>
    point2d position(const T &c, unsigned ix) {
        auto list = Traits::ports();
        auto i = 0u;
        for (auto it : list) {
            if (i++ == ix) {

                auto[x, y] = it;
                auto rot = rotation(c);
                rot = rot > 0 ? rot % 360 : (360 + (rot % 360));
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

                auto[px, py] = position(c);
                return {px + x, py + y};
            }
        }

        return position(c);
    }

    template<class T>
    void position(T &, point2d) {
    }

    template<typename T>
    void position(T &, unsigned, point2d) {
    }

    template<class Derived, class Base>
    class with_position : public Base {
    public:
        explicit with_position(std::string name)
                : Base{std::move(name)}, position_{} {

        }

        friend const point2d &position(const Derived &x) {
            return x.position_;
        }

        friend void position(Derived &x, point2d val) {
            x.position_ = std::move(val);
        }

    private:
        point2d position_;
    };

}


#endif //CIRCUITSIM_COMPONENT2D_WITH_POSITION_HH
