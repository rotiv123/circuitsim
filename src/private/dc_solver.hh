//
// Created by vitor on 16-08-2018.
//

#ifndef CIRCUITSIM_DC_SOLVER_HH
#define CIRCUITSIM_DC_SOLVER_HH

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

#include "../dc_solver.hpp"
#include "../circuit.hpp"
#include "../component_view.hpp"
#include "matrix.hh"
#include "dc_context.hh"
#include "../dc_context_view.hpp"
#include "algebra.hh"

namespace circuitsim {

    struct dc_solver::impl {

        bool solve(const circuit &c) const {
            std::vector<int> nodes_map;
            auto max_node_id = c.nodes() + 1;
            unsigned nodes{0}, voltage_sources{0};

            nodes_map.reserve(max_node_id);
            for (auto i = 0; i < max_node_id; ++i) {
                nodes_map.push_back(-1);
            }
            nodes_map[0] = 0;
            c.visit([&](const component_view &x) {
                auto n1 = x.port(0);
                auto n2 = x.port(1);

                if (n1 == n2) {
                    return;
                }

                if (x.symbol() == "V") {
                    voltage_sources++;
                }

                if (nodes_map[n1] == -1) {
                    nodes_map[n1] = static_cast<int>(++nodes);
                }

                if (nodes_map[n2] == -1) {
                    nodes_map[n2] = static_cast<int>(++nodes);
                }
            });

            dc_context_view::impl ctx{nodes, voltage_sources, nodes_map};
            auto ctx_view = dc_context_view{&ctx};
            c.visit([&](const component_view &x) {
                auto n1 = x.port(0);
                auto n2 = x.port(1);
                if (n1 != n2) {
                    x.stamp(ctx_view);
                }
            });

            auto mt = ctx.mat();
            print(mt);
            auto ok = circuitsim::solve(mt);

            for (auto i = 0u; i < nodes; ++i) {
                auto it = std::find(std::begin(nodes_map), std::end(nodes_map), i + 1);
                std::cout << "v_" << (std::distance(std::begin(nodes_map), it))
                          << " = " << mt.at(i, mt.cols() - 1) << std::endl;
            }

            for (auto i = 0u; i < voltage_sources; ++i) {
                std::cout << "i_" << i
                          << " = " << mt.at(mt.rows() - (voltage_sources + i), mt.cols() - 1) << std::endl;
            }

            return ok;
        }

    private:
    };

}


#endif //CIRCUITSIM_DC_SOLVER_HH
