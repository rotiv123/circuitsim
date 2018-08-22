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

    class CIRCUITSIM_API circuit final {
    public:

        circuit() noexcept;

        circuit(circuit &&) noexcept;

        ~circuit();

        std::string add(std::string_view symbol);

        void remove(std::string_view name);

        std::size_t nodes() const;

        void visit(const std::function<void(const component_view &)> &) const;

        void value(std::string_view, double);

        void connect(std::string_view, unsigned, std::string_view, unsigned);

        void ground(std::string_view src, unsigned srcp);

    private:
        class CIRCUITSIM_PRIVATE impl;

        std::unique_ptr<impl> impl_;
    };
}

#endif //CIRCUITSIM_CIRCUIT_HPP
