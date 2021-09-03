#include "Matrix.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "hello world!" << endl;
    Matrix<int> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << a;
    {
        Matrix<int> b = a;
        b(0, 0)       = 10;
        cout << b;
    }
    cout << a;

    return 0;
}
