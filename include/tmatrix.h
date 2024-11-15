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
class TDynamicVector
{
protected:
    size_t sz;
    T* pMem;
public:
    TDynamicVector(size_t size = 1) : sz(size)
    {
        if (sz == 0)
            throw length_error("Vector size should be greater than zero");
        if (sz > MAX_VECTOR_SIZE)
            throw length_error("Vector size is too big");
        pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
    }
    TDynamicVector(T* arr, size_t s) : sz(s)
    {
        if (!arr)
            throw exception("arr shall not be nullptr");
        if (sz == 0)
            throw length_error("Vector size should be greater than zero");
        if (sz > MAX_VECTOR_SIZE)
            throw length_error("Vector size is too big");
        pMem = new T[sz];
        copy(arr, arr + sz, pMem);
    }
    TDynamicVector(const TDynamicVector<T>& v)
    {
        sz = v.sz;
        pMem = new T[sz];
        copy(v.pMem, v.pMem + sz, pMem);
    }
    TDynamicVector(TDynamicVector<T>&& v) noexcept
    {
        pMem = nullptr;
        swap(*this, v);
    }
    ~TDynamicVector()
    {
        delete[] pMem;
        pMem = 0;
    }
    TDynamicVector<T>& operator=(const TDynamicVector<T>& v)
    {
        if (this != &v)
        {
            if (sz != v.sz)
            {
                T* tmp = new T[sz];
                sz = v.sz;
                delete[] pMem;
                pMem = tmp;
            }
            copy(v.pMem, v.pMem + sz, pMem);
        }
        return *this;
    }
    TDynamicVector<T>& operator=(TDynamicVector<T>&& v) noexcept
    {
        swap(*this, v);
        return *this;
    }
    
    size_t size() const noexcept { return sz; }

    // индексация
    T& operator[](size_t ind) noexcept
    {
        return pMem[ind];
    }
    const T& operator[](size_t ind) const noexcept
    {
        return pMem[ind];
    }
    // индексация с контролем
    T& at(size_t ind)
    {
        if (ind >= sz)
            throw out_of_range("TDV.at is out of range");
        return pMem[ind];
    }
    const T& at(size_t ind) const
    {
        if (ind >= sz)
            throw out_of_range("TDV.at is out of range");
        return pMem[ind];
    }

    // сравнение
    bool operator==(const TDynamicVector<T>& v) const noexcept
    {
        return (sz == v.sz && equal(pMem, pMem + sz, v.pMem));
    }
    bool operator!=(const TDynamicVector<T>& v) const noexcept
    {
        return !(*this == v);
    }
    
    //унарная операция
    TDynamicVector<T> operator-() const
    {
        TDynamicVector Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = -pMem[i];
        return Res;
    }

    // скалярные операции
    TDynamicVector<T> operator+(const T& val) const
    {
        TDynamicVector Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] + val;
        return Res;
    }
    TDynamicVector<T> operator-(const T& val) const
    {
        TDynamicVector Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] - val;
        return Res;
    }
    TDynamicVector<T> operator*(const T& val) const
    {
        TDynamicVector Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] * val;
        return Res;
    }
    TDynamicVector<T> operator/(const T& val) const    //My operator
    {
        TDynamicVector Res(sz);
        if (val == 0) 
            throw runtime_error("Vector division by zero is not allowed. Code = 1");
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] / val;
        return Res;
    }

    // скалярные присваивающие операции
    TDynamicVector<T>& operator+=(const T& val) noexcept
    {
        for (size_t i = 0; i < sz; i++)
            pMem[i] += val;
        return *this;
    }
    TDynamicVector<T>& operator-=(const T& val) noexcept
    {
        for (size_t i = 0; i < sz; i++)
            pMem[i] -= val;
        return *this;
    }
    TDynamicVector<T>& operator*=(const T& val) noexcept
    {
        for (size_t i = 0; i < sz; i++)
            pMem[i] *= val;
        return *this;
    }
    TDynamicVector<T>& operator/=(const T& val)
    {
        if (val == 0)
            throw runtime_error("Vector division by zero is not allowed. Code = 2");
        for (size_t i = 0; i < sz; i++)
            pMem[i] /= val;
        return *this;
    }

    // векторные операции
    TDynamicVector<T> operator+(const TDynamicVector<T>& v) const
    {
        if (sz != v.sz)
            throw exception("Can not operate with vectors of different size. Operator +");
        TDynamicVector Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] + v.pMem[i];
        return Res;
    }
    TDynamicVector<T> operator-(const TDynamicVector<T>& v) const
    {
        if (sz != v.sz)
            throw exception("Can not operate with TDV of different size. Operator -");
        TDynamicVector Res(sz);
            for (size_t i = 0; i < sz; i++)
                Res.pMem[i] = pMem[i] - v.pMem[i];
        return Res;
    }
    T operator*(const TDynamicVector<T>& v) const
    {
        if (sz != v.sz)
            throw exception("Can not operate with TDV of different size. Operator *");
        T Res = static_cast<T>(0);
        for (size_t i = 0; i < sz; i++)
                Res += pMem[i] * v.pMem[i];
        return Res;

    }

    // векторные присваивающие операции
    TDynamicVector<T> operator+=(const TDynamicVector<T>& v)
    {
        if (sz != v.sz)
            throw exception("Can not operate with TDV of different size. Operator +=");
        for (size_t i = 0; i < sz; i++)
            pMem[i] += v.pMem[i];
        return *this;
    }
    TDynamicVector<T> operator-=(const TDynamicVector<T>& v)
    {
        if (sz != v.sz)
            throw exception("Can not operate with TDV of different size. Operator -=");
        for (size_t i = 0; i < sz; i++)
            pMem[i] -= v.pMem[i];
        return *this;
    }

    // перестановка
    friend void swap(TDynamicVector<T>& lhs, TDynamicVector<T>& rhs) noexcept
    {
        swap(lhs.sz, rhs.sz);
        swap(lhs.pMem, rhs.pMem);
        return;
    }

    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicVector<T>& v)
    {
        for (size_t i = 0; i < v.sz; i++)
            istr >> v.pMem[i]; // требуется оператор>> для типа T
        return istr;
    }
    friend ostream& operator<<(ostream& ostr, const TDynamicVector<T>& v)
    {
        for (size_t i = 0; i < v.sz; i++)
        ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
        return ostr;
    }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template <typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
    using TDynamicVector<TDynamicVector<T>>::pMem;
    using TDynamicVector<TDynamicVector<T>>::sz;
public:
    TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
    {
        if (sz > MAX_MATRIX_SIZE)
            throw length_error("Matrix size is too big");
        for (size_t i = 0; i < sz; i++)
            pMem[i] = TDynamicVector<T>(sz);
    }

    friend void swap(TDynamicMatrix& lhs, TDynamicMatrix& rhs) noexcept
    {
        swap(lhs.sz, rhs.sz);
        swap(lhs.pMem, rhs.pMem);
        return;
    }

    using TDynamicVector<TDynamicVector<T>>::size;
    using TDynamicVector<TDynamicVector<T>>::operator[];
    using TDynamicVector<TDynamicVector<T>>::at;

    // сравнение
    bool operator==(const TDynamicMatrix<T>& m) const noexcept
    {
      return TDynamicVector<TDynamicVector<T>>::operator==(m);
    }
    bool operator!=(const TDynamicMatrix<T>& m) const noexcept
    {
        return !(*this == m);
    }

    //унарная операция
    TDynamicMatrix<T> operator-()
    {
        TDynamicMatrix<T> Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = -pMem[i];
        return Res;
    }

    // матрично-скалярные операции
    TDynamicMatrix<T> operator*(const T& val) const
    {
        TDynamicMatrix<T> Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] * val;
        return Res;
    }
    TDynamicMatrix<T> operator/(const T& val) const
    {
        if (val == 0)
            throw runtime_error("Matrix division by zero is not allowed. Code = 1");
        TDynamicMatrix Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] / val;
        return Res;
    }

    // матрично-скалярные присваивающие операции
    TDynamicMatrix<T>& operator*=(const T& val) noexcept
    {
        for (size_t i = 0; i < sz; i++)
            pMem[i] *= val;
        return *this;
    }
    TDynamicMatrix<T>& operator/=(const T& val)
    {
        if (val == 0)
            throw runtime_error("Matrix division by zero is not allowed. Code = 2");
        for (size_t i = 0; i < sz; i++)
            pMem[i] /= val;
        return *this;
    }

    // матрично-векторные операции
    TDynamicVector<T> operator*(const TDynamicVector<T>& v) const
    {
        if(sz != v.size())
            throw exception("Can not operate with matrix and vector of different size. Operator mat*vec");
        TDynamicVector<T> Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res[i] = pMem[i] * v;
        return Res;
    }

    // матрично-матричные операции
    TDynamicMatrix<T> operator+(const TDynamicMatrix<T>& m) const
    {
        if (sz != m.sz)
            throw exception("Can not operate with matrixes of different size. Operator +");
        TDynamicMatrix<T> Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res[i] = pMem[i] + m.pMem[i];
        return Res;
    }
    TDynamicMatrix<T> operator-(const TDynamicMatrix<T>& m) const
    {
        if (sz != m.sz)
            throw exception("Can not operate with matrixes of different size. Operator -");
        TDynamicMatrix<T> Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res[i] = pMem[i] - m.pMem[i];
        return Res;
    }
    TDynamicMatrix<T> operator*(const TDynamicMatrix<T>& m) const
    {
        if (sz != m.sz)
            throw exception("Can not operate with matrixes of different size. Operator *");
        TDynamicMatrix<T> Res(sz);
        for (size_t i = 0; i < sz; i++)                 // Результат умножения матриц есть матрица, где i-ая строка – это
        {                                               // линейная комбинация из строк второй матрицы с коэффициентами
            Res[i] = m.pMem[0] * pMem[i][0];            // из соответствующих столбцов i-ой строки первой матрицы
            for (size_t j = 1; j < sz; j++)
                Res[i] += m.pMem[j] * pMem[i][j];
        }
        return Res;
    }

    // матрично-матричные присваивающие операции
    TDynamicMatrix<T>& operator+=(const TDynamicMatrix<T>& m)
    {
        if (sz != m.sz)
            throw exception("Can not operate with matrixes of different size. Operator +=");
        for (size_t i = 0; i < sz; i++)
            pMem[i] += m.pMem[i];
        return *this;
    }
    TDynamicMatrix<T>& operator-=(const TDynamicMatrix<T>& m)
    {
        if (sz != m.sz)
            throw exception("Can not operate with matrixes of different size. Operator -=");
        for (size_t i = 0; i < sz; i++)
            pMem[i] -= m.pMem[i];
        return *this;
    }
    TDynamicMatrix<T>& operator*=(const TDynamicMatrix<T>& m)
    {
        if (sz != m.sz)
            throw exception("Can not operate with matrixes of different size. Operator *=");
        TDynamicMatrix<T> tmp(sz);
        for (size_t i = 0; i < sz; i++)
        {
            tmp[i] = m.pMem[0] * pMem[i][0];
            for (size_t j = 1; j < sz; j++)
                tmp[i] += m.pMem[j] * pMem[i][j];
        }
        swap(tmp, *this);
        return *this;
    }

    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicMatrix<T>& m)
    {
        for (size_t i = 0; i < m.sz; i++)
            istr >> m.pMem[i];
        return istr;
    }
    friend ostream& operator<<(ostream& ostr, const TDynamicMatrix<T>& m)
    {
        for (size_t i = 0; i < m.sz; i++)
            ostr << m.pMem[i] << '\n';
        return ostr;

    }
};
//Умножение матрицы на вектор слева
template <typename T>
TDynamicVector<T> operator*(const TDynamicVector<T>& v, const TDynamicMatrix<T>& m)
{
    if (v.size() != m.size())
        throw exception("Can not operate with matrix and vector of different size. Operator vec*mat");
    size_t sz = v.size();
    TDynamicVector<T> Res(sz);
    Res = m[0] * v[0];
    for (size_t i = 1; i < sz; i++)
        Res += m[i] * v[i];
    return Res;
};
#endif
