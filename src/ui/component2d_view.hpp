//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT2D_VIEW_HPP
#define CIRCUITSIM_COMPONENT2D_VIEW_HPP

#include <circuitsim/config/export.h>
#include "point2d.hpp"
#include "../component_view.hpp"

namespace circuitsim::ui {

    class CIRCUITSIM_API component2d_view : public component_view {
    public:
        struct CIRCUITSIM_INTERNAL concept;

        CIRCUITSIM_INTERNAL explicit component2d_view(const concept *) noexcept;

        const point2d &position() const;
    };

}


#endif //CIRCUITSIM_COMPONENT2D_VIEW_HPP
