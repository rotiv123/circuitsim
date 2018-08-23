//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_CIRCUIT2D_HPP
#define CIRCUITSIM_CIRCUIT2D_HPP

#include <circuitsim/config/export.h>
#include <memory>
#include <functional>
#include "component2d_view.hpp"
#include "../circuit.hpp"

namespace circuitsim::ui {

    class CIRCUITSIM_API circuit2d : public circuit {
    public:
        circuit2d() noexcept;

        circuit2d(circuit2d &&) noexcept;

        ~circuit2d() override;

        void visit(const std::function<void(const component2d_view &)> &) const;

    protected:
        struct CIRCUITSIM_PRIVATE concept;
        explicit circuit2d(std::unique_ptr<concept>&&) noexcept;
    private:
        struct CIRCUITSIM_PRIVATE impl;
        concept *impl_;
    };
}


#endif //CIRCUITSIM_CIRCUIT2D_HPP
