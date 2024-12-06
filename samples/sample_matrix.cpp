#include <iostream>
#include <stdexcept>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    size_t n;
    cout << "Введите размерность матриц: ";
    cin >> n;

    if (n == 0 || n > MAX_MATRIX_SIZE) {
        throw out_of_range("Размер матрицы должен быть больше нуля и не превышать " + to_string(MAX_MATRIX_SIZE));
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

        cout << "Матрица A:\n" << a << endl;
        cout << "Матрица B:\n" << b << endl;

        c = a + b;
        cout << "Результат сложения (A + B):\n" << c << endl;

        c = a - b;
        cout << "Результат вычитания (A - B):\n" << c << endl;

        int scalar = 5;
        c = a * scalar;
        cout << "Результат умножения (A * " << scalar << "):\n" << c << endl;

        TDynamicVector<int> v(n, 1);
        TDynamicVector<int> result = a * v;
        cout << "Результат умножения матрицы на вектор:\n" << result << endl;

        c = a * b;
        cout << "Результат умножения матриц (A * B):\n" << c << endl;

    }
    catch (const out_of_range& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Произошла непредвиденная ошибка: " << e.what() << endl;
    }

    return 0;
}