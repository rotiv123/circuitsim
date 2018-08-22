//
// Created by vitor on 22-08-2018.
//

#ifndef CIRCUITSIM_CIRCUIT2D_HPP
#define CIRCUITSIM_CIRCUIT2D_HPP

#include <circuitsim/config/export.h>
#include <memory>

namespace circuitsim::ui {

    class CIRCUITSIM_API circuit2d {
    public:
        circuit2d() noexcept;

        circuit2d(circuit2d &&) noexcept;

        ~circuit2d();
    private:
        class CIRCUITSIM_PRIVATE impl;

        std::unique_ptr<impl> impl_;
    };
}


#endif //CIRCUITSIM_CIRCUIT2D_HPP
