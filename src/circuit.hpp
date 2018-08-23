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

    class CIRCUITSIM_API circuit {
    public:

        circuit() noexcept;

        circuit(circuit &&) noexcept;

        virtual ~circuit();

        std::string add(std::string_view symbol);

        void remove(std::string_view name);

        std::size_t nodes() const;

        void visit(const std::function<void(const component_view &)> &) const;

        void value(std::string_view, double);

        void connect(std::string_view, unsigned, std::string_view, unsigned);

        void ground(std::string_view src, unsigned srcp);

    protected:
        struct CIRCUITSIM_PRIVATE concept;
        explicit circuit(std::unique_ptr<concept>&&) noexcept;

    private:
        struct CIRCUITSIM_PRIVATE impl;

        std::unique_ptr<concept> impl_;
    };
}

#endif //CIRCUITSIM_CIRCUIT_HPP
