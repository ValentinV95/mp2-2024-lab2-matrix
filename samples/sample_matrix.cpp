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
	size_t size;
	char action;
	int d;

	setlocale(LC_ALL, "Russian");
	cout << "Матричный калькулятор\n" << endl;
	cout << "Как вы хотите заполнить данные?\n 1. Вручную\t2. Автоматически" << endl;
	cin >> d;
	if (d == 1)
	{
		do
		{
			cout << "Введите размер двух матриц.\n";
			cin >> size;
			TDynamicMatrix<double> A(size), B(size);
			cout << "Введите матрицу A\n";
			cin >> A;
			cout << "Введите матрицу B\n";
			cin >> B;
			cout << "Выберите действие:\n1. Сложение (+)\n2. Вычитание (-)\n3. Умножение (*)\n";
			cin >> action;

			switch (action)
			{
			case '1':
				cout << A + B << "\n";
				break;
			case '2':
				cout << A - B << "\n";
				break;
			case '3':
				cout << A * B << "\n";
				break;
			default:
				cout << "ОШИБКА\n";
				break;
			}

			cout << "Продолжить?\n1. Да\t2. Нет" << endl;
			cin >> action;
		} while (action != '2');
	}
	else if (d == 2)
	{
		do
		{
			cout << "Введите размер двух матриц.\n";
			cin >> size;
			TDynamicMatrix<double> A(size), B(size);
			cout << "Введите матрицу A\n";
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					A[i][j] = rand() % 100;
				}
			}
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					B[i][j] = rand() % 100;
				}
			}
			cout << A << endl;
			cout << B << endl;
			cout << "Выберите действие:\n1. Сложение (+)\n2. Вычитание (-)\n3. Умножение (*)\n";
			cin >> action;

			switch (action)
			{
			case '1':
				cout << A + B << "\n";
				break;
			case '2':
				cout << A - B << "\n";
				break;
			case '3':
				cout << A * B << "\n";
				break;
			default:
				cout << "ОШИБКА\n";
				break;
			}

			cout << "Продолжить?\n1. Да\t2. Нет" << endl;
			cin >> action;
		} while (action != '2');
	}
	else
	{
		cout << "Ошибка!";
	}
}
//---------------------------------------------------------------------------