#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstddef>

template <class T> class Matrix {
  public:
    Matrix() {}
    Matrix(const Matrix &other) {}
    Matrix(size_t n_row, size_t n_col) {}
    Matrix(size_t n_row, size_t n_col, const T &initial_value) {}
    ~Matrix() {}

    Matrix &operator=(const Matrix &other) {}
    Matrix &operator+=(const Matrix &other) {}
    Matrix &operator-=(const Matrix &other) {}
    Matrix &operator*=(const Matrix &other) {}

    Matrix operator+(const Matrix &other) {}
    Matrix operator-(const Matrix &other) {}
    Matrix operator*(const Matrix &other) {}

    bool operator==(const Matrix &other) {}

    T &operator()(size_t i, size_t j) {}

  private:
    T *a;
    size_t n_row, n_col;
};

#endif // __MATRIX_HPP__