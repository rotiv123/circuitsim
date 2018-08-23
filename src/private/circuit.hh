//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_CIRCUIT_HH
#define CIRCUITSIM_CIRCUIT_HH

#include "../circuit.hpp"
#include "basic_circuit.hh"
#include "component_factory.hh"
#include "component_view.hh"

namespace circuitsim {

    struct circuit::concept {
        virtual ~concept() = default;

        virtual std::string add(std::string_view symbol) = 0;

        virtual void remove(std::string_view name) = 0;

        virtual std::size_t nodes() const = 0;

        virtual void value(std::string_view, double) = 0;

        virtual void connect(std::string_view, unsigned, std::string_view, unsigned) = 0;

        virtual void ground(std::string_view src, unsigned srcp) = 0;

        virtual void visit(const std::function<void(const component_view &)> &) const = 0;
    };

    struct circuit::impl : public basic_circuit<component_factory::impl, circuit::concept> {
        using base = basic_circuit<component_factory::impl, circuit::concept>;

        void visit(const std::function<void(const component_view &)> &f) const final {
            base::visit([&](const auto &x) {
                auto cvi = component{&x};
                component_view t{&cvi};
                f(t);
            });
        }
    };

}

#endif //CIRCUITSIM_CIRCUIT_HH
