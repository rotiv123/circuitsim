//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT2D_VIEW_HPP
#define CIRCUITSIM_COMPONENT2D_VIEW_HPP

#include <circuitsim/config/export.h>

namespace circuitsim::ui {

    class component2d;

    class CIRCUITSIM_API component2d_view {
    public:
        component2d_view(const component2d_view &) noexcept;

        ~component2d_view();
    private:
        explicit component2d_view(const component2d*) noexcept;

        const component2d* src_;
    };

}


#endif //CIRCUITSIM_COMPONENT2D_VIEW_HPP
