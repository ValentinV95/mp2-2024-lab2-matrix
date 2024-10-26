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
  setlocale(LC_ALL, "Russian");
  cout << "Тестирование класс работы с матрицами" << endl;
  cout << "Введите размер матрицы A и B: " << endl;
  int na, nb;
  cin >> na >> nb;
  cout << "Ввод матриц с клавиатуры(1) или случайное заполнение(2):" << endl;
  int t;
  cin >> t;
  TDynamicMatrix<int> A(na), B(nb);
  if (t == 1)
  {
      cout << "Введите матрицу A:" << endl;
      cin >> A;
      cout << "Введите матрицу B:" << endl;
      cin >> B;
  }
  else if (t == 2)
  {
      srand(time(NULL));
      for (int i = 0; i < na; i++)
      {
          for (int j = 0; j < na; j++)
          {
              A[i][j] = rand();
          }
      }
      for (int i = 0; i < nb; i++)
      {
          for (int j = 0; j < nb; j++)
          {
              B[i][j] = rand();
          }
      }
  }
  else throw exception("incorrect input");

  cout << "Введённые матрицы: " << endl;
  cout << A << endl << B << endl;
      
  cout << "Выберите номер доступной операции с матрицами: " << endl;
  cout << "1 A + B" << endl;
  cout << "2 A - B" << endl;
  cout << "3 B - A" << endl;
  cout << "4 A * B" << endl;
  cout << "5 B * A" << endl;

  cin >> t;

  TDynamicMatrix<int> C;
  if (t == 1)
  {
      C = A + B;
  }
  else if (t == 2)
  {
      C = A - B;
  }
  else if (t == 3)
  {
      C = B - A;
  }
  else if (t == 4)
  {
      C = A * B;
  }
  else if (t == 5)
  {
      C = B * A;
  }
  else throw exception("incorrect input");
  cout << C << endl;
  
  return;
}
//---------------------------------------------------------------------------