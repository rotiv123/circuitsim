//
// Created by vitor on 16-08-2018.
//

#ifndef CIRCUITSIM_DC_CONTEXT_HH
#define CIRCUITSIM_DC_CONTEXT_HH

#include "../dc_context.hpp"
#include "algebra.hh"
#include "matrix.hh"

namespace circuitsim {

    struct dc_context::impl {

        impl(std::size_t n, std::size_t m) : mat_{n + m, n + m + 1}, n_{n}, m_{m}, m_ix_{0} {

        }

        void stamp_resistance(unsigned n1, unsigned n2, double r) {
            if (n2 > 0) {
                mat_.at(n2 - 1, n2 - 1) += 1 / r;
            }

            if (n1 > 0) {
                mat_.at(n1 - 1, n1 - 1) += 1 / r;
            }

            if (n1 > 0 && n2 > 0) {
                mat_.at(n1 - 1, n2 - 1) -= 1 / r;
                mat_.at(n2 - 1, n1 - 1) -= 1 / r;
            }
        }

        void stamp_voltage(unsigned pn, unsigned nn, double v) {
            if (pn > 0) {
                mat_.at(pn - 1, n_ + m_ix_) = 1;
                mat_.at(n_ + m_ix_, pn - 1) = 1;
            }

            if (nn > 0) {
                mat_.at(nn - 1, n_ + m_ix_) = -1;
                mat_.at(n_ + m_ix_, nn - 1) = -1;
            }

            if (pn > 0 || nn > 0) {
                mat_.at(n_ + m_ix_, n_ + m_) = v;
                ++m_ix_;
            }
        }

    private:
        friend class dc_solver;

        matrix mat_; //::impl mat_;
        std::size_t n_, m_, m_ix_;
    };

}


#endif //CIRCUITSIM_DC_CONTEXT_HH
