#include <iostream>
#include <stdexcept>


#include "tmatrix.h"

using namespace std;

int main() {


    size_t n;
    cout << "enter the matrix dimension ";
    cin >> n;

    if (n == 0 || n > MAX_MATRIX_SIZE) {
        throw out_of_range("the matrix size must be greater than 0 and not exceed the max");
    }

    try {
        TDynamicMatrix<int> a(n), b(n), c(n);
        int i, j;

        for (i = 0; i < n; i++) {
            for (j = i; j < n; j++) {
                a[i][j] = i * 10 + j;
                b[i][j] = (i * 10 + j) * 100;
            }
        }

        cout << "Matrix A:\n" << a << endl;
        cout << "Matrix B:\n" << b << endl;

        c = a + b;
        cout << "result of addition (A + B):\n" << c << endl;

        c = a - b;
        cout << "result of subtraction (A - B):\n" << c << endl;

        int scalar = 5;
        c = a * scalar;
        cout << "result of multiplication (A * " << scalar << "):\n" << c << endl;

        TDynamicVector<int> v(n, 1);
        TDynamicVector<int> result = a * v;
        cout << "result of multiplying a matrix by a vector:\n" << result << endl;

        c = a * b;
        cout << "result of matix multiplication (A * B):\n" << c << endl;

    }
    catch (const out_of_range& e) {
        cout << "error: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}