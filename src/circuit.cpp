//
// Created by vitor on 12-08-2018.
//

#include "circuit.hpp"
#include "component.hpp"
#include "private/basic_circuit.hh"
#include "private/component.hh"
#include "component_factory.hpp"

namespace circuitsim {

    struct circuit::impl : public basic_circuit<component_factory, circuitsim::mutator<component>> {
        using base = basic_circuit<component_factory, circuitsim::mutator<component>>;
        using base::base;
    };

    circuit::circuit() noexcept
            : impl_{std::make_unique<impl>()} {

    }

    circuit::circuit(component_factory &&factory) noexcept
            : impl_{std::make_unique<impl>(std::move(factory))} {
    }

    circuit::circuit(circuit &&) noexcept = default;

    circuit::~circuit() = default;

    std::string circuit::add(std::string_view symbol, std::string name) {
        return impl_->add(symbol, std::move(name));
    }

    std::size_t circuit::nodes() const {
        return impl_->nodes();
    }

    std::size_t circuit::voltage_sources() const {
        return impl_->voltage_sources();
    }

    void set_value(circuit &c, std::string_view src, double val) {
        c.impl_->value(src, val);
    }

    void connect(circuit &c, std::string_view src, unsigned srcp, std::string_view dst, unsigned dstp) {
        c.impl_->connect(src, srcp, dst, dstp);
    }

    void ground(circuit &c, std::string_view src, unsigned srcp) {
        c.impl_->ground(src, srcp);
    }

    void visit(const circuit &c, const std::function<void(const component &)> &f) {
        c.impl_->visit(f);
    }

}