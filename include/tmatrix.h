// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include <assert.h>

using namespace std;

const size_t MAX_VECTOR_SIZE = 100000000;
const size_t MAX_MATRIX_SIZE = 10000;

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
        if (sz == 0 || sz > MAX_VECTOR_SIZE) throw out_of_range("sz should not be equal to zero or greater than MAX_VECTOR_SIZE");
        pMem = new T[sz]();
    }

    TDynamicVector(T* arr, size_t s) : sz(s)
    {
        if (sz == 0 || sz > MAX_VECTOR_SIZE) throw out_of_range("sz should not be equal to zero or greater than MAX_VECTOR_SIZE");
        assert(arr != nullptr && "TDynamicVector requires non-nullptr arg");
        pMem = new T[sz];
        copy(arr, arr + sz, pMem);
    }

    TDynamicVector(const TDynamicVector& v) : sz(v.sz)
    {
        pMem = new T[sz];
        copy(v.pMem, v.pMem + sz, pMem);
    }

    TDynamicVector(TDynamicVector&& v) noexcept
    {
        pMem = nullptr;
        sz = 0;
        swap(*this, v);
    }

    ~TDynamicVector()
    {
        delete[] pMem;
        sz = 0;
    }

    TDynamicVector& operator=(const TDynamicVector& v)
    {
        if (this == &v)
            return *this;

        TDynamicVector tmp(v);
        swap(*this, tmp);
        return *this;
    }

    TDynamicVector& operator=(TDynamicVector&& v) noexcept
    {
        pMem = nullptr;
        sz = 0;
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
        if (ind >= sz) throw std::out_of_range("ind is out of range");
        return pMem[ind];
    }

    const T& at(size_t ind) const
    {
        if (ind >= sz) throw std::out_of_range("ind is out of range");
        return pMem[ind];
    }
    
    // сравнение
    bool operator==(const TDynamicVector& v) const noexcept
    {
        if (sz != v.sz) return false;
        for (size_t i = 0; i < sz; i++)
            if (pMem[i] != v.pMem[i]) return false;
        return true;
    }

    bool operator!=(const TDynamicVector& v) const noexcept
    {
        return !(*this == v);
    }
    
    // скалярные операции
    TDynamicVector operator+(const T& val)
    {
        TDynamicVector res(*this);
        for (size_t i = 0; i < sz; i++)
            res.pMem[i] += val;
        return res;
    }

    TDynamicVector operator-(const T& val)
    {
        TDynamicVector res(*this);
        for (size_t i = 0; i < sz; i++)
            res.pMem[i] -= val;
        return res;
    }

    TDynamicVector operator*(const T& val)
    {
        TDynamicVector res(*this);
        for (size_t i = 0; i < sz; i++)
            res.pMem[i] *= val;
        return res;
    }
    
    // векторные операции
    TDynamicVector operator+(const TDynamicVector& v)
    {
        if (sz != v.sz) throw std::invalid_argument("Cannot add two vectors with different sizes");
        TDynamicVector res(*this);
        for (size_t i = 0; i < sz; i++)
            res.pMem[i] += v.pMem[i];
        return res;
    }

    TDynamicVector operator-(const TDynamicVector& v)
    {
        if (sz != v.sz) throw std::invalid_argument("Cannot subtract two vectors with different sizes");
        TDynamicVector res(*this);
        for (size_t i = 0; i < sz; i++)
            res.pMem[i] -= v.pMem[i];
        return res;
    }

    T operator*(const TDynamicVector& v)
    {
        if (sz != v.sz) throw std::invalid_argument("Cannot get dot product of two vectors with different sizes");
        T res = {};
        for (size_t i = 0; i < sz; i++)
            res += pMem[i] * v.pMem[i];
        return res;
    }
    
    friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
    {
        std::swap(lhs.sz, rhs.sz);
        std::swap(lhs.pMem, rhs.pMem);
    }
    
    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicVector& v)
    {
        for (size_t i = 0; i < v.sz; i++)
            if (!(istr >> v.pMem[i]))
                throw std::invalid_argument("Invalid input into vector.");

        return istr;
    }
    friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
    {
        for (size_t i = 0; i < v.sz; i++)
            ostr << v.pMem[i] << " ";
        return ostr;
    }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти

template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
    using TDynamicVector<TDynamicVector<T>>::pMem;
    using TDynamicVector<TDynamicVector<T>>::sz;
public:
    TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
    {
        if (s == 0 || s > MAX_MATRIX_SIZE) throw std::invalid_argument("sz should not be equal to zero or greater than MAX_MATRIX_SIZE");
        for (size_t i = 0; i < sz; i++)
            pMem[i] = TDynamicVector<T>(sz);
    }
    
    using TDynamicVector<TDynamicVector<T>>::operator[];
    using TDynamicVector<TDynamicVector<T>>::size;

    // индексация с контролем
    T& at(size_t r, size_t c)
    {
        if (r >= sz || c >= sz) throw std::out_of_range("row or column indices are out of range");
    }

    const T& at(size_t r, size_t c) const
    {
        if (r >= sz || c >= sz) throw std::out_of_range("row or column indices are out of range");
    }

    // сравнение
    bool operator==(const TDynamicMatrix& m) const noexcept
    {
        return TDynamicVector<TDynamicVector<T>>::operator==(m);
    }

    bool operator!=(const TDynamicMatrix& m) const noexcept
    {
        return TDynamicVector<TDynamicVector<T>>::operator!=(m);
    }
    
    // матрично-скалярные операции
    TDynamicMatrix<T> operator*(const T val)
    {
        TDynamicMatrix<T> tmp(*this);
        for (size_t i = 0; i < sz; i++)
            tmp.pMem[i] = pMem[i] * val;
        return tmp;
    }
    
    // матрично-векторные операции
    TDynamicVector<T> operator*(const TDynamicVector<T>& v)
    {
        if (sz != v.size()) throw std::invalid_argument("Cannot multiply matrix and vector with different sizes");
        TDynamicVector<T> tmp(sz);
        for (size_t i = 0; i < sz; i++)
            tmp[i] = pMem[i] * v;
        return tmp;
    }
    
    // матрично-матричные операции
    TDynamicMatrix operator+(const TDynamicMatrix& m)
    {
        if (sz != m.sz) throw std::invalid_argument("Cannot add two matrices with different sizes");
        TDynamicMatrix<T> tmp(*this);
        for (size_t i = 0; i < sz; i++)
            tmp.pMem[i] = pMem[i] + m.pMem[i];
        return tmp;
    }

    TDynamicMatrix operator-(const TDynamicMatrix& m)
    {
        if (sz != m.sz) throw std::invalid_argument("Cannot subtract two matrices with different sizes");
        TDynamicMatrix<T> tmp(*this);
        for (size_t i = 0; i < sz; i++)
            tmp.pMem[i] = pMem[i] - m.pMem[i];
        return tmp;
    }

    TDynamicMatrix operator*(const TDynamicMatrix& m)
    {
        if (sz != m.sz) throw std::invalid_argument("Cannot multiply two matrices with different sizes");
        TDynamicMatrix<T> tmp(m.sz);
        for (size_t i = 0; i < sz; i++)
            for (size_t k = 0; k < sz; k++)
                for (size_t j = 0; j < sz; j++)
                    tmp[i][j] += pMem[i][k] * m.pMem[k][j];

        return tmp;
    }

    friend void swap(TDynamicMatrix& lhs, TDynamicMatrix& rhs) noexcept
    {
        std::swap(lhs.sz, rhs.sz);
        std::swap(lhs.pMem, rhs.pMem);
    }
    
    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicMatrix& m)
    {
        for (size_t i = 0; i < m.sz; i++)
            for (size_t j = 0; j < m.sz; j++)
                if (!(istr >> m.pMem[i][j]))
                    throw std::invalid_argument("Invalid input into matrix");

        return istr;
    }

    friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& m)
    {
        for (size_t i = 0; i < m.sz; i++)
        {
            for (size_t j = 0; j < m.sz; j++)
                ostr << m.pMem[i][j] << " ";
            ostr << "\n";
        }

        return ostr;
    }
};

#endif
