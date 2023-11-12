// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"

//---------------------------------------------------------------------------

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

void main()
{
   
    size_t sz,ch2;
    char ch;
    cout << "Enter matrix's sizes" << endl;
    cin >> sz;
    TDynamicMatrix<int> a(sz), b(sz), c(sz);
    cout << "Enter first matrix" << endl;
    cin >> a;
    cout << "Enter second matrix" << endl;
    cin >> b;
    cout << "Enter the operation + for matrix addition, - for subtraction, * for multiplication" << std::endl;
    do {
        cin >> ch;
        if ((ch != '+') && (ch != '-') && (ch != '*')) {
            std::cout << "Wrong input. Try again." << std::endl;
        }
        else if (ch == '-') {
            cout << "Enter 0 if you want to subtract the second one from the first matrix, and 1 otherwise " << endl;
            do {
                cin >> ch2;
            } while (ch2 != 0 && ch2 != 1);
        }
    } while ((ch != '+') && (ch != '-') && (ch != '*'));
    if (ch == '+') c = a + b;
    if (ch == '-') {
        if (ch2 == 0) c = a - b;
        else c = b - a;
    }
    if (ch == '*') c = a * b;

    cout << "Matrix a = " << endl << a << endl;
    cout << "Matrix b = " << endl << b << endl;
    cout << "Matrix c = a" << ch<< "b" << endl << c << endl;
}
//---------------------------------------------------------------------------
