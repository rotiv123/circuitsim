//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT2D_HH
#define CIRCUITSIM_COMPONENT2D_HH

#include "primitives2d.hh"

namespace circuitsim::ui {

    class component2d {
    public:
        explicit component2d(primitive2d p) : storage_{std::move(p)} {
        }

        const point2d &position() const {
            return get_position(storage_);
        }

        void position(point2d val) {
            set_position(storage_, std::move(val));
        }

    private:
        primitive2d storage_;
    };

}


#endif //CIRCUITSIM_COMPONENT2D_HH
