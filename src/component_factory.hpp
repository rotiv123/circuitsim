//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_FACTORY_HPP
#define CIRCUITSIM_COMPONENT_FACTORY_HPP

#include <circuitsim/config/export.h>
#include <memory>

namespace circuitsim {

    class component;

    class CIRCUITSIM_API component_factory {
    public:

        using component_type = component;

        component_factory() noexcept;

        component_factory(component_factory &&) noexcept;

        ~component_factory();

        component_type create(std::string_view symbol, std::string name) const;

    private:
        class impl;

        std::unique_ptr<impl> impl_;
    };

}


#endif //CIRCUITSIM_COMPONENT_FACTORY_HPP
