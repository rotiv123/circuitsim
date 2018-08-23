//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_FACTORY_HPP
#define CIRCUITSIM_COMPONENT_FACTORY_HPP

#include <circuitsim/config/export.h>
#include <memory>

namespace circuitsim {

    class component_view;

    class CIRCUITSIM_API component_factory final {
    public:

        using component_type = component_view;

        component_factory() noexcept;

        component_factory(component_factory &&) noexcept;

        ~component_factory();

    private:
        friend class circuit;

        class CIRCUITSIM_INTERNAL impl;

        std::unique_ptr<impl> impl_;
    };

}


#endif //CIRCUITSIM_COMPONENT_FACTORY_HPP
