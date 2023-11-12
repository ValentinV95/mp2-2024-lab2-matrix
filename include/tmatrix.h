// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include <cassert>

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
      throw out_of_range("Vector size should be greater than zero");
    if (sz > MAX_VECTOR_SIZE)
        throw out_of_range("Vector size should be less than maximum size");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v) : sz(v.sz)
  {
      pMem = new T[sz];
      std::copy(v.pMem, v.pMem + sz, pMem);
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
      pMem = nullptr;
      swap(*this, v);
  }
  ~TDynamicVector()
  {
      delete[] pMem;
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
      this->sz = 0;
      delete[] pMem;
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
          throw exception("Index cant be negative or bigger then size");
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if(ind>=sz)
          throw exception("Index cant be negative or bigger then size");
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
          return false;
      for (size_t i = 0; i < sz; i++)
          if (pMem[i] != v.pMem[i])
              return false;
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
          return true;
      for (size_t i = 0; i < sz; i++)
          if (pMem[i] == v.pMem[i])
              return false;
      return true;
  }

  // скалярные операции
  TDynamicVector<T> operator+(T val)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] + val;
      return tmp;
  }
  TDynamicVector<T> operator-(double val)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] - val;
      return tmp;
  }
  TDynamicVector<T> operator*(double val)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] * val;
      return tmp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw exception("Vectors must have the same size for this operation");
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] + v.pMem[i];
      return tmp;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw exception("Vectors must have the same size for this operation");
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] - v.pMem[i];
      return tmp;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      if (sz != v.sz)
          throw exception("Vectors must have the same size for this operation");
      T res = T();
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
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if (sz == 0)
          throw out_of_range("Matrix size should be greater than zero");
      if (sz > MAX_MATRIX_SIZE)
          throw out_of_range("Matrix should be lower than MAX_MATRIX_SIZE");
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }
  TDynamicMatrix(const TDynamicMatrix& other) : TDynamicVector<TDynamicVector<T>>(other.sz)
  {
      for (size_t i = 0; i < sz; i++)
          pMem[i] = other.pMem[i];
  }

  TDynamicMatrix& operator = (const TDynamicMatrix& other)
  {
      if (this == &other)
          return *this;
      this->sz = other.sz;
      delete[] pMem;
      T* pMem = new TDynamicVector[sz];
      for (size_t i = 0; i < sz; i++)
          pMem[i] = other.pMem[i];
      return *this;
  }
  using TDynamicVector<TDynamicVector<T>>::operator[];

  size_t size() const noexcept { return sz; }

  T& at(int row, int col)
  {
      if (row < sz && col < sz && row >= 0 && col >= 0)
      {
          return pMem[row][col];
      }
      throw exception("wrong index!");
  }

  const T& at(int row, int col) const
  {
      if (row < sz && col < sz && row >= 0 && col >= 0)
      {
          return pMem[row][col];
      }
      throw exception("wrong index!");
  }
  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      if (this->sz != m.sz)
          return false;
      for (size_t i = 0; i < sz; i++)
          if (pMem[i] != m.pMem[i])
              return false;
      return true;
  }
 
  // матрично-скалярные операции
  TDynamicVector<T> operator*(const T& val)
  {
      TDynamicMatrix res(*this);
      for (size_t i = 0; i < sz; i++)
          res.pMem[i] = res.pMem[i] * val;
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; i++)
          res[i] = pMem[i] * v;
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz) 
      {
          throw logic_error("vectors must be equal size");
      }
      TDynamicMatrix res(sz);
      for (size_t i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] + m.pMem[i];
      return res;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
      {
          throw logic_error("vectors must be equal size");
      }
      TDynamicMatrix res(sz);
      for (size_t i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] - m.pMem[i];
      return res;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
      {
          throw logic_error("vectors must be equal size");
      }
      TDynamicMatrix res(sz);
      for (size_t i = 0; i < sz; i++)
          for (size_t j = 0; j < sz; j++)
              for (size_t l = 0; l < sz; l++)
                  res.pMem[i][j] += pMem[i][l] * m.pMem[l][j];
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          for (size_t j = 0; j < v.sz; j++)
              istr >> v[i][j];
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
      {
          for (size_t j = 0; j < v.sz; j++)
          {
              ostr << v[i][j] << "\t";
          }
          ostr << endl;
      }
      return ostr;
  }
};

#endif
