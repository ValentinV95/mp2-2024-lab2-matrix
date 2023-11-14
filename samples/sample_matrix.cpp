// основа.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "tmatrix.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Тестирование класса работы с матрицами" << endl;
    int n;
    cout << "Выберите операцию:" << endl;
    cout << "1. Сумма двух матриц" << endl;
    cout << "2. Разность двух матриц" << endl;
    cout << "3. Умножение двух матриц" << endl;
    cout << "4. Умножение матрицы на вектор" << endl;
    cout << "5. Умножение матрицы на константу" << endl;
    cin >> n;
    size_t size = 0;
    switch(n)
 {
     case 1:
    {
        cout << "Введите размер матриц:" << endl;
        cin >> size;
        TDynamicMatrix<double> A(size);
        cout << "Введите элементы первой матрицы:" << endl;
        cin >> A;
        TDynamicMatrix<double> B(size);
        cout << "Введите элементы второй матрицы:" << endl;
        cin >> B;
        cout << "Результат:" << endl;
        cout << A + B << endl;
        break;
    }
     case 2:
    {
        cout << "Введите размер матриц:" << endl;
        cin >> size;
        TDynamicMatrix<double> A(size);
        cout << "Введите элементы первой матрицы:" << endl;
        cin >> A;
        TDynamicMatrix<double> B(size);
        cout << "Введите элементы второй матрицы:" << endl;
        cin >> B;
        cout << "Результат:" << endl;
        cout << A - B << endl;
        break;
    }
     case 3:
    {
        cout << "Введите размер матриц:" << endl;
        cin >> size;
        TDynamicMatrix<double> A(size);
        cout << "Введите элементы первой матрицы:" << endl;
        cin >> A;
        TDynamicMatrix<double> B(size);
        cout << "Введите элементы второй матрицы:" << endl;
        cin >> B;
        cout << "Результат:" << endl;
        cout << A * B << endl;
        break;
    }
     case 4:
    {
        cout << "Введите размер матрицы и вектора:" << endl;
        cin >> size;
        TDynamicMatrix<double> A(size);
        cout << "Введите элементы матрицы:" << endl;
        cin >> A;
        TDynamicVector<double> b(size);
        cout << "Введите элементы вектора:" << endl;
        cin >> b;
        cout << "Результат:" << endl;
        cout << A * b << endl;
        break;
    }
     case 5:
    {
        cout << "Введите размер матрицы" << endl;
        cin >> size;
        TDynamicMatrix<double> A(size);
        cout << "Введите элементы матрицы:" << endl;
        cin >> A;
        double constanta = 0;
        cout << "Введите константу:" << endl;
        cin >> constanta;
        cout << "Результат:" << endl;
        cout << A * constanta << endl;
        break;
    }
  }   
 return 0;
}
