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
	int choose, check;
	do {
		do {
			check = 1;
			cout << "\n-------------------------------------------------------------\n";
			cout << "Choose an action:\n";
			cout << "0 - exit\n";
			cout << "1 - vector + scalar\n";
			cout << "2 - vector - scalar\n";
			cout << "3 - vector * scalar\n";
			cout << "4 - vector + vector\n";
			cout << "5 - vector - vector\n";
			cout << "6 - scalar product of vectors\n";
			cout << "7 - matrix * scalar\n";
			cout << "8 - matrix * vector\n";
			cout << "9 - matrix + matrix\n";
			cout << "10 - matrix - matrix\n";
			cout << "11 - matrix * matrix\n";
			cin >> choose;
			for (int i = 0; i <= 11; i++) {
				if (choose == i) check = 0;
			}
			if (check) {
				system("cls");
				cout << "The action you selected does not exist.\n";
			}
		} while (check);

		double scalar;
		size_t sz;

		try {
		switch (choose)
		{
		case (1):
		{
			cout << "Enter vector size: ";
			cin >> sz;
			TDynamicVector<double> v(sz);
			cout << "Enter vector: ";
			cin >> v;
			cout << "Enter scalar: ";
			cin >> scalar;
			cout << "Result:\n" << v + scalar;
			break;
		}
		case (2):
		{
			cout << "Enter vector size: ";
			cin >> sz;
			TDynamicVector<double> v(sz);
			cout << "Enter vector: ";
			cin >> v;
			cout << "Enter scalar: ";
			cin >> scalar;
			cout << "Result:\n" << v - scalar;
			break;
		}
		case (3):
		{
			cout << "Enter vector size: ";
			cin >> sz;
			TDynamicVector<double> v(sz);
			cout << "Enter vector: ";
			cin >> v;
			cout << "Enter scalar: ";
			cin >> scalar;
			cout << "Result:\n" << v * scalar;
			break;
		}
		case (4):
		{
			cout << "Enter vector1 size:";
			cin >> sz;
			TDynamicVector<double> v1(sz);
			cout << "Enter vector2 size: ";
			cin >> sz;
			TDynamicVector<double> v2(sz);
			cout << "Enter vector1: ";
			cin >> v1;
			cout << "Enter vector2: ";
			cin >> v2;
			cout << "Result:\n" << v1 + v2;
			break;
		}
		case (5):
		{
			cout << "Enter vector1 size:";
			cin >> sz;
			TDynamicVector<double> v1(sz);
			cout << "Enter vector2 size: ";
			cin >> sz;
			TDynamicVector<double> v2(sz);
			cout << "Enter vector1: ";
			cin >> v1;
			cout << "Enter vector2: ";
			cin >> v2;
			cout << "Result:\n" << v1 - v2;
			break;
		}
		case (6):
		{
			cout << "Enter vector1 size: ";
			cin >> sz;
			TDynamicVector<double> v1(sz);
			cout << "Enter vector2 size:";
			cin >> sz;
			TDynamicVector<double> v2(sz);
			cout << "Enter vector1: ";
			cin >> v1;
			cout << "Enter vector2: ";
			cin >> v2;
			cout << "Result:\n" << v1 * v2;
			break;
		}
		case (7):
		{
			cout << "Enter matrix size: ";
			cin >> sz;
			TDynamicMatrix<double> A(sz);
			cout << "Enter matrix: ";
			cin >> A;
			cout << "Enter scalar: ";
			cin >> scalar;
			cout << "Result:\n" << A * scalar;
			break;
		}
		case (8):
		{
			cout << "Enter matrix size: ";
			cin >> sz;
			TDynamicMatrix<double> A(sz);
			cout << "Enter vector size: ";
			cin >> sz;
			TDynamicVector<double> v(sz);
			cout << "Enter matrix: ";
			cin >> A;
			cout << "Enter vector: ";
			cin >> v;
			cout << "Result:\n" << A * v;
			break;
		}
		case (9):
		{
			cout << "Enter matrix1 size: ";
			cin >> sz;
			TDynamicMatrix<double> A(sz);
			cout << "Enter matrix2 size:";
			cin >> sz;
			TDynamicMatrix<double> B(sz);
			cout << "Enter matrix1: ";
			cin >> A;
			cout << "Enter matrix2: ";
			cin >> B;
			cout << "Result:\n" << A + B;
			break;
		}
		case (10):
		{
			cout << "Enter matrix1 size: ";
			cin >> sz;
			TDynamicMatrix<double> A(sz);
			cout << "Enter matrix2 size:";
			cin >> sz;
			TDynamicMatrix<double> B(sz);
			cout << "Enter matrix1: ";
			cin >> A;
			cout << "Enter matrix2: ";
			cin >> B;
			cout << "Result:\n" << A - B;
			break;
		}
		case (11):
		{
			cout << "Enter matrix1 size: ";
			cin >> sz;
			TDynamicMatrix<double> A(sz);
			cout << "Enter matrix2 size:";
			cin >> sz;
			TDynamicMatrix<double> B(sz);
			cout << "Enter matrix1: ";
			cin >> A;
			cout << "Enter matrix2: ";
			cin >> B;
			cout << "Result:\n" << A * B;
			break;
		}
		}
		} catch (exception& e) { cout << e.what(); }
		} while (choose != 0);
}

//---------------------------------------------------------------------------