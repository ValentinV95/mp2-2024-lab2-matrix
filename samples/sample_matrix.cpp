// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Тестирование класс работы с матрицами\n\n";
    bool _run = 1;
    char a = '0';
    do
    {
        size_t _sz = 0;
        do
        {
            cout << "Введите предпочтительный размер матрицы: ";
            cin >> _sz;
            if (_sz <= 0 || _sz > MAX_MATRIX_SIZE)
                cout << "Программа поддерживает только квадратные вещественные матрицы размера до " << MAX_MATRIX_SIZE << '\n' << endl;
        } while (_sz <= 0 || _sz > MAX_MATRIX_SIZE);
        {
            TDynamicMatrix<double> A(_sz), B(_sz), C(_sz);
            TDynamicVector<double> s(_sz), t(_sz), v(_sz);
            double X, Y;
            unsigned int O1 = 3, O2 = 3, Op = 4, OpAvail = 0;
            bool bar = 1;
            char snafu = '8';
            const string foo = "\nПожалуйста, скопируйте результат в буфер обмена для дальнейшего использования. ";
            const string Operations[4] = { "Доступна только операция умножения. ", "Выберите операцию: * – 1, / – 2\t", "Выберите операцию: + – 1, - – 2, * – 3\t", "Выберите операцию: + – 1, - – 2, * – 3, / – 4\t"};
            do
            {
                //Выбор операторов пользователем
                {
                    do
                    {
                        cout << "Выберите левый операнд: Вектор - 1, Матрица - 2  ";
                        cin >> O1;
                        O1 -= 1;
                    } while (O1 >= 2);
                    do
                    {
                        cout << "Выберите правый операнд: Скаляр - 1, Вектор - 2, Матрица - 3  ";
                        cin >> O2;
                        O2 -= 1;
                    } while (O2 >= 3);
                }
                //Определение доступных операций
                {
                    if (O2)
                        O2 -= 1;
                    else
                        O2 = 2;
                    if (!(O1 + O2 == 1))
                    {
                        if (O1 == O2)
                            OpAvail = 2;
                        else if (!O1)
                            OpAvail = 3;
                        else OpAvail = 1;
                    }
                }
                //Выбор операции пользователем
                {
                    if (OpAvail)
                    {
                        do
                        {
                            cout << Operations[OpAvail];
                            cin >> Op;
                            Op -= 1;
                        } while (Op > OpAvail);
                        if (OpAvail == 1)
                            Op += 2;
                    }
                    else
                    {
                        cout << Operations[OpAvail];
                        Op = 2;
                        system("pause");
                    }
                }
                // Введение левого операнда
                {
                    if (O1 == 0)
                    {
                        cout << "Ввведите левый операнд вектор:\t";
                        cin >> s;
                    }
                    else
                    {
                        cout << "Ввведите левый операнд матрица:\t";
                        cin >> A;
                    }
                }
                //Введение правого операнда
                {
                    if (O2 == 0)
                    {
                        cout << "Ввведите правый операнд вектор:\t";
                        cin >> t;
                    }
                    else if (O2 == 1)
                    {
                        cout << "Ввведите правый операнд матрица:\t";
                        cin >> B;
                    }
                    else
                    {
                        cout << "Ввведите правый операнд скаляр:\t";
                        cin >> X;
                        auto Q = X;
                    }
                    if (OpAvail == 0)
                    {
                        if (O1 == 0)
                            v = s * B;
                    }
                }
                // Выборка и исполнение операции
                if (OpAvail == 0)
                {
                    if (O1 == 0)
                    {
                        v = s * B;
                        cout << "Результат:\n" << v << foo << endl;
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        v = A * t;
                        cout << "Результат:\n" << v << foo << endl;
                        system("pause");
                        system("cls");
                    }
                }
                else if (OpAvail == 1)
                {
                    if (Op == 2)
                    {
                        C = A * X;
                        cout << "Результат:\n" << C << foo << endl;
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        try
                        {
                            C = A / X;
                            cout << "Результат:\n" << C << foo << endl;
                        }
                        catch (const exception& e) { cout << e.what() << endl; }
                        system("pause");
                        system("cls");
                    }

                }
                else if (OpAvail == 2)
                {
                    if (O1 == 0)
                    {
                        if (Op == 0)
                        {
                            v = s + t;
                            cout << "Результат:\n" << v << foo << endl;
                            system("pause");
                            system("cls");
                        }
                        else if (Op == 1)
                        {
                            v = s - t;
                            cout << "Результат:\n" << v << foo << endl;
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            Y = s * t;
                            cout << "Результат:\n" << Y << foo << endl;
                            system("pause");
                            system("cls");
                        }
                    }
                    else
                    {
                        if (Op == 0)
                        {
                            C = A + B;
                            cout << "Результат:\n" << C << foo << endl;
                            system("pause");
                            system("cls");
                        }
                        else if (Op == 1)
                        {
                            C = A - B;
                            cout << "Результат:\n" << C << foo << endl;
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            C = A * B;
                            cout << "Результат:\n" << C << foo << endl;
                            system("pause");
                            system("cls");
                        }
                    }
                }
                else
                {
                    if (Op == 0)
                    {
                        v = s + X;
                        cout << "Результат:\n" << v << foo << endl;
                        system("pause");
                        system("cls");
                    }
                    else if (Op == 1)
                    {
                        v = s - X;
                        cout << "Результат:\n" << v << foo << endl;
                        system("pause");
                        system("cls");
                    }
                    else if (Op == 2)
                    {
                        v = s * X;
                        cout << "Результат:\n" << v << foo << endl;
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        try
                        {
                            v = s / X;
                            cout << "Результат:\n" << v << foo << endl;
                        }
                        catch (const exception& e) { cout << e.what() << endl; }
                        system("pause");
                        system("cls");
                    }
                }
                O1 = 3, O2 = 3, Op = 4, OpAvail = 0;
                do
                {
                    cout << "Желаете продолжить вычисления? Y/N\t";
                    cin >> snafu;
                } while (snafu != 'Y' && snafu != 'y' && snafu != 'N' && snafu != 'n');
                if (snafu == 'N' || snafu == 'n')
                {
                    bar = 0;
                    snafu = '8';
                }
            }while (bar);
        }
        do
        {
            cout << "Желаете закончить работу? Y/N\t";
            cin >> a;
        } while (a != 'Y' && a != 'y' && a != 'N' && a != 'n');
        if (a == 'Y' || a == 'y')
        {
            _run = 0;
            a = '0';
        }
    } while (_run);
    return 0;
}
