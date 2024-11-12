// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
using std::swap;
using std::copy;
using std::equal;
using std::exception;
using std::length_error;
using std::out_of_range;
using std::runtime_error;
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
    TDynamicVector(const TDynamicVector& v)
    {
        sz = v.sz;
        pMem = new T[sz];
        copy(v.pMem, v.pMem + sz, pMem);
    }
    TDynamicVector(TDynamicVector&& v) noexcept
    {
        pMem = nullptr;
        swap(*this, v);
    }
    ~TDynamicVector()
    {
        delete[] pMem;
        pMem = 0;
    }
    TDynamicVector& operator=(const TDynamicVector& v)
    {
        if (this != &v)
        {
            if (sz != v.sz)
            {
                sz = v.sz;
                T* tmp = new T[sz];
                delete[] pMem;
                pMem = tmp;
            }
            copy(v.pMem, v.pMem + sz, pMem);
        }
        return *this;
    }
    TDynamicVector& operator=(TDynamicVector&& v) noexcept
    {
        pMem = nullptr;
        swap(*this, v);
        return *this;
    }
    
    size_t size() const noexcept { return sz; }

    // индексация
    T& operator[](size_t ind)
    {
        return pMem[ind];
    }
    const T& operator[](size_t ind) const
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
    bool operator==(const TDynamicVector& v) const noexcept
    {
        return (sz == v.sz && equal(pMem, pMem + sz, v.pMem));
    }
    bool operator!=(const TDynamicVector& v) const noexcept
    {
        return !(*this == v);
    }
    
    //унарная операция
    TDynamicVector operator-()
    {
        TDynamicVector Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = -pMem[i];
        return Res;
    }

    // скалярные операции
    TDynamicVector operator+(T val)
    {
        TDynamicVector Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] + val;
        return Res;
    }
    TDynamicVector operator-(T val)
    {
        TDynamicVector Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] - val;
        return Res;
    }
    TDynamicVector operator*(T val)
    {
        TDynamicVector Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] * val;
        return Res;
    }
    TDynamicVector operator/(T val)
    {
        TDynamicVector Res(sz);
        if (val == 0) 
            throw runtime_error("Division by zero. TDV operator /T");
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] / val;
        return Res;
    }
    TDynamicVector& operator+=(T val) noexcept
    {
        for (size_t i = 0; i < sz; i++)
            pMem[i] += val;
        return *this;
    }
    TDynamicVector& operator-=(T val) noexcept
    {
        for (size_t i = 0; i < sz; i++)
            pMem[i] -= val;
        return *this;
    }
    TDynamicVector& operator*=(T val) noexcept
    {
        for (size_t i = 0; i < sz; i++)
            pMem[i] *= val;
        return *this;
    }
    TDynamicVector& operator/=(T val)
    {
        if (T == 0)
            throw runtime_error("Division by zero. TDV operator /=T");
        for (size_t i = 0; i < sz; i++)
            pMem[i] /= val;
        return *this;
    }


    // векторные операции
    TDynamicVector operator+(const TDynamicVector& v)
    {
        if (sz != v.sz)
            throw exception("Can not operate with vectors of different size. Operator +");
        TDynamicVector Res(sz)
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] + v.pMem[i];
        return Res;
    }
    TDynamicVector operator-(const TDynamicVector& v)
    {
        if (sz != v.sz)
            throw exception("Can not operate with TDV of different size. Operator -");
        TDynamicVector Res(sz)
            for (size_t i = 0; i < sz; i++)
                Res.pMem[i] = pMem[i] - v.pMem[i];
        return Res;
    }
    T operator*(const TDynamicVector& v)
    {
        if (sz != v.sz)
            throw exception("Can not operate with TDV of different size. Operator *");
        T Res = static_cast<T>(0);
        for (size_t i = 0; i < sz; i++)
                Res += pMem[i] * v.pMem[i];
        return Res;

    }
    TDynamicVector operator+=(const TDynamicVector& v)
    {
        if (sz != v.sz)
            throw exception("Can not operate with TDV of different size. Operator +=");
        for (size_t i = 0; i < sz; i++)
            pMem[i] += v.pMem[i];
        return *this;
    }
    TDynamicVector operator-=(const TDynamicVector& v)
    {
        if (sz != v.sz)
            throw exception("Can not operate with TDV of different size. Operator -=");
        for (size_t i = 0; i < sz; i++)
            pMem[i] -= v.pMem[i];
        return *this;
    }

    friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
    {
        swap(lhs.sz, rhs.sz);
        swap(lhs.pMem, rhs.pMem);
        return;
    }

    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicVector& v)
    {
        for (size_t i = 0; i < v.sz; i++)
        istr >> v.pMem[i]; // требуется оператор>> для типа T
        return istr;
    }
    friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
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
    /*TDynamicMatrix(TDynamicVector<T>* arr, size_t s) : TDynamicVector<TDynamicVector<T>>(s)
    {
        if (sz > MAX_MATRIX_SIZE)
            throw length_error("Matrix size is too big");
        for (size_t i = 0; i < sz; i++)
            pMem[i] = arr[i];
    }*/
    TDynamicMatrix(const TDynamicMatrix& m) : TDynamicVector<TDynamicVector<T>>(m.sz)
    {
        for (size_i = 0; i < sz; i++)
            pMem[i] = m.pMem[i];
    }
    TDynamicMatrix(const TDynamicMatrix&& m)
    {
        pMem = 0;
        swap(*this, M);
    }
    ~TDynamicMatrix()
    {
        delete[] pMem;
        pMem = 0;
    }
    TDynamicMatrix& operator=(const TDynamicMatrix& m)
    {
        return TDynamicVector<TDynamicVector<T>>::operator=(m);
    }
    TDynamicMatrix& operator=(TDynamicMatrix&& m)
    {
        return TDynamicVector<TDynamicVector<T>>::operator=(m);
    }

    friend void swap(TDynamicMatrix& lhs, TDynamicMatrix& rhs) noexcept
    {
        swap(lhs.sz, rhs.sz);
        swap(lhs.pMem, rhs.pMem);
        return;
    }

    using TDynamicVector<TDynamicVector<T>>::operator[];

    // сравнение
    bool operator==(const TDynamicMatrix& m) const noexcept
    {
      //return TDynamicVector<TDynamicVector<T>>::operator==(m);
        int k = 1, i = 0;
        while (i < sz && k)
            if (pMem[i] != m.pMem[i])
                k = 0;
        return k;
    }
    bool operator!=(const TDynamicMatrix& m) const noexcept
    {
        return !(*this == m);
    }

    // матрично-скалярные операции
    TDynamicMatrix<T> operator*(const T& val)
    {
        TDynamicMatrix Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] * val;
        return Res;
    }
    TDynamicMatrix<T> operator/(const T& val)
    {
        if (val == 0)
            throw runtime_error("Division by zero. TDM operator /T");
        TDynamicMatrix Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res.pMem[i] = pMem[i] * val;
        return Res;
    }
    TDynamicMatrix<T>& operator*=(const T& val) noexcept
    {
        for (size_t i = 0; i < sz; i++)
            pMem[i] *= val;
        return Res;
    }
    TDynamicMatrix<T>& operator/=(const T& val)
    {
        if (val == 0)
            throw runtime_error("Division by zero. TDM operator /=T");
        for (size_t i = 0; i < sz; i++)
            pMem[i] /= val;
        return Res;
    }


    // матрично-векторные операции
    TDynamicVector<T> operator*(const TDynamicVector<T>& v)
    {
        if(sz != v.sz)
            throw exception("Can not operate with matrix and vector of different size. Operator mat*vec");
        TDynamicVector<T> Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res[i] = pMem[i] * v;
        return Res;
    }

    // матрично-матричные операции
    TDynamicMatrix operator+(const TDynamicMatrix& m)
    {
        if (sz != m.sz)
            throw exception("Can not operate with matrixes of different size. Operator +");
        TDynamicMatrix Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res[i] = pMem[i] + m.pMem[i];
        return Res;
    }
    TDynamicMatrix operator-(const TDynamicMatrix& m)
    {
        if (sz != m.sz)
            throw exception("Can not operate with matrixes of different size. Operator -");
        TDynamicMatrix Res(sz);
        for (size_t i = 0; i < sz; i++)
            Res[i] = pMem[i] - m.pMem[i];
        return Res;
    }
    TDynamicMatrix operator*(const TDynamicMatrix& m)
    {
        if (sz != m.sz)
            throw exception("Can not operate with matrixes of different size. Operator *");
        TDynamicMatrix Res(sz);
        for (size_t i = 0; i < sz; i++)                 // Результат умножения матриц есть матрица, где i-ая строка – это
        {                                               // линейная комбинация из строк второй матрицы с коэффициентами
            Res[i] = m.pMem[0] * pMem[i][0];            // из соответствующих столбцов i-ой строки первой матрицы
            for (size_t j = 1; j < sz; j++)
                Res[i] += m.pMem[j] * pMem[i][j];
        }
        return Res;
    }
    TDynamicMatrix& operator+=(const TDynamicMatrix& m)
    {
        if (sz != m.sz)
            throw exception("Can not operate with matrixes of different size. Operator +=");
        for (size_t i = 0; i < sz; i++)
            pMem[i] += m.pMem[i];
        return *this;
    }
    TDynamicMatrix& operator-=(const TDynamicMatrix& m)
    {
        if (sz != m.sz)
            throw exception("Can not operate with matrixes of different size. Operator -=");
        for (size_t i = 0; i < sz; i++)
            pMem[i] -= m.pMem[i];
        return *this;
    }
    TDynamicMatrix& operator*=(const TDynamicMatrix& m)
    {
        if (sz != m.sz)
            throw exception("Can not operate with matrixes of different size. Operator *=");
        TDynamicMatrix tmp(*this);
        for (size_t i = 0; i < sz; i++)
        {
            pMem[i] = m.pMem[0] * tmp[i][0];
            for (size_t j = 1; j < sz; j++)
                pMem[i] += m.pMem[j] * tmp[i][j];
        }
        return *this;
    }


    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicMatrix& m)
    {
        for (size_t i = 0; i < sz; i++)
            istr >> m.pMem[i];
        return istr;
    }
    friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& m)
    {
        for (size_t i = 0; i < sz; i++)
            ostr << m.pMem[i] << '\n';
        return ostr;

    }
};
template <typename T>
TDynamicVector<T> operator*(const TDynamicVector<T>& v, const TDynamicMatrix<T>& m)     //Умножение матрицы на вектор слева
{
    if (v.sz != m.sz)
        throw exception("Can not operate with matrix and vector of different size. Operator vec*mat");
    size_t sz = v.sz;
    TDynamicVector<T> Res(sz);
    Res[0] = m[0] * v[0];
    for (size_t i = 1; i < sz; i++)
        Res[i] += m[i] * v[i];
    return Res;
};
#endif
