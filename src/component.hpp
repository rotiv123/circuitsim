//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_HPP
#define CIRCUITSIM_COMPONENT_HPP

#include <circuitsim/config/export.h>
#include <memory>
#include <string_view>

namespace circuitsim {

    class CIRCUITSIM_API component {
    public:
        component(component &&) noexcept;

        ~component();

        std::string_view name() const;

        int port(unsigned ix);

        void port(unsigned ix, int val);

    private:
        friend class component_factory;

        class impl;

        explicit component(std::unique_ptr<impl>) noexcept;

        std::unique_ptr<impl> impl_;
    };

}

#endif //CIRCUITSIM_COMPONENT_HPP
