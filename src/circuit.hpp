//
// Created by vitor on 12-08-2018.
//

#ifndef CIRCUITSIM_CIRCUIT_HPP
#define CIRCUITSIM_CIRCUIT_HPP


#include <circuitsim/config/export.h>
#include <memory>
#include <string>

namespace circuitsim {

    class component_factory;

    class CIRCUITSIM_API circuit {
    public:

        circuit() noexcept;

        explicit circuit(component_factory &&factory) noexcept;

        circuit(circuit &&) noexcept;

        ~circuit();

        void add(std::string_view symbol, std::string name);

        friend CIRCUITSIM_API void connect(circuit &, std::string_view, unsigned, std::string_view, unsigned);

        friend CIRCUITSIM_API void ground(circuit &c, std::string_view src, unsigned srcp);

    private:
        class impl;

        std::unique_ptr<impl> impl_;
    };
}

#endif //CIRCUITSIM_CIRCUIT_HPP
