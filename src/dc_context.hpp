//
// Created by vitor on 16-08-2018.
//

#ifndef CIRCUITSIM_DC_CONTEXT_HPP
#define CIRCUITSIM_DC_CONTEXT_HPP

#include <circuitsim/config/export.h>
#include <memory>

namespace circuitsim {

    class CIRCUITSIM_API dc_context {
    public:
        dc_context(std::size_t n, std::size_t m) noexcept;

        dc_context(dc_context &&) noexcept;

        ~dc_context();

        void stamp_resistance(unsigned n1, unsigned n2, double r);

        void stamp_voltage(unsigned pn, unsigned nn, double v);

    private:
        class impl;
        friend class dc_solver;

        std::unique_ptr<impl> impl_;
    };

}


#endif //CIRCUITSIM_DC_CONTEXT_HPP
