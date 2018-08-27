//
// Created by vitor on 27-08-2018.
//

#ifndef CIRCUITSIM_AWAY_FROM_CENTER_WIRING_STRATEGY_HH
#define CIRCUITSIM_AWAY_FROM_CENTER_WIRING_STRATEGY_HH

#include <cmath>
#include <string_view>
#include "point2d.hh"

namespace circuitsim::ui {

    struct away_from_center_wiring_strategy {

        template<class Circuit>
        bool try_connect(Circuit &c, std::string_view src, unsigned srcp, std::string_view dst, unsigned dstp) const {
            auto &source = c.get(src);
            auto &destination = c.get(dst);
            auto[src_x, src_y] = get_position(source, srcp);
            auto[dst_x, dst_y] = get_position(destination, dstp);

            if (src_x != dst_x && src_y != dst_y) {
                auto[cx, cy] = c.center();
                auto d1 = std::pow(src_x - cx, 2) + std::pow(dst_y - cy, 2);
                auto d2 = std::pow(dst_x - cx, 2) + std::pow(src_y - cy, 2);
                auto x = src_x;
                auto y = dst_y;
                if (d1 < d2) {
                    x = dst_x;
                    y = src_y;
                }

                add_wire(c, {src_x, src_y}, {x, y});
                add_wire(c, {x, y}, {dst_x, dst_y});

                return true;
            }

            return false;
        }

    private:

        template<class Circuit>
        static void add_wire(Circuit &c, point2d a, point2d b) {
            auto w = c.add("*Wire*");
            auto &wire = c.get(w);
            set_position(wire, 0, a);
            set_position(wire, 1, b);
        }

    };
}

#endif //CIRCUITSIM_AWAY_FROM_CENTER_WIRING_STRATEGY_HH
