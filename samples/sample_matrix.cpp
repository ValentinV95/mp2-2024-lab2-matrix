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
    int fch;
    cout << "f you want to work only with matrices, press 1, if with matrices and vectors - 2, if only with vectors - 3, if with matrix and scalars - 4, with vectors and scalars - 5."<<endl;
    cin >> fch;
    if (fch == 1) {
        size_t sz, ch2;
        char ch;
        cout << "Enter matrix's sizes" << endl;
        cin >> sz;
        TDynamicMatrix<double> m(sz), m1(sz), res(sz);
        cout << "Enter first matrix" << endl;
        cin >> m;
        cout << "Enter second matrix" << endl;
        cin >> m1;
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
        if (ch == '+') res = m + m1;
        if (ch == '-') {
            if (ch2 == 0) res = m - m1;
            else res = m1 - m;
        }
        if (ch == '*') res = m * m1;

        cout << "Matrix m = " << endl << m << endl;
        cout << "Matrix m1 = " << endl << m1 << endl;
        cout << "Matrix res = m" << ch << "m1" << endl << res << endl;
    }
    else if (fch == 2) {
        size_t sz;
        cout << "Enter matrix and vector size" << endl;
        cin >> sz;
        TDynamicMatrix<double> m(sz);
        TDynamicVector<double> v(sz), res(sz);
        cout << "Enter matrix" << endl;
        cin >> m;
        cout << "Enter vector" << endl;
        cin >> v;
        cout << "the only operation between a matrix and a vector is multiplication, its result:"<<endl;
        res = m * v;
        cout << "Matrix m = " << endl << m << endl;
        cout << "Vector v = " << endl << v << endl;
        cout << "Vector res = m * b" << endl << res << endl;
    }
    else if (fch == 3) {
        size_t sz, ch2;
        char ch;
        cout << "Enter vector's size" << endl;
        cin >> sz;
        TDynamicVector<double> v(sz),v1(sz), res(sz);
        double r = 0.0;

        cout << "Enter first vector" << endl;
        cin >> v;
        cout << "Enter second vector" << endl;
        cin >> v1;
        cout << "Enter the operation + for vector addition, - for subtraction, * for multiplication" << std::endl;
        do {
            cin >> ch;
            if ((ch != '+') && (ch != '-') && (ch != '*')) {
                std::cout << "Wrong input. Try again." << std::endl;
            }
            else if (ch == '-') {
                cout << "Enter 0 if you want to subtract the second one from the first vector, and 1 otherwise " << endl;
                do {
                    cin >> ch2;
                } while (ch2 != 0 && ch2 != 1);
            }
        } while ((ch != '+') && (ch != '-') && (ch != '*'));
        if (ch == '+') res = v + v1;
        if (ch == '-') {
            if (ch2 == 0) res = v - v1;
            else res = v1 - v;
        }
        if (ch == '*') r = v * v1;

        cout << "Vector v = " << endl << v << endl;
        cout << "Vector v1 = " << endl << v1 << endl;
        cout << "Vector res = v" << ch << "v1" << endl << res << endl;
    }
    else if (fch == 4) {
        size_t sz;
        char ch;
        cout << "Enter matrix size" << endl;
        cin >> sz;
        TDynamicMatrix<double> m(sz), res(sz);
        double scal;
        cout << "Enter matrix" << endl;
        cin >> m;
        cout << "Enter scalar" << endl;
        cin >> scal;
        cout << "the only operation between a matrix and a scalar is multiplication, its result:"<<endl;
        res = m * scal;

        cout << "Matrix v = " << endl << m << endl;
        cout << "Scalar scal = " << endl << scal << endl;
        cout << "Matrix res = v*scal" << endl << res << endl;
    }
    else if (fch == 5) {
        size_t sz;
        char ch;
        cout << "Enter vector size" << endl;
        cin >> sz;
        TDynamicVector<double> v(sz), res(sz);
        double scal;
        cout << "Enter scalar" << endl;
        cin >> scal;

        cout << "Enter vector" << endl;
        cin >> v;
        cout << "Enter the operation + for addition, - for subtraction, * for multiplication" << std::endl;
        do {
            cin >> ch;
            if ((ch != '+') && (ch != '-') && (ch != '*')) {
                std::cout << "Wrong input. Try again." << std::endl;
            }
            
            
        } while ((ch != '+') && (ch != '-') && (ch != '*'));
        if (ch == '+') res = v + scal;
        if (ch == '-')  res = v - scal;
        if (ch == '*') res = v * scal;

        cout << "Vector v = " << endl << v << endl;
        cout << "Scalar scal = " << endl << scal << endl;
        cout << "Vector res = v" << ch << "scal" << endl << res << endl;
    }
}
//---------------------------------------------------------------------------
