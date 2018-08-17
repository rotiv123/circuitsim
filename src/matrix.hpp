////
//// Created by vitor on 17-08-2018.
////
//
//#ifndef CIRCUITSIM_MATRIX_HPP
//#define CIRCUITSIM_MATRIX_HPP
//
//
//#include <circuitsim/config/export.h>
//#include <memory>
//
//namespace circuitsim {
//
//    class CIRCUITSIM_API matrix {
//    public:
//        matrix(std::size_t m, std::size_t n) noexcept;
//
//        matrix(matrix &&) noexcept;
//
//        ~matrix();
//
//        std::size_t cols() const;
//
//        std::size_t rows() const;
//
//        double at(std::size_t i, std::size_t j) const;
//
//        double &at(std::size_t i, std::size_t j);
//
//        std::size_t i_max(std::size_t h, std::size_t j) const;
//
//        void swap_rows(std::size_t i1, std::size_t i2);
//
//    private:
//        class impl;
//        friend class dc_context;
//
//        std::unique_ptr<impl> impl_;
//    };
//}
//
//#endif //CIRCUITSIM_MATRIX_HPP
