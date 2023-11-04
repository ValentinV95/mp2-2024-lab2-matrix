// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

int main()
{
    int n = 9;
    while (1)
    {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "0 - A + B (matrixs)" << std::endl;
        std::cout << "1 - A - B (matrixs)" << std::endl;
        std::cout << "2 - A * B (matrixs)" << std::endl;
        std::cout << "3 - alpha * A (scalar, matrix)" << std::endl;
        std::cout << "4 - a + b (vectors)" << std::endl;
        std::cout << "5 - a - b (vectors)" << std::endl;
        std::cout << "6 - (a, b) (dot product)" << std::endl;
        std::cout << "7 - alpha * a (scalar, vector)" << std::endl;
        std::cout << "8 - A * b (matrix, vector)" << std::endl;
        std::cout << "9 - exit" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cin >> n;

        switch (n)
        {
        case(0)://A+B
        {
            try {
                size_t m = 0, k = 0;

                std::cout << "A size" << std::endl;
                std::cin >> m;

                TDynamicMatrix<double> A(m);

                std::cout << "A elements" << std::endl;
                std::cin >> A;


                std::cout << "B size" << std::endl;
                std::cin >> k;

                TDynamicMatrix<double> B(k);

                std::cout << "B elements" << std::endl;
                std::cin >> B;

                std::cout << "A + B = ..." << std::endl;
                std::cout << A + B << std::endl;
            }
            catch (std::exception& e) { std::cout << "error: " << e.what() << std::endl; break; }

            break;
        }
        case(1): //A-B
        {
            try {
                size_t m = 0, k = 0;

                std::cout << "A size" << std::endl;
                std::cin >> m;

                TDynamicMatrix<double> A(m);

                std::cout << "A elements" << std::endl;
                std::cin >> A;


                std::cout << "B size" << std::endl;
                std::cin >> k;

                TDynamicMatrix<double> B(k);

                std::cout << "B elements" << std::endl;
                std::cin >> B;

                std::cout << "A - B = ..." << std::endl;
                std::cout << A - B << std::endl;
            }
            catch (std::exception& e) { std::cout << "error: " << e.what() << std::endl; break; }

            break;
        }
        case(2): //A*B
        {
            try {
                size_t m = 0, k = 0;

                std::cout << "A size" << std::endl;
                std::cin >> m;

                TDynamicMatrix<double> A(m);

                std::cout << "A elements" << std::endl;
                std::cin >> A;


                std::cout << "B size" << std::endl;
                std::cin >> k;

                TDynamicMatrix<double> B(k);

                std::cout << "B elements" << std::endl;
                std::cin >> B;

                std::cout << "A * B = ..." << std::endl;
                std::cout << A * B << std::endl;
            }
            catch (std::exception& e) { std::cout << "error: " << e.what() << std::endl; break; }

            break;
        }
        case(3): //alpha * A
        {
            try {
                size_t m = 0;
                double alpha = 0;

                std::cout << "alpha" << std::endl;
                std::cin >> alpha;

                std::cout << "A size" << std::endl;
                std::cin >> m;

                TDynamicMatrix<double> A(m);

                std::cout << "A elements" << std::endl;
                std::cin >> A;

                std::cout << "alpha * A = ..." << std::endl;
                std::cout << A * alpha << std::endl;
            }
            catch (std::exception& e) { std::cout << "error: " << e.what() << std::endl; break; }

            break;
        }
        case(4): //a + b
        {
            try {
                size_t m = 0, k = 0;

                std::cout << "a size" << std::endl;
                std::cin >> m;

                TDynamicVector<double> a(m);

                std::cout << "a elements" << std::endl;
                std::cin >> a;


                std::cout << "b size" << std::endl;
                std::cin >> k;

                TDynamicVector<double> b(k);

                std::cout << "b elements" << std::endl;
                std::cin >> b;

                std::cout << "a + b = ..." << std::endl;
                std::cout << a + b << std::endl;
            }
            catch (std::exception& e) { std::cout << "error: " << e.what() << std::endl; break; }

            break;
        }
        case(5): //a - b
        {
            try {
                size_t m = 0, k = 0;

                std::cout << "a size" << std::endl;
                std::cin >> m;

                TDynamicVector<double> a(m);

                std::cout << "a elements" << std::endl;
                std::cin >> a;


                std::cout << "b size" << std::endl;
                std::cin >> k;

                TDynamicVector<double> b(k);

                std::cout << "b elements" << std::endl;
                std::cin >> b;

                std::cout << "a - b = ..." << std::endl;
                std::cout << a - b << std::endl;
            }
            catch (std::exception& e) { std::cout << "error: " << e.what() << std::endl; break; }

            break;
        }
        case(6): //(a,b)
        {
            try {
                size_t m = 0, k = 0;

                std::cout << "a size" << std::endl;
                std::cin >> m;

                TDynamicVector<double> a(m);

                std::cout << "a elements" << std::endl;
                std::cin >> a;


                std::cout << "b size" << std::endl;
                std::cin >> k;

                TDynamicVector<double> b(k);

                std::cout << "b elements" << std::endl;
                std::cin >> b;

                std::cout << "(a,b) = ..." << std::endl;
                std::cout << a * b << std::endl;
            }
            catch (std::exception& e) { std::cout << "error: " << e.what() << std::endl; break; }

            break;
        }
        case(7): //alpha * a
        {
            try {
                size_t m = 0;
                double alpha = 0;

                std::cout << "aplha" << std::endl;
                std::cin >> alpha;

                std::cout << "a size" << std::endl;
                std::cin >> m;

                TDynamicVector<double> a(m);

                std::cout << "a elements" << std::endl;
                std::cin >> a;

                std::cout << "alpha * a = ..." << std::endl;
                std::cout << a * alpha << std::endl;
            }
            catch (std::exception& e) { std::cout << "error: " << e.what() << std::endl; break; }

            break;
        }
        case(8): //A*b
            try {
                size_t m = 0, k = 0;

                std::cout << "A size" << std::endl;
                std::cin >> m;

                TDynamicMatrix<double> A(m);

                std::cout << "a elements" << std::endl;
                std::cin >> A;


                std::cout << "b size" << std::endl;
                std::cin >> k;

                TDynamicVector<double> b(k);

                std::cout << "b elements" << std::endl;
                std::cin >> b;

                std::cout << "A * b = ..." << std::endl;
                std::cout << A * b << std::endl;
            }
            catch (std::exception& e) { std::cout << "error: " << e.what() << std::endl; break; }

            break;
        case(9): exit(0);
        }

    }
    return 0;
}
//---------------------------------------------------------------------------
