////
//// Created by vitor on 17-08-2018.
////
//
//#include "matrix.hpp"
//#include "private/matrix.hh"
//
//
//namespace circuitsim {
//
//    matrix::matrix(std::size_t m, std::size_t n) noexcept : impl_{std::make_unique<impl>(m, n)} {}
//
//    matrix::matrix(matrix &&) noexcept = default;
//
//    matrix::~matrix() = default;
//
//    std::size_t matrix::cols() const {
//        return impl_->cols();
//    }
//
//    std::size_t matrix::rows() const {
//        return impl_->rows();
//    }
//
//    double matrix::at(std::size_t i, std::size_t j) const {
//        return impl_->at(i, j);
//    }
//
//    double &matrix::at(std::size_t i, std::size_t j) {
//        return impl_->at(i, j);
//    }
//
//    std::size_t matrix::i_max(std::size_t h, std::size_t j) const {
//        return impl_->i_max(h, j);
//    }
//
//    void matrix::swap_rows(std::size_t i1, std::size_t i2) {
//        return impl_->swap_rows(i1, i2);
//    }
//
//}