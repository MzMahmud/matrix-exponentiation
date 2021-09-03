#include "Matrix.hpp"
#include <iostream>

using namespace std;

Matrix<int> getI(int n) {
    Matrix<int> I(n, n, 0);
    for (int i = 0; i < n; ++i)
        I(i, i) = 1;
    return I;
}

Matrix<int> matrix_exponentiation(const Matrix<int> &a, int n) {
    if (n == 0)
        return getI(a.get_n_row());
    Matrix<int> x = matrix_exponentiation(a, n >> 1);
    x             = x * x;
    return (n & 1) ? x * a : x;
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

    cout << "[a^10]\n";
    cout << matrix_exponentiation(a, 5);

    return 0;
}
