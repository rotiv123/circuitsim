//
// Created by vitor on 16-08-2018.
//

#ifndef CIRCUITSIM_DC_CONTEXT_HH
#define CIRCUITSIM_DC_CONTEXT_HH

#include <utility>
#include "../dc_context_view.hpp"
#include "algebra.hh"
#include "matrix.hh"

namespace circuitsim {

    struct dc_context_view::impl {

        static constexpr double OPEN_AIR_RESISTANCE = 1000000000;

        impl(unsigned n, unsigned m, std::vector<int> &map) : G{n, n}, B{n, m}, C{m, n}, D{m, m}, i{n, 1}, e{m, 1},
                                                              node_map_{map}, n_{n}, m_{m},
                                                              m_ix_{0} {

        }

        void stamp_resistance(int n1, int n2, double r) {
            auto[ok, k1, k2] = protect(false, n1, n2);

            if (!ok) {
                return;
            }

            if (n2 > 0) {
                G.at(k2, k2) += 1.0 / r;
            }

            if (n1 > 0) {
                G.at(k1, k1) += 1.0 / r;
            }

            if (n1 > 0 && n2 > 0) {
                G.at(k1, k2) -= 1.0 / r;
                G.at(k2, k1) -= 1.0 / r;
            }
        }

        void stamp_voltage(int pn, int nn, double v) {
            auto[ok, kp, kn] = protect(true, pn, nn);

            if (!ok) {
                return;
            }

            if (pn > 0) {
                B.at(kp, m_ix_) = 1.0;
                C.at(m_ix_, kp) = 1.0;
            }

            if (nn > 0) {
                B.at(kn, m_ix_) = -1.0;
                C.at(m_ix_, kn) = -1.0;
            }

            if (pn > 0 || nn > 0) {
                e.at(m_ix_, 0) = v;
                ++m_ix_;
            }
        }

        matrix mat() const {
            matrix mt{n_ + m_, n_ + m_ + 1};
            mt.stamp(G, 0, 0);
            mt.stamp(B, 0, n_);
            mt.stamp(C, n_, 0);
            mt.stamp(D, n_, n_);
            mt.stamp(i, 0, n_ + m_);
            mt.stamp(e, n_, n_ + m_);

            return mt;
        }

    private:
        friend class dc_solver;

        matrix G, B, C, D, i, e;
        std::reference_wrapper<std::vector<int>> node_map_;
        unsigned n_, m_, m_ix_;

        std::tuple<bool, std::size_t, std::size_t> protect(bool vs, int &n1, int &n2) {
            if (n1 == n2) {
                if (vs) {
                    resize(n_, m_ - 1);
                }
            } else if (n1 < 0) {
                n1 = n_ + 1;
                resize(n_ + 1, m_);
                stamp_resistance(n1, 0, OPEN_AIR_RESISTANCE);
            } else if (n2 < 0) {
                n2 = n_ + 1;
                resize(n_ + 1, m_);
                stamp_resistance(n2, 0, OPEN_AIR_RESISTANCE);
            }

            n1 = node_map_.get()[n1];
            n2 = node_map_.get()[n2];
            return {n1 != n2, ix(n1 - 1), ix(n2 - 1)};
        }

        void resize(unsigned n, unsigned m) {
            if (n != n_ && m != m_) {
                G = G.resize(n, n);
                B = B.resize(n, m);
                C = C.resize(m, n);
                D = D.resize(m, m);
                e = e.resize(m, 1);
                i = i.resize(n, 1);
                n_ = n;
                m_ = m;
                node_map_.get().push_back(n);
            } else if (n != n_) {
                G = G.resize(n, n);
                B = B.resize(n, m_);
                C = C.resize(m_, n);
                i = i.resize(n, 1);
                n_ = n;
                node_map_.get().push_back(n);
            } else if (m != m_) {
                B = B.resize(n_, m);
                C = C.resize(m, n_);
                D = D.resize(m, m);
                e = e.resize(m, 1);
                m_ = m;
            }
        }

        static constexpr std::size_t

        ix(int n) {
            return n > 0 ? static_cast<unsigned>(n) : 0;
        }
    };

}


#endif //CIRCUITSIM_DC_CONTEXT_HH
