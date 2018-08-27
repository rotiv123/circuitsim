//
// Created by vitor on 26-08-2018.
//

#ifndef CIRCUITSIM_POINT2D_HH
#define CIRCUITSIM_POINT2D_HH

#include "../point2d.hpp"

namespace circuitsim::ui {

    inline point2d rotate(point2d p, int rot) {
        auto[x, y] = p;
        rot = rot > 0 ? rot % 360 : (360 + (rot % 360));
        switch (rot) {
            case 90:
                std::swap(x, y);
                break;
            case 270:
                std::swap(x, y);
                y *= -1;
                break;
            case 180:
                x *= -1;
                break;
            default:
                break;
        }
        return {x, y};
    }

    inline int dot_product(point2d p1, point2d p2) {
        auto[x1, y1] = p1;
        auto[x2, y2] = p2;
        return x1 * x2 + y1 * y2;
    }
}

#endif //CIRCUITSIM_POINT2D_HH
