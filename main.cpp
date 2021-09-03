#include "Matrix.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "hello world!" << endl;
    Matrix<int> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "[a]\n";
    cout << a;
    {
        Matrix<int> b = a;
        b(0, 0)       = 10;
        cout << "[b]\n";
        cout << b;

        cout << "[a+b]\n";
        cout << (a + b);
        cout << "[a-b]\n";
        cout << (a - b);
        cout << "[a]\n";
        cout << a;
        cout << "[b]\n";
        cout << b;
    }

    return 0;
}
