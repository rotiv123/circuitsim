//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_CIRCUIT2D_HH
#define CIRCUITSIM_CIRCUIT2D_HH

#include "../circuit2d.hpp"
#include "../../private/circuit.hh"
#include "basic_circuit2d.hh"
#include "component2d_factory.hh"
#include "component2d_view.hh"
#include "wiring_strategy.hh"

namespace circuitsim::ui {

    struct circuit2d::concept : public circuit::concept {
        virtual void visit(const std::function<void(const component2d_view &)> &f) const = 0;

        virtual void move_to(std::string_view c, int dx, int dy) = 0;

        virtual void rotate(std::string_view, int r) = 0;

        virtual void ground_move_to(int dx, int dy) = 0;
    };

    struct circuit2d::impl final :
            public basic_circuit2d<standard_wiring_strategy, component2d_factory::impl, circuit2d::concept> {
        using base = basic_circuit2d<standard_wiring_strategy, component2d_factory::impl, circuit2d::concept>;

        impl() noexcept : base{} {
            add("*Ground*");
        }

        void visit(const std::function<void(const component2d_view &)> &f) const final {
            base::visit([&](const auto &x) {
                auto cvi = component2d_view_model{&x};
                component2d_view t{&cvi};
                f(t);
            });
        }

        void visit(const std::function<void(const component_view &)> &f) const final {
            base::visit([&](const auto &x) {
                auto cvi = component2d_view_model{&x};
                component2d_view t{&cvi};
                f(t);
            });
        }
    };

}


#endif //CIRCUITSIM_CIRCUIT2D_HH
