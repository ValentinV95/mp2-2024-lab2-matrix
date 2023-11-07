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
	size_t sz;
	char action;

	setlocale(LC_ALL, "Russian");
	cout << "Матричный калькулятор\n";

	do
	{
		cout << "Введите размер двух матриц.\n";
		cin >> sz;
		TDynamicMatrix<double> m1(sz), m2(sz);
		cout << "Введите матрицу A\n";
		cin >> m1;
		cout << "Введите матрицу B\n";
		cin >> m2;
		cout << "Выберите действие:\n1. Сложение (+)\n2. Вычитание (-)\n3. Умножение (*)\n";
		cin >> action;

		switch (action)
		{
		case '+':
			cout << m1 + m2 << "\n";
			break;
		case '-':
			cout << m1 - m2 << "\n";
			break;
		case '*':
			cout << m1 * m2 << "\n";
			break;
		default:
			cout << "Нераспознанное действие.\n";
			break;
		}

		cout << "Продолжить (y/n)?";
		cin >> action;
	} while (action != 'n' && action != 'N' && action != 'н' && action != 'Н');
}
//---------------------------------------------------------------------------
