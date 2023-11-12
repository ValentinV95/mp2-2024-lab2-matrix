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
      if (sz <= 0 || sz > MAX_VECTOR_SIZE)
          throw invalid_argument("Vector size should be greater than zero and less than max vector size");
    
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
      assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)
  {
      pMem = new T[v.sz];
      sz = v.sz;
      std::copy(v.pMem, v.pMem + sz, pMem);
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
      pMem = nullptr;
      swap(*this, v);
  }
  ~TDynamicVector()
  {
      sz = 0;
      delete[] pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v)
          return *this;
      if (sz != v.sz)
      {
          sz = v.sz;
          T* tmp = new T[sz];
          delete[] pMem;
          pMem = tmp;
      }
      std::copy(v.pMem, v.pMem + v.sz, pMem);
      return *this;

  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      swap(*this,v);
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
      if (ind < 0 || ind >= sz)
          throw out_of_range("Index should be between 0 and size of vector");
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind < 0 || ind >= sz)
          throw out_of_range("Index should be between 0 and size of vector");
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
          return false;
      for (size_t i = 0; i < sz; i++)
          if (pMem[i] != v[i])
              return false;
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(v == *this);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector res(*this);
      for (size_t i = 0; i < sz; i++)
          res[i] += val;
      return res;
  }
  TDynamicVector operator-(T val)//стояло double???
  {
      TDynamicVector res(*this);
      for (size_t i = 0; i < sz; i++)
          res[i] -= val;
      return res;
  }
  TDynamicVector operator*(T val)//стояло double???
  {
      TDynamicVector res(*this);
      for (size_t i = 0; i < sz; i++)
          res[i] *= val;
      return res;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw logic_error("Not equel size");
      TDynamicVector res(*this);
      for (size_t i = 0; i < sz; i++)
      {
          res[i] += v[i];
      }
      return res;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw logic_error("Not equel size");
      TDynamicVector res(*this);
      for (size_t i = 0; i < sz; i++)
      {
          res[i] -= v[i];
      }
      return res;
  }
  T operator*(const TDynamicVector& v) 
  {
      T res = {};
      if (sz != v.sz)
          throw logic_error("Not equel size");
      for (size_t i = 0; i < sz; i++)
      {
          res += v.pMem[i] * pMem[i];
      }
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
      if (s > MAX_MATRIX_SIZE || s <= 0)
          throw invalid_argument("Matrix size should be greater than zero and less than max matrix size");
      for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::size;
  using TDynamicVector<TDynamicVector<T>>::operator=;

  T& at(size_t ind1,size_t ind2)
  {
      if (ind1 < 0 || ind1 >= sz || ind2 < 0 || ind2 >= sz)
          throw out_of_range("Index should be between 0 and size of vector");
      return pMem[ind1][ind2];
  }
  const T& at(size_t ind1, size_t ind2) const
  {
      if (ind1 < 0 || ind1 >= sz || ind2 < 0 || ind2 >= sz)
          throw out_of_range("Index should be between 0 and size of vector");
      return pMem[ind1][ind2];
  }

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      return TDynamicVector<TDynamicVector<T>>::operator==(m);
  }
  bool operator!=(const TDynamicMatrix& m) const noexcept
  {
      return !(*this == m);
  }

  // матрично-скалярные операции
  TDynamicMatrix<T> operator*(const T& val)
  {
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] * val;
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz!=v.size())
          throw logic_error("Not equel size");
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; i++)
          res[i] = pMem[i] * v;
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw logic_error("Not equel size");
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] + m.pMem[i];
      return res;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw logic_error("Not equel size");
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] - m.pMem[i];
      return res;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw logic_error("Not equel size");
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; i++)
          for (size_t k = 0; k < sz; k++)
              for (size_t j = 0; j < sz; j++)
                  res.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.size(); i++)
              istr >> v.pMem[i];
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.size(); i++)
      {
              ostr << v.pMem[i] << "\n";
      }
      return ostr;
  }
};

#endif
