// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"

//---------------------------------------------------------------------------

void randomFillingTDynamicVector(TDynamicVector<int>& v)
{
    
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = rand();
    }
    return;
}

void randomFillingTDynamicMatrix(TDynamicMatrix<int>& A)
{
    for (int i = 0; i < A.size(); i++)
    {
        randomFillingTDynamicVector(A[i]);
    }
    return;
}

void main()
{
  setlocale(LC_ALL, "Russian");
  srand(time(NULL));
  cout << "Тестирование класс работы с матрицами" << endl;
  cout << "Выберите номер доступной операции с матрицами: " << endl;
  cout << "1 A + B" << endl;
  cout << "2 A - B" << endl;
  cout << "3 A * B" << endl;
  cout << "4 a * A" << endl;
  cout << "5 A * v" << endl;

  int t;
  cin >> t;

  if (t == 1 || t == 2 || t == 3)
  {
      cout << "Введите размер матрицы A и B: " << endl;

      int na, nb;
      cin >> na >> nb;

      cout << "Ввод матриц с клавиатуры(1) или случайное заполнение(2):" << endl;

      int t1;
      cin >> t1;
      TDynamicMatrix<int> A(na), B(nb);

      if (t1 == 1)
      {
          cout << "Введите матрицу A:" << endl;
          cin >> A;
          cout << "Введите матрицу B:" << endl;
          cin >> B;
      }
      else if (t1 == 2)
      {
          randomFillingTDynamicMatrix(A);
          randomFillingTDynamicMatrix(B);
      }
      else throw exception("incorrect input");

      cout << "Введённые матрицы: " << endl;
      cout << A << endl << B << endl;
      TDynamicMatrix<int> C;
      if (t == 1)
      {
          C = A + B;
      }
      else if (t == 2)
      {
          C = A - B;
      }
      else 
      {
          C = A * B;
      }
      cout << C << endl;
  }
  else if (t == 4 || t == 5)
  {
      cout << "Введите размер матрицы A: " << endl;

      int na;
      cin >> na;

      cout << "Ввод матрицы с клавиатуры(1) или случайное заполнение(2):" << endl;

      int t1;
      cin >> t1;
      TDynamicMatrix<int> A(na);

      if (t1 == 1)
      {
          cout << "Введите матрицу A:" << endl;
          cin >> A;
      }
      else if (t1 == 2)
      {
          randomFillingTDynamicMatrix(A);
      }
      else throw exception("incorrect input");

      cout << "Введённая матрица: " << endl;
      cout << A << endl;

      if (t == 4)
      {
          cout << "Введите константу: " << endl;
          int alpha;
          cin >> alpha;
          cout << A * alpha << endl;
      }
      else
      {
          cout << "Ввод вектора с клавиатуры(1) или случайное заполнение(2):" << endl;
          cin >> t1;
          TDynamicVector<int> v(na);

          if (t1 == 1)
          {
              cout << "Введите вектгор v:" << endl;
              cin >> v;
          }
          else if (t1 == 2)
          {
              randomFillingTDynamicVector(v);
          }
          else throw exception("incorrect input");
          cout << "Введённый вектор: " << endl;
          cout << v << endl;
          cout << A * v << endl;
      }
  }
  else throw exception("incorrect input");
  return;
}
//---------------------------------------------------------------------------