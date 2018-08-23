//
// Created by vitor on 12-08-2018.
//

#include "circuit.hpp"
#include "component_view.hpp"
#include "private/circuit.hh"

namespace circuitsim {

    circuit::circuit() noexcept
            : impl_{std::make_unique<impl>()} {

    }

    circuit::circuit(std::unique_ptr<concept>&& x) noexcept : impl_{std::move(x)} {

    }

    circuit::circuit(circuit &&) noexcept = default;

    circuit::~circuit() = default;

    circuit &circuit::operator=(circuit &&) noexcept = default;

    std::string circuit::add(std::string_view symbol) {
        return impl_->add(symbol);
    }

    void circuit::remove(std::string_view name) {
        impl_->remove(name);
    }

    std::size_t circuit::nodes() const {
        return impl_->nodes();
    }

    void circuit::value(std::string_view src, double val) {
        impl_->value(src, val);
    }

    void circuit::connect(std::string_view src, unsigned srcp, std::string_view dst, unsigned dstp) {
        impl_->connect(src, srcp, dst, dstp);
    }

    void circuit::ground(std::string_view src, unsigned srcp) {
        impl_->ground(src, srcp);
    }

    void circuit::visit(const std::function<void(const component_view &)> &f) const {
        impl_->visit(f);
    }

}