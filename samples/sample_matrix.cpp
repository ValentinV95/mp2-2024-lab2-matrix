// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

int fmenu(char* a[], int n)
{
    int k; 
    cout << "Меню:" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
    cout << "Введите номер желаемого действия:" << endl;
    cin >> k; 
    return k;
}

void main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Тестирование класс работы с матрицами" << endl;
    int count = 14;
    char* pmenu[14] = { "1) Выполнить сложение вектора со скаляром", "2) Выполнить вычитание из вектора скаляра", "3) Выполнить умножение вектора на скаляр", "4) Выполнить сравнение векторов", "5) Выполнить сложение векторов", "6) Выполнить вычитание векторов", "7) Выполнить умножение векторв", "8) Выполнить сравнение матриц", "9) Выполнить умножение матрицы на скаляр", "10) Выполнить умножение матрицы на вектор", "11) Выполнить сложение матриц", "12) Выполнить вычитание матриц", "13) Выполнить умножение матриц", ">13) Выход"};
    int k; 
    int i, j, r, d;
    double l, m;
    cout << "Введите размер первой матрицы" << endl;
    cin >> i;
    cout << "Введите размер второй матрицы" << endl;
    cin >> j;
    cout << "Введите размер первого вектора" << endl;
    cin >> r;
    cout << "Введите размер второго вектора" << endl;
    cin >> d;
    cout << "Введите скаляр" << endl;
    cin >> l;
    TDynamicMatrix<double> a(i), b(j), c;
    TDynamicVector<double> v(r), s(d), f;
    cout << "Введите матрицу a" << endl;
    cin >> a;
    cout << "Введите матрицу b" << endl;
    cin >> b;
    cout << "Введите вектор v" << endl;
    cin >> v;
    cout << "Введите вектор s" << endl;
    cin >> s;

    do
    {
        k = fmenu(pmenu, count);
        if ((k > 0) && (k <= 13))
        {
            switch (k)
            {
            case 1: {
                f = v + l;
                cout << "Вектор f = v + l" << endl << f << endl;
                break;
            }
            case 2: {
                f = v - l;
                cout << "Вектор f = v - l" << endl << f << endl;
                break;
            }
            case 3: {
                f = v * l;
                cout << "Вектор f = v * l" << endl << f << endl;
                break;
            }
            case 4: {
                cout << "v == s" << endl << (v == s) << endl;
                break;
            }
            case 5: {
                f = v + s;
                cout << "Вектор f = v + s" << endl << f << endl;
                break;
            }
            case 6: {
                f = v - s;
                cout << "Вектор f = v - s" << endl << f << endl;
                break;
            }
            case 7: {
                m = v * s;
                cout << "Скаляр m" << endl << m << endl;
                break;
            }
            case 8: {
                cout << "a == b" << endl << (a == b) << endl;
                break;
            }
            case 9: {
                c = a * l;
                cout << "Матрица c = a * l" << endl << c << endl;
                break;
            }
            case 10: {
                f = a * v;
                cout << "Вектор f = a * v" << endl << f << endl;
                break;
            }
            case 11: {
                c = a + b;
                cout << "Матрица c = a + b" << endl << c << endl;
                break;
            }
            case 12: {
                c = a - b;
                cout << "Матрица c = a - b" << endl << c << endl;
                break;
            }
            case 13: {
                c = a * b;
                cout << "Матрица c = a * b" << endl << c << endl;
                break;
            }
            }
        }
    } while (k <= 13);
}
//---------------------------------------------------------------------------
