//
// Created by vitor on 27-08-2018.
//

#ifndef CIRCUITSIM_SAME_AXIS_WIRING_STRATEGY_HH
#define CIRCUITSIM_SAME_AXIS_WIRING_STRATEGY_HH

#include <string_view>

namespace circuitsim::ui {

    struct same_axis_wiring_strategy {

        template<class Circuit>
        bool try_connect(Circuit &c, std::string_view src, unsigned srcp, std::string_view dst, unsigned dstp) const {
            auto &source = c.get(src);
            auto &destination = c.get(dst);
            auto[src_x, src_y] = get_position(source, srcp);
            auto[dst_x, dst_y] = get_position(destination, dstp);

            if (src_x == dst_x || src_y == dst_y) {
                auto w = c.add("*Wire*");
                auto &wire = c.get(w);
                set_position(wire, 0, {src_x, src_y});
                set_position(wire, 1, {dst_x, dst_y});

                return true;
            }

            return false;
        }

    };

}


#endif //CIRCUITSIM_SAME_AXIS_WIRING_STRATEGY_HH
