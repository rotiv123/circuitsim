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

        circuit2d &operator=(circuit2d &&) noexcept;

        void visit(const std::function<void(const component2d_view &)> &) const;

        void move_to(std::string_view, int dx, int dy);

        void ground_move_to(int dx, int dy);

        void rotate(std::string_view, int r);

    protected:
        struct CIRCUITSIM_INTERNAL concept;

        explicit circuit2d(std::unique_ptr<concept> &&) noexcept;
    private:
        struct CIRCUITSIM_INTERNAL impl;
    };
}


#endif //CIRCUITSIM_CIRCUIT2D_HPP
