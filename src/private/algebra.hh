//
// Created by vitor on 15-08-2018.
//

#ifndef CIRCUITSIM_ALGEBRA_HH
#define CIRCUITSIM_ALGEBRA_HH

#include <cstddef>
#include <cassert>

// #include <iostream>
// #include <iomanip>

namespace circuitsim {

    template<class Matrix>
    struct matrix_traits {

        static std::size_t cols(const Matrix &mat) {
            return mat.cols();
        }

        static std::size_t rows(const Matrix &mat) {
            return mat.rows();
        }

        static double at(const Matrix &mat, std::size_t i, std::size_t j) {
            return mat.at(i, j);
        }

        static double &at(Matrix &mat, std::size_t i, std::size_t j) {
            return mat.at(i, j);
        }

        static std::size_t i_max(const Matrix &mat, std::size_t h, std::size_t j) {
            return mat.i_max(h, j);
        }

        static void swap_rows(Matrix &mat, std::size_t i1, std::size_t i2) {
            mat.swap_rows(i1, i2);
        }
    };

    template<class Matrix>
    void to_row_echelon(Matrix &mat) {
        using traits = matrix_traits<Matrix>;

        const auto n = traits::cols(mat);
        const auto m = traits::rows(mat);
        std::size_t h = 0;
        std::size_t k = 0;

        while (h < m && k < n) {
            auto i_max = traits::i_max(mat, h, k);
            if (traits::at(mat, i_max, k) == 0) {
                ++k;
                continue;
            }

            traits::swap_rows(mat, h, i_max);
            for (std::size_t i = h + 1; i < m; ++i) {
                auto f = traits::at(mat, i, k) / traits::at(mat, h, k);
                traits::at(mat, i, k) = 0;
                for (std::size_t j = k + 1; j < n; ++j) {
                    traits::at(mat, i, j) -= traits::at(mat, h, j) * f;
                }
            }
            ++h;
            ++k;
        }
    }

    template<class Matrix>
    bool solve(Matrix &mat) {
        using traits = matrix_traits<Matrix>;
        const auto n = traits::cols(mat);
        const auto m = traits::rows(mat);
        const auto k1 = n - 1;
        assert(n == m + 1);

        to_row_echelon(mat);
        int h = (int) m - 1;

        while (h > -1) {
            if (traits::at(mat, h, h) == 0) {
                return false;
            }

            traits::at(mat, h, k1) /= traits::at(mat, h, h);
            traits::at(mat, h, h) = 1;
            for (int i = 0; i < h; ++i) {
                auto f = traits::at(mat, i, h);
                for (int j = i; j < h; ++j) {
                    traits::at(mat, i, j) -= traits::at(mat, h, j) * f;
                }
                traits::at(mat, i, h) = 0;
                traits::at(mat, i, k1) -= traits::at(mat, h, k1) * f;
            }

            --h;
        }

        return true;
    }

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

#endif //CIRCUITSIM_ALGEBRA_HH
