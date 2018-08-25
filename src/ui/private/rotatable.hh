//
// Created by vitor on 25-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT2D_WITH_ROTATION_HH
#define CIRCUITSIM_COMPONENT2D_WITH_ROTATION_HH


#include <string>
#include "../point2d.hpp"

namespace circuitsim::ui {

    template<class T>
    int rotation(const T &) {
        return 0;
    }

    template<class T>
    void rotation(const T &, int) {
    }

    template<class Derived, class Base>
    class rotatable : public Base {
    public:
        explicit rotatable(std::string name)
                : Base{std::move(name)}, rotation_{} {
        }

        friend int rotation(const Derived &x) {
            return x.rotation_;
        }

        friend void rotation(Derived &x, int val) {
            x.rotation_ = val;
        }

    private:
        int rotation_;
    };

}


#endif //CIRCUITSIM_COMPONENT2D_WITH_ROTATION_HH
