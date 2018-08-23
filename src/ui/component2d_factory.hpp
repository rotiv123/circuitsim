//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT2D_FACTORY_HPP
#define CIRCUITSIM_COMPONENT2D_FACTORY_HPP

#include <circuitsim/config/export.h>
#include <memory>

namespace circuitsim::ui {

    class component2d_view;

    class CIRCUITSIM_API component2d_factory {
    public:
        using component_type = component2d_view;

        component2d_factory() noexcept;

        component2d_factory(component2d_factory &&) noexcept;

        ~component2d_factory();

    private:
        friend class circuit2d;

        class CIRCUITSIM_INTERNAL impl;

        std::unique_ptr<impl> impl_;
    };
}


#endif //CIRCUITSIM_COMPONENT2D_FACTORY_HPP
