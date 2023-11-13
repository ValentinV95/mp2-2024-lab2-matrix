// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
using namespace std;


int main()
{
    int n = 10;
    while (1)
    {
        cout << "1 - M * scalar" << endl;
        cout << "2 - M * V" << endl;
        cout << "3 - M1 + M2" << endl;
        cout << "4 - M1 - M2" << endl;
        cout << "5 - M1 * M2" << endl;
        cout << "0 - exit" << endl;

        cin >> n;

        switch (n)
        {
            case(1): //M * scalar
            {
                try{
                    size_t s;
                    double scalar;

                    cout << "Enter size M:" << endl;
                    cin >> s;
                    TDynamicMatrix<double> M(s);

                    cout << "Fill M:" << endl;
                    cin >> M;

                    cout << "Enter scalar:" << endl;
                    cin >> scalar;

                    cout << "Answer:" << endl;
                    cout << (M * scalar) << endl;
                    cout << "_________" << endl;
                }
                catch (exception& e) {
                    cout << "error: " << e.what() << endl;
                    break;
                }
                break;
            }

            case(2): //M*V
            {
                try {
                    size_t s1, s2;

                    cout << "Enter size V" << endl;
                    cin >> s1;
                    TDynamicVector<double> V(s1);

                    cout << "Fill V:" << endl;
                    cin >> V;


                    cout << "Enter size M" << endl;
                    cin >>s2 ;
                    TDynamicMatrix<double> M(s2);

                    cout << "Fill M:" << endl;
                    cin >> M;

                    cout << "Answer:" << endl;
                    cout << M*V << endl;
                    cout << "_________" << endl;
                }
                catch (exception& e) {
                    cout << "error: " << e.what() << endl;
                    break;
                }
                break;
            }

            case(3): //M1 + M2
            {
                try {
                    size_t s1, s2;

                    cout << "Enter size M1" << endl;
                    cin >> s1;
                    TDynamicMatrix<double> M1(s1);

                    cout << "Fill M1:" << endl;
                    cin >> M1;


                    cout << "Enter size M2" << endl;
                    cin >>s2 ;
                    TDynamicMatrix<double> M2(s2);

                    cout << "Fill M2:" << endl;
                    cin >> M2;

                    cout << "Answer:" << endl;
                    cout << M1+M2 << endl;
                    cout << "_________" << endl;
                }
                catch (exception& e) {
                    cout << "error: " << e.what() << endl;
                    break;
                }
                break;
            }

            case(4): //M1 - M2
            {
                try {
                    size_t s1, s2;

                    cout << "Enter size M1" << endl;
                    cin >> s1;
                    TDynamicMatrix<double> M1(s1);

                    cout << "Fill M1:" << endl;
                    cin >> M1;


                    cout << "Enter size M2" << endl;
                    cin >>s2 ;
                    TDynamicMatrix<double> M2(s2);

                    cout << "Fill M2:" << endl;
                    cin >> M2;

                    cout << "Answer:" << endl;
                    cout << M1-M2 << endl;
                    cout << "_________" << endl;
                }
                catch (exception& e) {
                    cout << "error: " << e.what() << endl;
                    break;
                }
                break;
            }

            case(5): //M1*M2
            {
                try {
                    size_t s1, s2;

                    cout << "Enter size M1" << endl;
                    cin >> s1;
                    TDynamicMatrix<double> M1(s1);

                    cout << "Fill M1:" << endl;
                    cin >> M1;


                    cout << "Enter size M2" << endl;
                    cin >>s2 ;
                    TDynamicMatrix<double> M2(s2);

                    cout << "Fill M2:" << endl;
                    cin >> M2;

                    cout << "Answer:" << endl;
                    cout << M1*M2 << endl;
                    cout << "_________" << endl;
                }
                catch (exception& e) {
                    cout << "error: " << e.what() << endl;
                    break;
                }
                break;
            }

            case(0): exit(0);
        }

    }
}
