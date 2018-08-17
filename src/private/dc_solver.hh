//
// Created by vitor on 16-08-2018.
//

#ifndef CIRCUITSIM_DC_SOLVER_HH
#define CIRCUITSIM_DC_SOLVER_HH

#include <iostream>
#include <iomanip>

#include "../dc_solver.hpp"
#include "../circuit.hpp"
#include "../component.hpp"
#include "matrix.hh"
#include "dc_context.hh"
#include "algebra.hh"

namespace circuitsim {


    template<class Matrix>
    void print(const Matrix mat) {
        using traits = circuitsim::matrix_traits<Matrix>;
        const auto n = traits::cols(mat);
        const auto m = traits::rows(mat);

        for (int i = 0; i < m; ++i) {
            std::cout << "[" << std::setw(9) << traits::at(mat, i, 0);
            for (int j = 1; j < n; ++j) {
                std::cout << ", " << std::setw(9) << traits::at(mat, i, j);
            }
            std::cout << "]" << std::endl;
        }
    }

    struct dc_solver::impl {

        void solve(const circuit &c) const {
            dc_context ctx{c.nodes(), c.voltage_sources()};
            visit(c, [&](const component &x) {
                std::cout << x.name() << " " << x.port(0) << " " << x.port(1) << " " << x.value() << std::endl;
                x.stamp(ctx);
            });

            std::cout << c.nodes() << " nodes" << std::endl;
            std::cout << c.voltage_sources() << " voltage_sources" << std::endl;

            print(ctx.impl_->mat_);
            std::cout << "solving..." << std::endl;
            circuitsim::solve(ctx.impl_->mat_);
            print(ctx.impl_->mat_);
        }

    private:
    };

}


#endif //CIRCUITSIM_DC_SOLVER_HH
