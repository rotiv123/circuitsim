//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_MATRIX_HH
#define CIRCUITSIM_MATRIX_HH

#include <vector>
#include <algorithm>
#include <cmath>
#include "../matrix.hpp"

namespace circuitsim {

    struct matrix { //::impl {

        matrix(std::size_t m, std::size_t n) noexcept : storage_{}, M{m}, N{n} {
            storage_.reserve(M * N);
            for (int i = 0; i < M * N; ++i) {
                storage_.push_back(0);
            }
        }

        std::size_t cols() const {
            return N;
        }

        std::size_t rows() const {
            return M;
        }

        double at(std::size_t i, std::size_t j) const {
            return storage_[i * N + j];
        }

        double &at(std::size_t i, std::size_t j) {
            return storage_[i * N + j];
        }

        std::size_t i_max(std::size_t h, std::size_t j) const {
            auto max = std::abs(at(h, j));
            auto max_i = h;
            for (std::size_t i = h + 1; i < M; ++i) {
                if (std::abs(at(i, j)) > max) {
                    max = at(i, j);
                    max_i = i;
                }
            }

            return max_i;
        }

        void swap_rows(std::size_t i1, std::size_t i2) {

            if (i1 == i2) {
                return;
            }

            for (std::size_t j = 0; j < N; ++j) {
                std::swap(at(i1, j), at(i2, j));
            }
        }

    private:
        std::vector<double> storage_;
        const std::size_t M, N;
    };

}


#endif //CIRCUITSIM_MATRIX_HH
