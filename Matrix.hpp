#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <initializer_list>
#include <iostream>

using std::initializer_list;

template <class T> class Matrix {
  public:
    Matrix(initializer_list<initializer_list<T>> list_of_list) {
        n_row = list_of_list.size();
        n_col = list_of_list.begin()->size();
        a     = new T[n_row * n_col];
        int i = 0;
        for (const auto &list : list_of_list) {
            for (const auto &item : list) {
                a[i++] = item;
            }
        }
    }

    Matrix(int n_row, int n_col) {
        this->n_row = n_row;
        this->n_col = n_col;
        this->a     = new T[this->n_row * this->n_col];
    }

    Matrix() : Matrix(2, 2) {}

    Matrix(int n_row, int n_col, const T &initial_value) : Matrix(n_row, n_col) {
        int size = n_row * n_col;
        for (int i = 0; i < size; ++i)
            a[i] = initial_value;
    }

    Matrix(const Matrix &other) : Matrix(other.n_row, other.n_col) {
        int size = n_row * n_col;
        for (int i = 0; i < size; ++i)
            a[i] = other.a[i];
    }

    ~Matrix() {
        if (a != nullptr)
            delete[] a;
    }

    Matrix &operator=(const Matrix &other) {
        if (this != &other) {
            clear();
            n_row    = other.n_row;
            n_col    = other.n_col;
            int size = n_row * n_col;
            for (int i = 0; i < size; ++i)
                a[i] = other.a[i];
        }
        return *this;
    }

    Matrix &operator+=(const Matrix &other) {}
    Matrix &operator-=(const Matrix &other) {}
    Matrix &operator*=(const Matrix &other) {}

    Matrix operator+(const Matrix &other) {}
    Matrix operator-(const Matrix &other) {}
    Matrix operator*(const Matrix &other) {}

    bool operator==(const Matrix &other) {
        if (n_row != other.n_row || n_col != other.n_col)
            return false;
        int size = n_row * n_col;
        for (int i = 0; i < size; ++i)
            if (a[i] != other.a[i])
                return false;
        return true;
    }

    T &operator()(int i, int j) { return a[get_index(i, j)]; }

    const T &operator()(int i, int j) const { return a[get_index(i, j)]; }

    int get_n_row() const { return n_row; }
    int get_n_col() const { return n_col; }

  private:
    T *a;
    int n_row, n_col;

    int get_index(int i, int j) const { return i * n_col + j; }

    void clear() {
        n_row = n_col = 0;
        if (a != nullptr)
            delete[] a;
    }
};

template <class T> std::ostream &operator<<(std::ostream &sout, const Matrix<T> &m) {
    for (int i = 0; i < m.get_n_row(); ++i) {
        for (int j = 0; j < m.get_n_col(); ++j) {
            sout << m(i, j) << " ";
        }
        sout << std::endl;
    }
    return sout;
}

#endif // __MATRIX_HPP__