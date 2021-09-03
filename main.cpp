#include "Matrix.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    cout << "hello world!" << endl;
    Matrix<int> a(3, 2, -1);
    cout << a;
    return 0;
}
