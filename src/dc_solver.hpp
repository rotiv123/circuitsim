//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_DC_SOLVER_HPP
#define CIRCUITSIM_DC_SOLVER_HPP

#include <circuitsim/config/export.h>
#include <memory>
#include <variant>
#include <functional>

namespace circuitsim {

    class circuit;

    struct node_voltage {
        unsigned node_id;
        double value;
    };

    struct voltage_source_current {
        unsigned voltage_source_id;
        double value;
    };

    using data_point = std::variant<node_voltage, voltage_source_current>;

    class CIRCUITSIM_API dc_solver final {
    public:
        dc_solver() noexcept;

        dc_solver(dc_solver &&) noexcept;

        ~dc_solver();

        bool solve(const circuit &);

        void visit(const std::function<void(const data_point &)> &) const;

    private:
        class CIRCUITSIM_PRIVATE impl;

        std::unique_ptr<impl> impl_;
    };
}


#endif //CIRCUITSIM_DC_SOLVER_HPP
