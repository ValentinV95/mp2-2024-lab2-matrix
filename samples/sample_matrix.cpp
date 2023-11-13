// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

void main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Тестирование класс работы с матрицами. Матричный калькулятор" << endl;

    size_t n;
    char operation;
    cout << "Введите желаемую операцию:\n";
    cout << "1. Сложение векторов\n";
    cout << "2. Вычитание векторов\n";
    cout << "3. Скалярное произведение\n";
    cout << "4. Умножение матрицы на вектор\n";
    cout << "5. Умножение матрицы на скаляр\n";
    cout << "6. Сложение матриц\n";
    cout << "7. Вычитание матриц\n";
    cout << "8. Умножение матриц\n";
    cout << "Выбор: ";
    cin >> operation;

    switch (operation)
    {
    case '1':
    {
        try
        {
            cout << "Введите размер векторов для счета";
            cin >> n;
            TDynamicVector<double> a(n), b(n);
            cout << "Введите вектор 1 для счета построчно";
            cin >> a;
            cout << "Введите вектор 2 для счета построчно";
            cin >> b;

            cout << "c = a + b\n" << a + b;
        }
        catch (exception& e) {
            cout << "error: " << e.what() << endl;
            break;
        }
        break;
    }
    case '2':
    {
        try
        {
            cout << "Введите размер векторов для счета";
            cin >> n;
            TDynamicVector<double> a(n), b(n);
            cout << "Введите вектор 1 для счета построчно";
            cin >> a;
            cout << "Введите вектор 2 для счета построчно";
            cin >> b;

            cout << "c = a - b\n" << a - b;
        }
        catch (exception& e) {
            cout << "error: " << e.what() << endl;
            break;
        }
        break;
    }
    case '3':
    {
        try
        {
            cout << "Введите размер векторов для счета";
            cin >> n;
            TDynamicVector<double> a(n), b(n);
            cout << "Введите вектор 1 для счета построчно";
            cin >> a;
            cout << "Введите вектор 2 для счета построчно";
            cin >> b;

            cout << "c = (a, b)\n" << a * b;
        }
        catch (exception& e) {
            cout << "error: " << e.what() << endl;
            break;
        }
        break;
    }
    case '4':
    {
        try
        {
            cout << "Введите размер матрицы и вектора для счета";
            cin >> n;
            TDynamicMatrix<double> A(n);
            cout << "Введите матрицу для счета построчно";
            cin >> A;
            TDynamicVector<double> b(n);
            cout << "Введите вектор для счета построчно";
            cin >> b;

            cout << "C = A * b\n" << A * b;
        }
        catch (exception& e) {
            cout << "error: " << e.what() << endl;
            break;
        }
        break;
    }
   
    case '5':
    {
        try
        {
            cout << "Введите размер матриц для счета";
            cin >> n;
            TDynamicMatrix<double> A(n);
            double scalar;
            cout << "Введите матрицу для счета построчно";
            cin >> A;
            cout << "Введите скаляр";
            cin >> scalar;

            cout << "B = A * scalar\n" << A * scalar;
        }
        catch (exception& e) {
            cout << "error: " << e.what() << endl;
            break;
        }
        break;
    }
    case '6':
    {
        try
        {
            cout << "Введите размер матриц для счета";
            cin >> n;
            TDynamicMatrix<double> A(n), B(n);
            cout << "Введите матрицу 1 для счета построчно";
            cin >> A;
            cout << "Введите матрицу 2 для счета построчно";
            cin >> B;

            cout << "C = A + B\n" << A + B;
        }
        catch (exception& e) {
            cout << "error: " << e.what() << endl;
            break;
        }
        break;
    }
    case '7':
    {
        try
        {
            cout << "Введите размер матриц для счета";
            cin >> n;
            TDynamicMatrix<double> A(n), B(n);
            cout << "Введите матрицу 1 для счета построчно";
            cin >> A;
            cout << "Введите матрицу 2 для счета построчно";
            cin >> B;

            cout << "C = A - B\n" << A - B;
        }
        catch (exception& e) {
            cout << "error: " << e.what() << endl;
            break;
        }
        break;
    }
    case '8':
    {
        try
        {
            cout << "Введите размер матриц для счета";
            cin >> n;
            TDynamicMatrix<double> A(n), B(n);
            cout << "Введите матрицу 1 для счета построчно";
            cin >> A;
            cout << "Введите матрицу 2 для счета построчно";
            cin >> B;

            cout << "C = A * B\n" << A * B;
        }
        catch (exception& e) {
            cout << "error: " << e.what() << endl;
            break;
        }
        break;
    }
    }

}
//---------------------------------------------------------------------------
