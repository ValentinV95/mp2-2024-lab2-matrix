// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
#include <string>
//---------------------------------------------------------------------------

void main()
{
	size_t sz = 0;
	char action = 0;
	string inp = "";
	string buff_to_ignore = "";

	setlocale(LC_ALL, "Russian");
	cout << "Матричный калькулятор.\n";

	do
	{
		try
		{
			cout << "Выберите действие:\n(+) Сложить две матрицы\n(-) Вычесть две матрицы\n(*) Умножить две матрицы\n(q) Выйти\n";
			cin >> inp;

			if (inp.length() > 1)
			{
				// предотвращаем попадание неправильного ввода в inp
				// например, когда пользователь ввёл строку вида "a a a a a a a"
				cin.clear();
				getline(cin, buff_to_ignore);
				throw invalid_argument("Неверный ввод.");
			}

			if (inp[0] == 'q') break;
			else if (inp[0] == '+' || inp[0] == '-' || inp[0] == '*') action = inp[0];
			else
			{
				cin.clear();
				getline(cin, buff_to_ignore);
				throw invalid_argument("Неверный ввод.");
			}

			cin.clear();
			getline(cin, buff_to_ignore);
			cout << "Введите размер матриц.\n";
			if (!(cin >> sz))
			{
				cin.clear();
				getline(cin, buff_to_ignore);
				throw invalid_argument("Неверный ввод.");
			}

			cin.clear();
			getline(cin, buff_to_ignore);
			TDynamicMatrix<double> m1(sz), m2(sz);
			cout << "Введите матрицу A:\n";
			cin >> m1;
			cin.clear();
			getline(cin, buff_to_ignore);

			cout << "Введите матрицу B:\n";
			cin >> m2;
			cin.clear();
			getline(cin, buff_to_ignore);

			switch (action)
			{
			case '+':
				cout << "Результат:\n" << m1 + m2 << "\n";
				break;
			case '-':
				cout << "Результат:\n" << m1 - m2 << "\n";
				break;
			case '*':
				cout << "Результат:\n" << m1 * m2 << "\n";
				break;
			default:
				break;
			}
		}

		catch (const exception& e)
		{
			cerr << e.what() << endl;
			cin.clear();
			getline(cin, buff_to_ignore);
		}

		cout << "Конец работы? (y/Y/д/Д)\n";
		cin >> action;
		cin.clear();
		getline(cin, buff_to_ignore);
	} while (action != 'y' && action != 'Y' && action != 'д' && action != 'Д');
}
//---------------------------------------------------------------------------
