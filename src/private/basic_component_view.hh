//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_BASIC_COMPONENT_VIEW_HH
#define CIRCUITSIM_BASIC_COMPONENT_VIEW_HH

#include <string_view>
#include "../dc_context_view.hpp"

namespace circuitsim {

    template<class Primitive>
    void stamp(const Primitive &c, dc_context_view &ctx);

    template<class Primitive, class Concept>
    struct basic_component_view : public Concept {
        explicit basic_component_view(const Primitive *impl) : impl_{impl} {}

        std::string_view symbol() const {
            return get_symbol(*impl_);
        }

        std::string_view name() const {
            return get_name(*impl_);
        }

        double value() const {
            return get_value(*impl_);
        }

        int port(unsigned ix) const {
            return get_port(*impl_, ix);
        }

        bool can_stamp() const {
            return circuitsim::can_stamp(*impl_);
        }

        void stamp(dc_context_view &ctx) const {
            circuitsim::stamp(*impl_, ctx);
        }

    protected:
        const Primitive *impl_;
    };

}


#endif //CIRCUITSIM_BASIC_COMPONENT_VIEW_HH
