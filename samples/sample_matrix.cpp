// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"

template <class T>
void rand_vector(TDynamicVector<T>& vec);

template <class T>
void rand_matrix(TDynamicMatrix<T>& mat, size_t size_matrix);

template <class T>
void create_vector(TDynamicVector<T>& v, size_t size_vector);

template <class T>
void create_matrix(TDynamicMatrix<T>& mat, size_t size_matrix);



int main() {
    int choice;
    size_t size_vector_a, size_vector_b, size_matrix_A, size_matrix_B;
    TDynamicVector<double> vector_a, vector_b;
    TDynamicMatrix<double> matrix_A, matrix_B;
    double alpha;   
    while(1)
    {
        cout << "/----------------------------------------------------------------/" << endl;
        cout << " MENU:" << endl;
        cout << " 0 -- a+b vector operation" << endl;
        cout << " 1 -- a-b vector operation" << endl;
        cout << " 2 -- a*b vector operation (a,b)" << endl;
        cout << " 3 -- a+alpha vector-scalar operation" << endl;
        cout << " 4 -- a-alpha vector-scalar operation" << endl;
        cout << " 5 -- a*alpha vector-scalar operation" << endl;
        cout << " 6 -- A*alpha matrix-scalar operation" << endl;
        cout << " 7 -- A*b matrix-vector operation" << endl;
        cout << " 8 -- A+B matrix-matrix operation" << endl;
        cout << " 9 -- A-B matrix-matrix operation" << endl;
        cout << " 10 -- A*B matrix-matrix operation" << endl;
        cout << " 11 -- END " << endl;
        cout << " Operation selection: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 0: {
            try
            {
                cout << " Enter size a: ";
                cin >> size_vector_a;
                create_vector(vector_a, size_vector_a);
                cout << " Enter size b: ";
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
                cout << " Enter size a: ";
                cin >> size_vector_a;
                create_vector(vector_a, size_vector_a);
                cout << " Enter size b: ";
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
                cout << " Enter size a: ";
                cin >> size_vector_a;
                create_vector(vector_a, size_vector_a);
                cout << " Enter size b: ";
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
                cout << " Enter size a: ";
                cin >> size_vector_a;
                create_vector(vector_a, size_vector_a);
                cout << " Enter alpha: ";
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
                cout << " Enter size a: ";
                cin >> size_vector_a;
                create_vector(vector_a, size_vector_a);
                cout << " Enter alpha: ";
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
                cout << " Enter size a: ";
                cin >> size_vector_a;
                create_vector(vector_a, size_vector_a);
                cout << " Enter alpha: ";
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
                cout << " Enter size A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Enter alpha: ";
                cin >> alpha;
                cout << " A*alpha=" << endl << matrix_A * alpha << endl;
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
                cout << " Enter size A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Enter size b: ";
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
                cout << " Enter size A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Enter size B: ";
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
                cout << " Enter size A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Enter size B: ";
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
                cout << " Enter size A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Enter size B: ";
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
            cout << "Program completed!" << endl;
            return 0;
        }
        default: {
            cout << endl << "Incorrect choice!" << endl << endl;
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
    cout << " 1 -- Random filling" << endl;
    cout << " 2 -- Manual filling" << endl;
    cout << " Choice: ";
    cin >> choice_rand;
    cout << endl;
    if (choice_rand == 1) {
        rand_vector(vec);
        cout << " vec=" << endl << vec << endl;
    }
    else {
        cout << " Vector filling" << endl;
        cin >> vec;
        cout << " vec=" << endl << vec << endl;
    }
    v = vec;
}

template <class T>
void create_matrix(TDynamicMatrix<T>& mat, size_t size_matrix) {
    TDynamicMatrix<T> mt(size_matrix);
    int choice_rand;
    cout << " 1 -- Random filling" << endl;
    cout << " 2 -- Manual filling" << endl;
    cout << " Choice: ";
    cin >> choice_rand;
    cout << endl;
    if (choice_rand == 1) {
        rand_matrix(mt, size_matrix);
        cout << " matr=" << endl << mt << endl;
    }
    else {
        cout << " Matrix filling" << endl;
        cin >> mt;
        cout << " matr=" << endl << mt << endl;
    }
    mat = mt;
}