//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_DC_SOLVER_HPP
#define CIRCUITSIM_DC_SOLVER_HPP

#include <circuitsim/config/export.h>
#include <memory>

namespace circuitsim {

    class circuit;

    class CIRCUITSIM_API dc_solver {
    public:
        dc_solver() noexcept;

        dc_solver(dc_solver &&) noexcept;

        ~dc_solver();

        bool solve(const circuit &) const;

    private:
        class impl;

        std::unique_ptr<impl> impl_;
    };
}


#endif //CIRCUITSIM_DC_SOLVER_HPP
