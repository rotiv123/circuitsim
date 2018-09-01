//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_CIRCUIT2D_PAINTER_HPP
#define CIRCUITSIM_CIRCUIT2D_PAINTER_HPP

#include <circuitsim/config/export.h>
#include <memory>
#include "draw_context_view.hpp"

namespace circuitsim::ui {

    class circuit2d;

    class CIRCUITSIM_API circuit2d_painter {
    public:
        circuit2d_painter() noexcept;

        circuit2d_painter(circuit2d_painter &&) noexcept;

        ~circuit2d_painter();

        circuit2d_painter &operator=(circuit2d_painter &&) noexcept;

        void draw(const circuit2d &, draw_context_view &);

    private:
        class CIRCUITSIM_INTERNAL impl;

        std::unique_ptr<impl> impl_;
    };
}


#endif //CIRCUITSIM_CIRCUIT2D_PAINTER_HPP
