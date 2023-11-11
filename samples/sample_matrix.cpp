// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------
typedef double T;
void filler(TDynamicMatrix<T> & input)
{
    size_t sz;
    cin >> sz;
    TDynamicMatrix<T> tmp(sz);
    cout << "Введите матрицу построчно: ";
    cin >> tmp;
    input = move(tmp);
}

void main()
{
    TDynamicMatrix<T> A, B, RES;
    int use;
    bool empty_A=true, empty_B = true;
    char contin = 'Y', op;
    setlocale(LC_ALL, "Russian");
    cout << "Матричный калькулятор" << endl;
    try {
        while (contin == 'Y' || contin == 'y')
        {

            if (empty_A) {
                cout << "Введите размер первого операнда: ";
                filler(A);
            }
            if (empty_B) {
                cout << "Введите размер второго операнда: ";
                filler(B);
            }
            cout << "Выберите операцию: + / - / * " << endl;
            cin >> op;
            switch (op)
            {
            case '+':
            {
                RES = A + B;
                break;
            }
            case '-':
            {
                RES = A - B;
                break;
            }
            case '*':
            {
                RES = A * B;
                break;
            }
            default:
                throw invalid_argument("Incorrect operation input");
            }
            cout << "A " << op << " B" " =" << endl << RES;
            cout << "Продолжить вычисления? Yy / Nn" << endl;
            cin >> contin;
            if (contin == 'N' || contin == 'n')  break;
            else if (contin != 'Y' && contin != 'y')
                throw invalid_argument("Incorrect action input");
            cout << "Использовать результат вычислений?" << endl << "1)Да, в качестве первого операнда" << endl << "2)Да, в качестве второго операнда" << endl << "3)Нет" << endl;
            cin >> use;
            switch (use)
            {
            case 1:
            {
                empty_B = true;
                empty_A = false;
                A = RES;
                break;
            }
            case 2:
            {
                empty_A = true;
                empty_B = false;
                B = RES;
                break;
            }
            case 3:
            {
                empty_A = true;
                empty_B = true;
                break;
            }
            default:
                throw invalid_argument("Incorrect action input");
            }

        }
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
}
//---------------------------------------------------------------------------
