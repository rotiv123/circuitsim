//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_MATRIX_HH
#define CIRCUITSIM_MATRIX_HH

#include <vector>
#include <algorithm>
#include <cmath>

namespace circuitsim {

    struct matrix {

        matrix(std::size_t m, std::size_t n) noexcept : storage_{}, M{m}, N{n} {
            storage_.reserve(M * N);
            clear();
        }

        matrix resize(std::size_t m, std::size_t n) {
            matrix mt{m, n};
            mt.stamp(*this, 0, 0);
            return mt;
        }

        void clear() {
            storage_.clear();
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

        void stamp(const matrix &o, std::size_t i, std::size_t j) {
            for (std::size_t h = 0; h < std::min(o.rows(), rows()); ++h) {
                for (std::size_t k = 0; k < std::min(o.cols(), cols()); ++k) {
                    at(i + h, j + k) = o.at(h, k);
                }
            }
        }

    private:
        std::vector<double> storage_;
        std::size_t M, N;
    };

    //    template<class Matrix>
//    void print(const Matrix mat) {
//        using traits = circuitsim::matrix_traits<Matrix>;
//        const auto n = traits::cols(mat);
//        const auto m = traits::rows(mat);
//
//        for (int i = 0; i < m; ++i) {
//            std::cout << "[" << std::setw(9) << traits::at(mat, i, 0);
//            for (int j = 1; j < n; ++j) {
//                std::cout << ", " << std::setw(9) << traits::at(mat, i, j);
//            }
//            std::cout << "]" << std::endl;
//        }
//    }

}


#endif //CIRCUITSIM_MATRIX_HH
