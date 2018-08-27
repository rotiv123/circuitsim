//
// Created by vitor on 25-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT2D_WITH_POSITION_HH
#define CIRCUITSIM_COMPONENT2D_WITH_POSITION_HH


#include <algorithm>
#include <string>
#include "../../private/basic_component.hh"
#include "point2d.hh"

namespace circuitsim::ui {

    template<class T>
    const point2d &position(const T &x) {
        static const point2d zero{};
        return zero;
    }

    template<typename T, class Traits = component_traits <T>>
    point2d position(const T &c, unsigned ix) {
        if (ix < Traits::ports().size()) {
            auto rot = rotation(c);
            auto[x, y] = rotate(Traits::ports()[ix], rot);
            auto[px, py] = position(c);
            return {px + x, py + y};
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
