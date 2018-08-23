//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT2D_VIEW_HPP
#define CIRCUITSIM_COMPONENT2D_VIEW_HPP

#include <circuitsim/config/export.h>
#include "../component_view.hpp"

namespace circuitsim::ui {

    class CIRCUITSIM_API component2d_view : public component_view {
    public:

    protected:
        struct CIRCUITSIM_PRIVATE impl;
        explicit component2d_view(const impl *) noexcept;
    private:
        friend class circuit2d;
        friend class component2d;
    };

}


#endif //CIRCUITSIM_COMPONENT2D_VIEW_HPP
