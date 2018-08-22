//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_VIEW_HPP
#define CIRCUITSIM_COMPONENT_VIEW_HPP

#include <circuitsim/config/export.h>
#include <memory>
#include <string_view>

namespace circuitsim {

    class dc_context_view;
    class component;

    class CIRCUITSIM_API component_view {
    public:
        component_view(const component_view &) noexcept;

        ~component_view();

        std::string_view symbol() const;

        std::string_view name() const;

        double value() const;

        int port(unsigned ix) const;

        void stamp(dc_context_view&) const;

    private:
        friend class component_factory;
        friend class circuit;

        explicit component_view(const component*) noexcept;

        const component *impl_;
    };

}

#endif //CIRCUITSIM_COMPONENT_VIEW_HPP
