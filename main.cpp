#include "Matrix.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    Matrix<int> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> b = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> c = {{1, -8}, {7, -4}, {15, 60}};

    try {
        cout << "[a]\n";
        cout << a;

        cout << "[b]\n";
        cout << b;

        cout << "[c]\n";
        cout << c;

        cout << "[a * b]\n";
        cout << a * b;

        // cout << "[a + b]\n";
        // cout << a + b;

        // cout << "[a - b]\n";
        // cout << a - b;

        cout << "[b + c]\n";
        cout << b + c;

        cout << "[c - b]\n";
        cout << c - b;
    } catch (const char *message) {
        cout << message << endl;
    }

    return 0;
}
