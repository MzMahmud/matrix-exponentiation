#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <initializer_list>
#include <iostream>

using std::initializer_list;

template <class T> class Matrix {
  public:
    Matrix(initializer_list<T> list) {
        n_row = list.size();
        n_col = 1;
        a     = new T[n_row * n_col];
        int i = 0;
        for (const auto &item : list)
            a[i++] = item;
    }

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
            int this_size = n_row * n_col;

            n_row = other.n_row;
            n_col = other.n_col;

            int other_size = other.n_row * other.n_col;
            if (this_size != other_size) {
                if (a != nullptr)
                    delete[] a;
                a = new T[other_size];
            }

            for (int i = 0; i < other_size; ++i)
                a[i] = other.a[i];
        }
        return *this;
    }

    Matrix &operator+=(const Matrix &other) {
        if (!this->has_same_dimention(other))
            throw "can not add mismatching dimention matrix";
        int size = n_row * n_col;
        for (int i = 0; i < size; ++i)
            a[i] += other.a[i];
        return *this;
    }

    Matrix &operator-=(const Matrix &other) {
        if (!this->has_same_dimention(other))
            throw "can not subtract mismatching dimention matrix";
        int size = n_row * n_col;
        for (int i = 0; i < size; ++i)
            a[i] -= other.a[i];
        return *this;
    }

    Matrix operator+(const Matrix &other) {
        Matrix m(*this);
        return m += other;
    }

    Matrix operator-(const Matrix &other) {
        Matrix m(*this);
        return m -= other;
    }

    Matrix operator*(const Matrix &other) {
        if (n_col != other.n_row)
            throw "can not multiply for invalid dimention";

        Matrix m(n_row, other.n_col);
        const Matrix &this_matrix = *this;
        for (int i = 0; i < m.n_row; ++i) {
            for (int j = 0; j < m.n_col; ++j) {
                for (int k = 0; k < n_col; ++k) {
                    T res = this_matrix(i, k) * other(k, j);
                    k == 0 ? m(i, j) = res : m(i, j) += res;
                }
            }
        }
        return m;
    }

    Matrix transpose() {
        Matrix m(n_col, n_row);
        const Matrix &this_matrix = *this;
        for (int i = 0; i < m.n_row; ++i) {
            for (int j = 0; j < m.n_col; ++j) {
                m(i, j) = this_matrix(j, i);
            }
        }
        return m;
    }

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

    bool has_same_dimention(const Matrix &other) {
        return n_row == other.n_row && n_col == other.n_col;
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