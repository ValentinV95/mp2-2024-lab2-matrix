#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Тестирование класса работы с матрицами" << "\n" << "\n";

    int a;

    cout << "Выберите матричную операцию:" << "\n";
    cout << "1. Сложение двух матриц" << "\n" << "2. Разность двух матриц" << "\n" << "3. Умножение двух матриц" << "\n" << "4. Умножение матрицы на вектор" << "\n" << "5. Умножение матрицы на скаляр" << "\n";
    cin >> a;

    if (a == 1)
    {
        size_t size = 0;
        cout << "Введите размер матриц:" << "\n";
        cin >> size;
        

        TDynamicMatrix<double> A(size);
        cout << "Введите элементы матрицы А:" << "\n";
        cin >> A;
        

        TDynamicMatrix<double> B(size);
        cout << "Введите элементы матрицы В:" << "\n";
        cin >> B;

        cout << "Ответ:" << "\n";
        cout << A + B << "\n";
    }

    if (a == 2)
    {
        size_t size = 0;
        cout << "Введите размер матриц:" << "\n";
        cin >> size;

        TDynamicMatrix<double> A(size);
        cout << "Введите элементы матрицы А:" << "\n";
        cin >> A;

        TDynamicMatrix<double> B(size);
        cout << "Введите элементы матрицы В:" << "\n";
        cin >> B;

        cout << "Ответ:" << "\n";
        cout << A + B << "\n";
    }

    if (a == 3)
    {
        size_t size = 0;
        cout << "Введите размер матриц:" << "\n";
        cin >> size;

        TDynamicMatrix<double> A(size);
        cout << "Введите элементы матрицы А:" << "\n";
        cin >> A;

        TDynamicMatrix<double> B(size);
        cout << "Введите элементы матрицы В:" << "\n";
        cin >> B;

        cout << "Ответ:" << "\n";
        cout << A + B << "\n";
    }

    if (a == 4)
    {
        size_t size = 0;
        cout << "Введите размер матрицы и вектора:" << "\n";
        cin >> size;

        TDynamicMatrix<double> A(size);
        cout << "Введите элементы матрицы:" << "\n";
        cin >> A;

        TDynamicVector<double> b(size);
        cout << "Введите элементы вектора:" << "\n";
        cin >> b;

        cout << "Ответ:" << "\n";
        cout << A * b << "\n";
    }

    if (a == 5)
    {
        size_t size = 0;
        cout << "Введите размер матрицs:" << "\n";
        cin >> size;

        TDynamicMatrix<double> A(size);
        cout << "Введите элементы матрицы А:" << "\n";
        cin >> A;

        double skl = 0;
        cout << "Введите скаляр:" << "\n";
        cin >> skl;

        cout << "Ответ:" << "\n";
        cout << A * skl << "\n";
    }

    return 0;

}
