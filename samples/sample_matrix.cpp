// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

void nmain()
{
  TDynamicMatrix<int> a(5), b(5), c(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование класс работы с матрицами"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
}
//---------------------------------------------------------------------------


template <class T>
void rand_vector(TDynamicVector<T>& vec);

template <class T>
void rand_matrix(TDynamicMatrix<T>& mat, size_t size_matrix);

template <class T>
void create_vector(TDynamicVector<T>& v, size_t size_vector);

template <class T>
void create_matrix(TDynamicMatrix<T>& mat, size_t size_matrix);



int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    size_t size_vector_a, size_vector_b, size_matrix_A, size_matrix_B;
    TDynamicVector<double> vector_a, vector_b;
    TDynamicMatrix<double> matrix_A, matrix_B;
    double alpha;
    
    while(1)
    {
        cout << "/----------------------------------------------------------------/" << endl;
        cout << " МЕНЮ:" << endl;
        cout << " 0 -- a+b векторная операция" << endl;
        cout << " 1 -- a-b векторная операция" << endl;
        cout << " 2 -- a*b векторная операция (a,b)" << endl;
        cout << " 3 -- a+alpha векторно-скалярня операция" << endl;
        cout << " 4 -- a-alpha векторно-скалярня операция" << endl;
        cout << " 5 -- a*alpha векторно-скалярня операция" << endl;
        cout << " 6 -- A*alpha матрично-скалярня операция" << endl;
        cout << " 7 -- A*b матрично-векторная операция" << endl;
        cout << " 8 -- A+B матрично-матричная операция" << endl;
        cout << " 9 -- A-B матрично-матричная операция" << endl;
        cout << " 10 -- A*B матрично-матричная операция" << endl;
        cout << " 11 -- END " << endl;
        cout << " Выбор операции: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 0: {
            try
            {
                cout << " Введите размер a: ";
                cin >> size_vector_a;
                create_vector(vector_a, size_vector_a);
                cout << " Введите размер b: ";
                cin >> size_vector_b;
                create_vector(vector_b, size_vector_b);
                cout << " a+b=" << endl << vector_a + vector_b << endl;
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }           
            break;
        }
        case 1: {
            try
            {
                cout << " Введите размер a: ";
                cin >> size_vector_a;
                create_vector(vector_a, size_vector_a);
                cout << " Введите размер b: ";
                cin >> size_vector_b;
                create_vector(vector_b, size_vector_b);
                cout << " a-b=" << endl << vector_a - vector_b << endl;
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 2: {
            try
            {
                cout << " Введите размер a: ";
                cin >> size_vector_a;
                create_vector(vector_a, size_vector_a);
                cout << " Введите размер b: ";
                cin >> size_vector_b;
                create_vector(vector_b, size_vector_b);
                cout << " a*b=" << endl << vector_a * vector_b << endl;
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 3: {
            try
            {
                cout << " Введите размер a: ";
                cin >> size_vector_a;
                create_vector(vector_a, size_vector_a);
                cout << " Введите alpha: ";
                cin >> alpha;
                cout << " a+alpha=" << endl << vector_a + alpha << endl;
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            try
            {
                cout << " Введите размер a: ";
                cin >> size_vector_a;
                create_vector(vector_a, size_vector_a);
                cout << " Введите alpha: ";
                cin >> alpha;
                cout << " a-alpha=" << endl << vector_a - alpha << endl;
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 5: {
            try
            {
                cout << " Введите размер a: ";
                cin >> size_vector_a;
                create_vector(vector_a, size_vector_a);
                cout << " Введите alpha: ";
                cin >> alpha;
                cout << " a*alpha=" << endl << vector_a * alpha << endl;
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 6: {
            try
            {
                cout << " Введите размер A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Введите alpha: ";
                cin >> alpha;
                cout << " a*alpha=" << endl << matrix_A * alpha << endl;
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 7: {
            try
            {
                cout << " Введите размер A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Введите размер b: ";
                cin >> size_vector_b;
                create_vector(vector_b, size_vector_b);
                cout << " A*b=" << endl << matrix_A * vector_b << endl;
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 8: {
            try
            {
                cout << " Введите размер A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Введите размер B: ";
                cin >> size_matrix_B;
                create_matrix(matrix_B, size_matrix_B);
                cout << " A+B=" << endl << matrix_A + matrix_B << endl;
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 9: {
            try
            {
                cout << " Введите размер A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Введите размер B: ";
                cin >> size_matrix_B;
                create_matrix(matrix_B, size_matrix_B);
                cout << " A-B=" << endl << matrix_A - matrix_B << endl;
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 10: {
            try
            {
                cout << " Введите размер A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Введите размер B: ";
                cin >> size_matrix_B;
                create_matrix(matrix_B, size_matrix_B);
                cout << " A*B=" << endl << matrix_A * matrix_B << endl;
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 11: {
            cout << "/----------------------------------------------------------------/" << endl<<endl;
            cout << "Программа завершена!" << endl;
            return 0;
        }
        default: {
            cout << endl << "Неправильный выбор!" << endl << endl;
            break;
        }
        }
    }
}




template <class T>
void rand_vector(TDynamicVector<T>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        vec[i] = ((T)rand()) / 100;
    }
}

template <class T>
void rand_matrix(TDynamicMatrix<T>& mat, size_t size_matrix) {
    for (size_t i = 0; i < size_matrix; i++) {
        for (size_t j = 0; j < size_matrix; j++) {
            mat[i][j] = ((T)rand()) / 100;
        }
    }
}
template <class T>
void create_vector(TDynamicVector<T>& v, size_t size_vector) {
    TDynamicVector<T> vec(size_vector);
    int choice_rand;
    cout << " 1 -- Рандомное заполнение" << endl;
    cout << " 2 -- Ручное заполнение" << endl;
    cout << " Выбор: ";
    cin >> choice_rand;
    cout << endl;
    if (choice_rand == 1) {
        rand_vector(vec);
        cout << " vec=" << endl << vec << endl;
    }
    else {
        cout << " Заполнение вектора" << endl;
        cin >> vec;
        cout << " a=" << endl << vec << endl;
    }
    v = vec;
}

template <class T>
void create_matrix(TDynamicMatrix<T>& mat, size_t size_matrix) {
    TDynamicMatrix<T> mt(size_matrix);
    int choice_rand;
    cout << " 1 -- Рандомное заполнение" << endl;
    cout << " 2 -- Ручное заполнение" << endl;
    cout << " Выбор: ";
    cin >> choice_rand;
    cout << endl;
    if (choice_rand == 1) {
        rand_matrix(mt, size_matrix);
        cout << " matr=" << endl << mt << endl;
    }
    else {
        cout << " Заполнение вектора" << endl;
        cin >> mt;
        cout << " matr=" << endl << mt << endl;
    }
    mat = mt;
}