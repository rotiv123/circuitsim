//
// Created by vitor on 23-08-2018.
//

#ifndef CIRCUITSIM_SVG_PAINTER_HPP
#define CIRCUITSIM_SVG_PAINTER_HPP

#include <circuitsim/config/export.h>
#include <memory>
#include <string>

namespace circuitsim::ui {

    class circuit2d;

    class CIRCUITSIM_API svg_painter {
    public:
        svg_painter() noexcept;

        svg_painter(svg_painter &&) noexcept;

        ~svg_painter();

        svg_painter &operator=(svg_painter &&) noexcept;

        std::string draw(const circuit2d &);

    private:
        class CIRCUITSIM_INTERNAL impl;

        std::unique_ptr<impl> impl_;
    };
}


#endif //CIRCUITSIM_SVG_PAINTER_HPP
