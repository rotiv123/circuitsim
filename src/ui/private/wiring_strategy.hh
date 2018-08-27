//
// Created by vitor on 27-08-2018.
//

#ifndef CIRCUITSIM_WIRING_STRATEGY_HH
#define CIRCUITSIM_WIRING_STRATEGY_HH

#include <string_view>
#include "same_axis_wiring_strategy.hh"
#include "away_from_center_wiring_strategy.hpp"

namespace circuitsim::ui {

    template<class T, class Next = void>
    struct wiring_strategy : private T, private Next {

        template<class Circuit>
        void connect(Circuit &c, std::string_view src, unsigned srcp, std::string_view dst, unsigned dstp) const {

            if (!T::try_connect(c, src, srcp, dst, dstp)) {
                Next::connect(c, src, srcp, dst, dstp);
            }
        }
    };

    template<class T>
    struct wiring_strategy<T, void> : private T {

        template<class Circuit>
        void connect(Circuit &c, std::string_view src, unsigned srcp, std::string_view dst, unsigned dstp) const {
            if (!T::try_connect(c, src, srcp, dst, dstp)) {
                wire_connect(c, src, srcp, dst, dstp);
            }
        }

    private:

        template<class Circuit>
        static void wire_connect(Circuit &c, std::string_view src, unsigned srcp, std::string_view dst, unsigned dstp) {
            auto &source = c.get(src);
            auto &destination = c.get(dst);
            auto w = c.add("*Wire*");
            auto &wire = c.get(w);
            set_position(wire, 0, get_position(source, srcp));
            set_position(wire, 1, get_position(destination, dstp));
        }
    };

    using standard_wiring_strategy =
    wiring_strategy<same_axis_wiring_strategy,
            wiring_strategy<away_from_center_wiring_strategy>>;

}

#endif //CIRCUITSIM_WIRING_STRATEGY_HH
