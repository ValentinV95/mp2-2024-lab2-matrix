// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include <assert.h>

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
    TDynamicVector(size_t size = 100) : sz(size)
    {
        if ((sz == 0) || (sz > MAX_VECTOR_SIZE))
            throw std::out_of_range("vector size should be greater than zero and less or equal than maximum vector size");

        pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
    }
    TDynamicVector(T* arr, size_t s) : sz(s)
    {
        if (sz > MAX_VECTOR_SIZE) throw std::out_of_range("vector size should be less or equal than maximum vector size");

        assert(arr != nullptr && "TDynamicVector requires non-nullptr arg");

        pMem = new T[sz];

        std::copy(arr, arr + sz, pMem);
    }
    TDynamicVector(const TDynamicVector& v)
    {
        sz = v.sz;

        pMem = new T[sz];

        std::copy(v.pMem, v.pMem + sz, pMem);
    }
    TDynamicVector(TDynamicVector&& v) noexcept
    {
        pMem = nullptr;

        sz = 0;

        swap(*this, v);
    }
    ~TDynamicVector()
    {
        sz = 0;

        delete[] pMem;
    }
    TDynamicVector& operator=(const TDynamicVector& v)
    {
        if (*this == v) return *this;

        if (sz != v.sz)
        {
            T* tmp = new T[v.sz];

            delete[] pMem;

            pMem = tmp;

            sz = v.sz;
        }

        for (size_t i = 0; i < sz; i++)
            pMem[i] = v[i];

        return *this;
    }
    TDynamicVector& operator=(TDynamicVector&& v) noexcept
    {
        delete[] pMem;

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
        if (ind >= sz) throw std::out_of_range("ind should be less than size");

        return pMem[ind];
    }
    const T& at(size_t ind) const
    {
        if (ind >= sz) throw std::out_of_range("ind should be less than size");

        return pMem[ind];
    }

    // сравнение
    bool operator==(const TDynamicVector& v) const noexcept
    {
        if (sz != v.sz) return false;

        for (size_t i = 0; i < sz; i++)
            if (pMem[i] != v[i]) return false;

        return true;
    }
    bool operator!=(const TDynamicVector& v) const noexcept
    {
        return !(*this == v);
    }

    // скалярные операции
    TDynamicVector operator+(T val)
    {
        TDynamicVector res(*this);

        for (size_t i = 0; i < sz; i++)
            res[i] += val;

        return res;
    }
    TDynamicVector operator-(T val)
    {
        TDynamicVector res(*this);

        for (size_t i = 0; i < sz; i++)
            res[i] -= val;

        return res;
    }
    TDynamicVector operator*(T val)
    {
        TDynamicVector res(*this);

        for (size_t i = 0; i < sz; i++)
            res[i] *= val;

        return res;
    }

    // векторные операции
    TDynamicVector operator+(const TDynamicVector& v)
    {
        if (sz != v.sz) throw std::out_of_range("vectors should have equal sizes");

        TDynamicVector res(*this);

        for (size_t i = 0; i < sz; i++)
            res[i] += v[i];

        return res;
    }
    TDynamicVector operator-(const TDynamicVector& v)
    {
        if (sz != v.sz) throw std::out_of_range("vectors should have equal sizes");

        TDynamicVector res(*this);

        for (size_t i = 0; i < sz; i++)
            res[i] -= v[i];

        return res;
    }
    T operator*(const TDynamicVector& v) //Dot product
    {
        if (sz != v.sz) throw std::out_of_range("vectors should have equal sizes");

        T res = static_cast<T>(0);

        for (size_t i = 0; i < sz; i++)
            res += pMem[i] * v[i];

        return res;
    }

    TDynamicVector& operator+=(const TDynamicVector& v)
    {
        if (sz != v.sz) throw std::out_of_range("vectors should have equal sizes");

        for (size_t i = 0; i < sz; i++)
            pMem[i] += v[i];

        return *this;
    }

    friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
    {
        std::swap(lhs.sz, rhs.sz);

        std::swap(lhs.pMem, rhs.pMem);
    }

    // ввод/вывод
    friend std::istream& operator>>(std::istream& istr, TDynamicVector& v)
    {
        for (size_t i = 0; i < v.sz; i++)
            istr >> v[i]; // требуется оператор>> для типа T
        return istr;
    }
    friend std::ostream& operator<<(std::ostream& ostr, const TDynamicVector& v)
    {
        for (size_t i = 0; i < v.sz; i++)
            ostr << v[i] << ' '; // требуется оператор<< для типа T
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
    TDynamicMatrix(size_t s = 100) : TDynamicVector<TDynamicVector<T>>(s)
    {
        if ((s == 0) || (s > MAX_MATRIX_SIZE))
            throw std::out_of_range("matrix size should be greater than zero and less or equal than maximum matrix size");

        for (size_t i = 0; i < sz; i++)
            pMem[i] = TDynamicVector<T>(sz);
    }

    using TDynamicVector<TDynamicVector<T>>::operator[];
    using TDynamicVector<TDynamicVector<T>>::size;

    T& at(size_t ind1, size_t ind2)
    {
        if ((ind1 >= sz) || (ind2 >= sz)) throw std::out_of_range("ind1 and ind2 should be less than size");

        return pMem[ind1][ind2];
    }

    // сравнение
    bool operator==(const TDynamicMatrix& m) const noexcept
    {
        if (sz != m.sz) return false;

        return TDynamicVector<TDynamicVector<T>>::operator==(m);
    }

    // матрично-скалярные операции
    TDynamicMatrix<T> operator*(T val)
    {
        TDynamicMatrix res(sz);

        for (size_t i = 0; i < sz; i++)
            res[i] = pMem[i] * val;

        return res;
    }

    // матрично-векторные операции
    TDynamicVector<T> operator*(const TDynamicVector<T>& v)
    {
        if (sz != v.size()) throw std::out_of_range("vector and matrix should have equal sizes");

        TDynamicVector<T> res(sz);

        for (size_t i = 0; i < sz; i++)
            res[i] = pMem[i] * v;

        return res;
    }

    // матрично-матричные операции
    TDynamicMatrix operator+(const TDynamicMatrix& m)
    {
        if (sz != m.sz) throw std::out_of_range("matrixs should have equal sizes");

        TDynamicMatrix res(sz);

        for (size_t i = 0; i < sz; i++)
            res[i] = pMem[i] + m[i];

        return res;
    }
    TDynamicMatrix operator-(const TDynamicMatrix& m)
    {
        if (sz != m.sz) throw std::out_of_range("matrixs should have equal sizes");

        TDynamicMatrix res(sz);

        for (size_t i = 0; i < sz; i++)
            res[i] = pMem[i] - m[i];

        return res;
    }
    TDynamicMatrix operator*(const TDynamicMatrix& m)
    {
        if (sz != m.sz) throw std::out_of_range("matrixs should have equal sizes");

        TDynamicMatrix res(sz);

        for (size_t i = 0; i < sz; i++)
            for (size_t j = 0; j < sz; j++)
                for (size_t k = 0; k < sz; k++)
                    res[i][j] += pMem[i][k] * m[k][j];

        return res;
    }

    // ввод/вывод
    friend std::istream& operator>>(std::istream& istr, TDynamicMatrix& m)
    {
        for (size_t i = 0; i < m.sz; i++)
            istr >> m[i];

        return istr;
    }
    friend std::ostream& operator<<(std::ostream& ostr, const TDynamicMatrix& m)
    {
        for (size_t i = 0; i < m.sz; i++)
            ostr << m[i] << "\n";

        return ostr;
    }
};

#endif
