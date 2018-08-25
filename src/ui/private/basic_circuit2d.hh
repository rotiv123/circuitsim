//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_BASIC_CIRCUIT2D_HH
#define CIRCUITSIM_BASIC_CIRCUIT2D_HH

#include "../../private/basic_circuit.hh"
#include "primitives2d.hh"

namespace circuitsim::ui {

    template<class ComponentFactory, class Concept>
    class basic_circuit2d : public basic_circuit<ComponentFactory, Concept> {
    public:

        using base = basic_circuit<ComponentFactory, Concept>;

        void move_to(std::string_view c, int dx, int dy) override {
            auto &source = base::get(c);

            auto[x, y] = get_position(source);
            set_position(source, {x + dx, y + dy});
        }

        void rotate(std::string_view c, int r) override {
            auto &source = base::get(c);

            set_rotation(source, r);
        }

        void connect(std::string_view src, unsigned srcp, std::string_view dst, unsigned dstp) override {
            base::connect(src, srcp, dst, dstp);

            auto w = base::add("*Wire*");
            base::connect(w, 0, src, srcp);
            base::connect(w, 1, dst, dstp);

            auto &wire = base::get(w);
            auto &source = base::get(src);
            auto &destination = base::get(dst);
            set_position(wire, 0, get_position(source, srcp));
            set_position(wire, 1, get_position(destination, dstp));
        }

        void ground(std::string_view src, unsigned srcp) override {
            base::ground(src, srcp);

            auto w = base::add("*Wire*");
            base::connect(w, 0, src, srcp);
            base::ground(w, 1);

            auto &wire = base::get(w);
            auto &source = base::get(src);
            auto &destination = base::get("*Ground*1");
            set_position(wire, 0, get_position(source, srcp));
            set_position(wire, 1, get_position(destination, 0));
        }

    private:
    };
}


#endif //CIRCUITSIM_BASIC_CIRCUIT2D_HH
