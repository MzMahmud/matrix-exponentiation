#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstddef>
#include <iostream>

template <class T> class Matrix {
  public:
    Matrix(size_t n_row, size_t n_col) {
        this->n_row = n_row;
        this->n_col = n_col;
        this->a     = new T[this->n_row * this->n_col];
    }

    Matrix() : Matrix(2, 2) {}

    Matrix(size_t n_row, size_t n_col, const T &initial_value) : Matrix(n_row, n_col) {
        for (int i = 0; i < this->n_row * this->n_col; ++i)
            this->a[i] = initial_value;
    }

    Matrix(const Matrix &other) : Matrix(other.n_row, other.n_col) {
        for (int i = 0; i < this->n_row * this->n_col; ++i)
            this->a[i] = other.a[i];
    }

    ~Matrix() {
        if (a != nullptr)
            delete[] a;
    }

    Matrix &operator=(const Matrix &other) {}
    Matrix &operator+=(const Matrix &other) {}
    Matrix &operator-=(const Matrix &other) {}
    Matrix &operator*=(const Matrix &other) {}

    Matrix operator+(const Matrix &other) {}
    Matrix operator-(const Matrix &other) {}
    Matrix operator*(const Matrix &other) {}

    bool operator==(const Matrix &other) {
        if (n_row != other.n_row || n_col != other.n_col)
            return false;
        size_t size = n_row * n_col;
        for (int i = 0; i < size; ++i)
            if (a[i] != other.a[i])
                return false;
        return true;
    }

    T &operator()(size_t i, size_t j) { return a[get_index(i, j)]; }

    size_t n_row() const { return n_row; }
    size_t n_col() const { return n_col; }

  private:
    T *a;
    size_t n_row, n_col;

    size_t get_index(size_t i, size_t j) { return i * n_row + j; }
};

template <class T> std::ostream &operator<<(std::ostream &sout, const Matrix<T> &m) {
    for (int i = 0; i < m.n_row(); ++i) {
        for (int j = 0; j < m.n_col(); ++j) {
            sout << m(i, j) << " ";
        }
        sout << std::endl;
    }
    return sout;
}

#endif // __MATRIX_HPP__