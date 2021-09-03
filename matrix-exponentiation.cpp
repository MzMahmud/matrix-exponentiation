#include "Matrix.hpp"
#include <iostream>

using namespace std;

Matrix<int> getI(int n) {
    Matrix<int> I(n, n, 0);
    for (int i = 0; i < n; ++i)
        I(i, i) = 1;
    return I;
}

Matrix<int> operator%(const Matrix<int> &a, int m) {
    Matrix<int> res(a);
    for (int i = 0; i < res.get_n_row(); ++i)
        for (int j = 0; j < res.get_n_col(); ++j)
            res(i, j) %= m;
    return res;
}

Matrix<int> matrix_exponentiation(const Matrix<int> &a, int n, int mod) {
    if (n == 0)
        return getI(a.get_n_row()) % mod;
    Matrix<int> x = matrix_exponentiation(a, n >> 1, mod);

    x = (x * x) % mod;
    return (n & 1) ? (x * a) % mod : x;
}

int main(int argc, char const *argv[]) {
    Matrix<int> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // Matrix<int> b = {{1, 2}, {3, 4}, {5, 6}};

    cout << "[a]";
    cout << a;
    // cout << "[b]\n";
    // cout << b;

    // cout << "[ab]\n";
    // cout << a * b;

    cout << "[a^100] mod 10\n";
    cout << matrix_exponentiation(a, 100, 10);

    return 0;
}
