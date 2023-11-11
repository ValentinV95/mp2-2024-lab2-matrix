// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector {
protected:
    size_t sz;
    T *pMem;
public:
    TDynamicVector(size_t size = 1) : sz(size) //конструктор по умолчанию
    {
        if (sz <= 0 || sz > MAX_VECTOR_SIZE)
            throw out_of_range("Vector size should be greater than zero and less than MAX_VECTOR_SIZE");
        pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
    }

    TDynamicVector(T *arr, size_t s) : sz(s)  //конструктор-инициализатор
    {
        assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
        pMem = new T[sz];
        std::copy(arr, arr + sz, pMem);
    }

    TDynamicVector(const TDynamicVector &v) //конструктор копирования
    {
        sz = v.sz;
        pMem = new T[sz];
        std::copy(v.pMem, v.pMem + sz, pMem);
    }

    TDynamicVector(TDynamicVector &&v) noexcept  //конструктор перемещения
    {
        sz = v.sz;
        pMem = nullptr;
        pMem = v.pMem;
    }

    ~TDynamicVector() {
        delete[]pMem;
        sz = 0;
    }

    TDynamicVector &operator=(const TDynamicVector &v)  //оператор присваивания
    {
        if (this == &v)
            return *this;
        if (sz != v.sz) {
            sz = v.sz;
            T* p = new T[v.sz];
            delete[] pMem;
            pMem = p;
        }
        std::copy(v.pMem, v.pMem + sz, pMem);
        return *this;
    }

    TDynamicVector &operator=(TDynamicVector &&v) noexcept  //оператор присваивания перемещения
    {
        swap(*this, v);
        return *this;
    }

    size_t size() const noexcept { return sz; }  //вернуть размер

    // индексация
    T &operator[](size_t ind) //получить элемент по индексу
    {
        return pMem[ind];
    }

    const T &operator[](size_t ind) const //получить константный элемент по ндексу
    {
        return pMem[ind];
    }

    // индексация с контролем
    T &at(size_t ind) {
        if (ind >= sz) { throw out_of_range("index can't be less than 0 or greater than vector siz"); }
        return pMem[ind];
    }

    const T &at(size_t ind) const {
        if (ind >= sz) { throw out_of_range("index can't be less than 0 or greater than vector size"); }
        return pMem[ind];
    }

    // сравнение
    bool operator==(const TDynamicVector &v) const noexcept {
        if (sz != v.size()) { return false; }
        for (int i = 0; i < sz; i++) {
            if (pMem[i] != v[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const TDynamicVector &v) const noexcept {
        return !(*this == v);
    }

    // скалярные операции
    TDynamicVector operator+(T val) {
        TDynamicVector<T> res(sz);
        for (int i = 0; i < res.size(); i++) {
            res[i] = pMem[i] + val;
        }
        return res;
    }

    TDynamicVector operator-(T val) {
        TDynamicVector<T> res(sz);
        for (int i = 0; i < res.size(); i++) {
            res[i] = pMem[i] - val;
        }
        return res;
    }

    TDynamicVector operator*(T val) {
        TDynamicVector<T> res(sz);
        for (int i = 0; i < res.size(); i++) {
            res[i] = pMem[i] * val;
        }
        return res;
    }

    // векторные операции
    TDynamicVector operator+(const TDynamicVector &v) {
        if (sz != v.size()) { throw invalid_argument("Sizes must match"); }
        TDynamicVector<T> res(sz);
        for (int i = 0; i < sz; i++) {
            res[i] = pMem[i] + v[i];
        }
        return res;
    }

    TDynamicVector operator-(const TDynamicVector &v) {
        if (sz != v.size()) { throw invalid_argument("Sizes must match"); }
        TDynamicVector<T> res(sz);
        for (int i = 0; i < sz; i++) {
            res[i] = pMem[i] - v[i];
        }
        return res;
    }

    T operator*(const TDynamicVector &v) //noexcept(noexcept(T()))
    {
        if (sz != v.size()) { throw invalid_argument("Sizes must match"); }
        T res = 0;
        for (int i = 0; i < sz; i++) {
            res += v[i] * pMem[i];
        }
        return res;
    }

    friend void swap(TDynamicVector &lhs, TDynamicVector &rhs) noexcept {
        std::swap(lhs.sz, rhs.sz);
        std::swap(lhs.pMem, rhs.pMem);
    }

    // ввод/вывод
    friend istream &operator>>(istream &istr, TDynamicVector &v) {
        for (size_t i = 0; i < v.sz; i++)
            istr >> v.pMem[i]; // требуется оператор>> для типа T
        return istr;
    }

    friend ostream &operator<<(ostream &ostr, const TDynamicVector &v) {
        for (size_t i = 0; i < v.sz; i++)
            ostr << v.pMem[i] << " "; // требуется оператор<< для типа T
        return ostr;
    }
};


// Динамическая матрица -
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T> > {
    using TDynamicVector<TDynamicVector<T> >::pMem;
    using TDynamicVector<TDynamicVector<T> >::sz;
public:
    TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T> >(s) {
        if (s <= 0 || s > MAX_MATRIX_SIZE)
            throw out_of_range("Matrix size should be greater than zero and less than MAX_MATRIX_SIZE");
        for (size_t i = 0; i < sz; i++) {
            pMem[i] = TDynamicVector<T>(sz);
            for (int j = 0; j < sz; j++) {
                pMem[i][j] = 0;
            }
        }
    }

    using TDynamicVector<TDynamicVector<T>>::operator[];

    size_t size() const noexcept { return sz; }  //вернуть размер

    T &at(size_t ind, size_t ind2) {
        if (ind >= sz, ind2>=sz) { throw out_of_range("index can't be less than 0 or greater than vector siz"); }
        return pMem[ind][ind2];
    }

    const T &at(size_t ind, size_t ind2) const {
        if (ind >= sz, ind2>=sz) { throw out_of_range("index can't be less than 0 or greater than vector siz"); }
        return pMem[ind][ind2];
    }

    // сравнение
    bool operator==(const TDynamicMatrix &m) const noexcept {
        if (m.sz != sz) {
            return false;
        }
        for (int i = 0; i < sz; i++) {
            if (m[i] != pMem[i]) {
                return false;
            }
        }
        return true;
    }

    // матрично-скалярные операции
    TDynamicMatrix<T> operator*(const T &val) {
        TDynamicMatrix<T> res(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                res[i][j] = val * this[i][j];
            }
        }
        return res;
    }

    // матрично-векторные операции
    TDynamicMatrix<T> operator*(const TDynamicVector<T> &v) {
        if (sz != v.size()) { throw invalid_argument("Sizes must match"); }
        TDynamicMatrix<T> res(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                res[i][j] += v[i] * this[i][j]; //проверить на бумажке!!!!
            }
        }
        return res;
    }

    // матрично-матричные операции
    TDynamicMatrix operator+(const TDynamicMatrix &m) {
        if (sz != m.size()) { throw invalid_argument("Sizes must match"); }
        TDynamicMatrix<T> res(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; i < sz; i++) {
                res[i][j] = pMem[i][j] + m[i][j];
            }
        }
        return res;
    }

    TDynamicMatrix operator-(const TDynamicMatrix &m) {
        if (sz != m.size()) { throw invalid_argument("Sizes must match"); }
        TDynamicMatrix<T> res(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; i < sz; i++) {
                res[i][j] = pMem[i][j] + m[i][j];
            }
        }
        return res;
    }

    TDynamicMatrix operator*(const TDynamicMatrix &m) {
        if (sz != m.size()) { throw invalid_argument("Sizes must match"); }
        TDynamicMatrix<T> res(sz);
        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                for (int j = 0; j < sz; j++) {
                    res[i][j] = pMem[i][k] + m[k][j];
                }
            }
        }
        return res;
    }

    // ввод/вывод
    friend istream &operator>>(istream &istr, TDynamicMatrix &v) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                istr >> v[i][j];
            }
        }
        return istr;
    }

    friend ostream &operator<<(ostream &ostr, const TDynamicMatrix &v) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                ostr << v[i][j] << " ";
            }
            ostr << "\n";
        }
        return ostr;
    }
};

#endif
