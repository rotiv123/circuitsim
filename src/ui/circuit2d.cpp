//
// Created by vitor on 22-08-2018.
//

#include "circuit2d.hpp"
#include "component2d_view.hpp"
#include "../private/basic_circuit.hh"
#include "private/component.hh"
#include "private/component2d_factory.hh"

namespace circuitsim::ui {

    class circuit2d::impl : public basic_circuit<component2d_factory::impl> {
    public:
        using base = basic_circuit<component2d_factory::impl>;
        using base::base;
    };

    circuit2d::circuit2d() noexcept
            : impl_{std::make_unique<impl>()} {

    }

    circuit2d::circuit2d(circuit2d &&) noexcept = default;

    circuit2d::~circuit2d() = default;

}