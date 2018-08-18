//
// Created by vitor on 12-08-2018.
//

#ifndef CIRCUITSIM_CIRCUIT_HPP
#define CIRCUITSIM_CIRCUIT_HPP


#include <circuitsim/config/export.h>
#include <memory>
#include <string>
#include <functional>
#include "component_view.hpp"

namespace circuitsim {

    class component_factory;

    class CIRCUITSIM_API circuit {
    public:

        circuit() noexcept;

        circuit(circuit &&) noexcept;

        ~circuit();

        std::string add(std::string_view symbol);

        std::size_t nodes() const;

        void visit(const std::function<void(const component_view &)> &) const;

        friend CIRCUITSIM_API void set_value(circuit &, std::string_view, double);

        friend CIRCUITSIM_API void connect(circuit &, std::string_view, unsigned, std::string_view, unsigned);

        friend CIRCUITSIM_API void ground(circuit &c, std::string_view src, unsigned srcp);

    private:
        class impl;

        std::unique_ptr<impl> impl_;
    };
}

#endif //CIRCUITSIM_CIRCUIT_HPP
