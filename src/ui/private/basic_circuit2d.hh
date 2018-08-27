//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_BASIC_CIRCUIT2D_HH
#define CIRCUITSIM_BASIC_CIRCUIT2D_HH

#include "../../private/basic_circuit.hh"
#include "primitives2d.hh"

namespace circuitsim::ui {

    template<class WiringStrategy, class ComponentFactory, class Concept>
    class basic_circuit2d : public basic_circuit<ComponentFactory, Concept> {
    public:

        using base = basic_circuit<ComponentFactory, Concept>;
        using wiring_strategy_type = WiringStrategy;

        void move_to(std::string_view c, int dx, int dy) override {
            auto &source = base::get(c);

            auto[x, y] = get_position(source);
            set_position(source, {x + dx, y + dy});
        }

        void ground_move_to(int dx, int dy) override {
            move_to("*Ground*1", dx, dy);
        }

        void rotate(std::string_view c, int r) override {
            auto &source = base::get(c);

            set_rotation(source, r);
        }

        void connect(std::string_view src, unsigned srcp, std::string_view dst, unsigned dstp) override {
            base::connect(src, srcp, dst, dstp);
            wiring_strategy_.connect(*this, src, srcp, dst, dstp);
        }

        void ground(std::string_view src, unsigned srcp) override {
            base::ground(src, srcp);
            wiring_strategy_.connect(*this, src, srcp, "*Ground*1", 0);
        }

        point2d center() const {
            auto sumx = 0;
            auto sumy = 0;
            int cnt = base::components().size();
            for (const auto &i : base::components()) {
                auto[x, y] = get_position(i);
                sumx += x;
                sumy += y;
            }

            return {sumx / cnt, sumy / cnt};
        }

    private:
        wiring_strategy_type wiring_strategy_;
    };
}


#endif //CIRCUITSIM_BASIC_CIRCUIT2D_HH
