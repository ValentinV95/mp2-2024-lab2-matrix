// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include <iomanip>
#include <random>
#include "tmatrix.h"
//---------------------------------------------------------------------------

int main()
{
    auto randFill = [](TDynamicMatrix<double>& m) {
        random_device rd;
        mt19937 mt(rd());
        uniform_real_distribution<double> dist(-100.0, 100.0);
        for (size_t i = 0; i < m.size(); ++i)
            for (size_t j = 0; j < m.size(); ++j)
                m[i][j] = dist(mt);
    };
    try {
        size_t sa, sb;
        char sym;

        setlocale(LC_ALL, "Russian");
        cout << "Тестирование класс работы с матрицами" << endl;
        cout << "Введите размеры двух матриц" << endl;
        cin >> sa;
        cin >> sb;
        TDynamicMatrix<double> a(sa), b(sb), c;
        TDynamicVector<double> v(sa);
        double t;
        cout << endl << "Ввести матрицы с клавиатуры (y), иначе заполнить их случайным образом (n)" << endl;
        cin >> sym;

        if (sym == 'y') {
            cin >> a;
            cin >> b;
        }
        else if (sym == 'n') {
            randFill(a);
            randFill(b);
        }
        else {
            cout << "Некорректный ввод" << endl;
            return 0;
        }

        cout << "Matrix a = " << endl << a << endl;
        cout << "Matrix b = " << endl << b << endl;

        cout << endl << "Выберите бинарную операцию: '+' для сложения, '-' для вычитания, '=' для сравнения, '*' для произведения, 'v' чтобы вычислить произведение первой введенной матрицы на вектор, 't' чтобы вычислить произведение первой введенной матрицы на число" << endl;
        cin >> sym;
        switch (sym) {
        case '+':
            c = a + b;
            cout << "Matrix c = a + b" << endl << c << endl;
            break;

        case '-':
            c = a - b;
            cout << "Matrix c = a - b" << endl << c << endl;
            break;

        case '=':
            cout << "a == b - " << (a == b) << endl;
            break;

        case '*':
            c = a * b;
            cout << "Matrix c = a * b" << endl << c << endl;
            break;

        case 'v':
            cout << endl << "Введите вектор" << endl;
            cin >> v;
            v = a * v;
            cout << "Matrix c = a * v" << endl << v << endl;
            break;

        case 't':
            cout << endl << "Введите число" << endl;
            cin >> t;
            c = a * t;
            cout << "Matrix c = a * t" << endl << c << endl;
            break;

        default:
            cout << "Некорректный ввод" << endl;
            return 0;
        }
    }

    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
//---------------------------------------------------------------------------
