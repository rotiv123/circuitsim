//
// Created by vitor on 16-08-2018.
//

#ifndef CIRCUITSIM_DC_CONTEXT_HPP
#define CIRCUITSIM_DC_CONTEXT_HPP

#include <circuitsim/config/export.h>

namespace circuitsim {

    class CIRCUITSIM_API dc_context_view final {
    public:

        void stamp_resistance(int n1, int n2, double r);

        void stamp_voltage(int pn, int nn, double v);

    private:
        class CIRCUITSIM_INTERNAL impl;

        friend class dc_solver;

        explicit dc_context_view(impl *) noexcept;

        impl *impl_;
    };

}


#endif //CIRCUITSIM_DC_CONTEXT_HPP
