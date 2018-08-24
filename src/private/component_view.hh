//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_COMPONENT_VIEW_HH
#define CIRCUITSIM_COMPONENT_VIEW_HH

#include "../component_view.hpp"
#include "private/primitives.hh"
#include "private/basic_component_view.hh"

namespace circuitsim {

    struct component_view::concept {
        virtual ~concept() = default;

        virtual std::string_view symbol() const =0;

        virtual std::string_view name() const =0;

        virtual double value() const =0;

        virtual int port(unsigned ix) const =0;

        virtual bool can_stamp() const = 0;

        virtual void stamp(dc_context_view &) const =0;
    };

    struct component_view_model : public basic_component_view<primitive, component_view::concept> {
        using base =  basic_component_view<primitive, component_view::concept>;
        using base::base;
    };


}


#endif //CIRCUITSIM_COMPONENT_VIEW_HH
