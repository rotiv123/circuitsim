//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_HPP
#define CIRCUITSIM_COMPONENT_HPP

#include <circuitsim/config/export.h>
#include <memory>
#include <string_view>

namespace circuitsim {

    class dc_context;
    template <class T> class mutator;

    class CIRCUITSIM_API component {
    public:
        component(component &&) noexcept;

        ~component();

        std::string_view symbol() const;

        std::string_view name() const;

        double value() const;

        int port(unsigned ix) const;

        void stamp(dc_context&) const;

    private:
        friend class component_factory;
        friend class mutator<component>;

        class impl;

        explicit component(std::unique_ptr<impl>) noexcept;

        std::unique_ptr<impl> impl_;

        void port(unsigned ix, int val);

        void value(double val);
    };

}

#endif //CIRCUITSIM_COMPONENT_HPP
