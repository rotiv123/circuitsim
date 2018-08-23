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

    class CIRCUITSIM_API component_view {
    public:
        struct CIRCUITSIM_INTERNAL concept;

        CIRCUITSIM_INTERNAL explicit component_view(const concept *) noexcept;

        std::string_view symbol() const;

        std::string_view name() const;

        double value() const;

        int port(unsigned ix) const;

        void stamp(dc_context_view &) const;

    protected:
        const concept *impl_;
    };

}

#endif //CIRCUITSIM_COMPONENT_VIEW_HPP
