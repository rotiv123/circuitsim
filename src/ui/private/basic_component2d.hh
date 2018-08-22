//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_BASIC_COMPONENT2D_HH
#define CIRCUITSIM_BASIC_COMPONENT2D_HH

#include <tuple>

namespace circuitsim::ui {

    using point2d = std::tuple<float, float>;

    template <class Derived, class Base>
    class basic_component2d : public Base {
    public:
        using Base::Base;

        const point2d &position() const {
            return position_;
        }

        void position(point2d val) {
            position_ = std::move(val);
        }

    private:
        point2d position_;
    };

}


#endif //CIRCUITSIM_BASIC_COMPONENT2D_HH
