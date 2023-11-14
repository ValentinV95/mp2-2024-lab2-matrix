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
void create_matrix(TDynamicMatrix<T>& mat, size_t size_matrix);

int main() {
    int choice;
    size_t size_vector, size_matrix_A, size_matrix_B;    
    TDynamicMatrix<double> matrix_A, matrix_B;
    double alpha;   
    while(1)
    {
        cout << "/----------------------------------------------------------------/" << endl;
        cout << " MENU:" << endl;       
        cout << " 0 -- A*alpha" << endl;
        cout << " 1 -- A*b" << endl;
        cout << " 2 -- A+B" << endl;
        cout << " 3 -- A-B" << endl;
        cout << " 4 -- A*B" << endl;
        cout << " 5 -- END" << endl;
        cout << " Operation selection: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {        
        case 0: {
            try {
                cout << " Enter size A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Enter alpha: ";
                cin >> alpha;
                cout << " A*alpha=" << endl << matrix_A * alpha << endl;
            }
            catch (const std::exception& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 1: {
            try {
                cout << " Enter size A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Enter size b: ";
                cin >> size_vector;
                TDynamicVector<double> vec(size_vector);
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
                cout << " A*b=" << endl << matrix_A * vec << endl;
            }
            catch (const std::exception& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 2: {
            try {
                cout << " Enter size A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Enter size B: ";
                cin >> size_matrix_B;
                create_matrix(matrix_B, size_matrix_B);
                cout << " A+B=" << endl << matrix_A + matrix_B << endl;
            }
            catch (const std::exception& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 3: {
            try {
                cout << " Enter size A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Enter size B: ";
                cin >> size_matrix_B;
                create_matrix(matrix_B, size_matrix_B);
                cout << " A-B=" << endl << matrix_A - matrix_B << endl;
            }
            catch (const std::exception& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            try {
                cout << " Enter size A: ";
                cin >> size_matrix_A;
                create_matrix(matrix_A, size_matrix_A);
                cout << " Enter size B: ";
                cin >> size_matrix_B;
                create_matrix(matrix_B, size_matrix_B);
                cout << " A*B=" << endl << matrix_A * matrix_B << endl;
            }
            catch (const std::exception& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 5: {
            cout << "/----------------------------------------------------------------/" << endl << endl << "Program completed!" << endl;
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