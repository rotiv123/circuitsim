//
// Created by vitor on 12-08-2018.
//

#include "circuit.hpp"
#include "component.hpp"
#include "private/basic_circuit.hh"
#include "component_factory.hpp"

namespace circuitsim {

    struct circuit::impl : public basic_circuit<component_factory> {
        using base = basic_circuit<component_factory>;
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

    void circuit::add(std::string_view symbol, std::string name) {
        impl_->add(symbol, std::move(name));
    }

    void connect(circuit &c, std::string_view src, unsigned srcp, std::string_view dst, unsigned dstp) {
        c.impl_->connect(src, srcp, dst, dstp);
    }

    void ground(circuit &c, std::string_view src, unsigned srcp) {
        c.impl_->ground(src, srcp);
    }

}