// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Тестирование класса работы с матрицами" << "\n" << "\n";

    int a;

    cout << "Выберите матричную операцию:" << "\n";
    cout << "1. Сумма двух матриц" << "\n" << "2. Разность двух матриц" << "\n" << "3. Умножение двух матриц" << "\n" << "4. Умножение матрицы на вектор" << "\n" << "5. Умножение матрицы на константу" << "\n";
    cin >> a;

    switch (a)
    {
    case 1: { //A + В
        size_t size = 0;
        cout << "Введите желаемый размер для матриц:" << "\n";
        cin >> size;

        TDynamicMatrix<double> A(size);
        cout << "Введите элементы матрицы:" << "\n";
        cin >> A;

        TDynamicMatrix<double> B(size);
        cout << "Введите элементы второй матрицы:" << "\n";
        cin >> B;

        cout << "Ответ:" << "\n";
        cout << A + B << "\n"; 

        break; }

    case 2: { //A - B
        size_t size = 0;
        cout << "Введите желаемый размер для матриц:" << "\n";
        cin >> size;

        TDynamicMatrix<double> A(size);
        cout << "Введите элементы матрицы:" << "\n";
        cin >> A;

        TDynamicMatrix<double> B(size);
        cout << "Введите элементы второй матрицы:" << "\n";
        cin >> B;

        cout << "Ответ:" << "\n";
        cout << A - B << "\n"; 
    
        break; }

    case 3: { // A * B
        size_t size = 0;
        cout << "Введите желаемый размер для матриц:" << "\n";
        cin >> size;

        TDynamicMatrix<double> A(size);
        cout << "Введите элементы матрицы:" << "\n";
        cin >> A;

        TDynamicMatrix<double> B(size);
        cout << "Введите элементы второй матрицы:" << "\n";
        cin >> B;

        cout << "Ответ:" << "\n";
        cout << A * B << "\n"; 
    
        break; }

    case 4: { // A * b
        size_t size = 0;
        cout << "Введите желаемый размер для матрицы и вектора:" << "\n";
        cin >> size;

        TDynamicMatrix<double> A(size);
        cout << "Введите элементы матрицы:" << "\n";
        cin >> A;

        TDynamicVector<double> b(size);
        cout << "Введите элементы вектора:" << "\n";
        cin >> b;

        cout << "Ответ:" << "\n";
        cout << A * b << "\n"; 
    
        break; }

    case 5: { // A * const
        size_t size = 0;
        cout << "Введите желаемый размер для матрицы:" << "\n";
        cin >> size;

        TDynamicMatrix<double> A(size);
        cout << "Введите элементы матрицы:" << "\n";
        cin >> A;

        double cons = 0;
        cout << "Введите константу:" << "\n";
        cin >> cons;

        cout << "Ответ:" << "\n";
        cout << A * cons << "\n"; 
    
        break;  }
    }

    return 0;
}