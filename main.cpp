#include "Matrix.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "hello world!" << endl;
    Matrix<int> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << a;
    return 0;
}
