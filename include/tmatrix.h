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
template <typename T>
class TDynamicVector
{
protected:
    size_t sz;
    T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
      if ((sz == 0) || (sz > MAX_MATRIX_SIZE))
          throw out_of_range("Error, vector size should be greater than zero and not exceed MAX_VECTOR_SIZE");
      
      pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }

  TDynamicVector(T* arr, size_t s) : sz(s)
  {
      if ((sz == 0) || (sz > MAX_MATRIX_SIZE))
          throw out_of_range("Error, vector size should be greater than zero and not exceed MAX_VECTOR_SIZE");
      
      assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
      pMem = new T[sz];
      for (int i = 0; i < sz; i++)
          pMem[i] = arr[i];
  }

  TDynamicVector(const TDynamicVector& v)
  {
      sz = v.sz;
      pMem = new T[sz];
      for (int i = 0; i < sz; i++)
          pMem[i] = v.pMem[i];
  }

  TDynamicVector(TDynamicVector&& v) noexcept
  {
      pMem = nullptr;
      swap(*this, v);
  }

  ~TDynamicVector()
  {
      delete[] pMem;
      sz = 0;
      pMem = nullptr;
  }

  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this != &v) {
          if (sz != v.sz) {
              T* tmp = new T[v.sz];
              delete[] pMem;
              pMem = tmp;
              sz = v.sz; 
          }
          for (size_t i = 0; i < sz; i++)
              pMem[i] = v[i];
      }
      return *this;
  }

  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
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
          throw out_of_range("Error, index is out of range of the vector size");
      return pMem[ind];
  }

  const T& at(size_t ind) const
  {
      if (ind >= sz)
          throw out_of_range("Error, index is out of range of the vector size");
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) 
          return false;
      for (int i = 0; i < sz; i++)
          if (pMem[i] != v.pMem[i]) 
              return false;
      return true;
  }

  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(*this == v)
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] + val;
      return res;
  }

  TDynamicVector operator-(double val)
  {
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] - val;
      return res;
  }

  TDynamicVector operator*(double val)
  {
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] * val;
      return res;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz) 
          throw invalid_argument("Error, vectors have different sizes");

      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] + v.pMem[i];
      return res;
  }

  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw invalid_argument("Error, vectors have different sizes");

      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] - v.pMem[i];
      return res;
  }

  T operator*(const TDynamicVector& v) 
  {
      if (sz != v.sz)
          throw invalid_argument("Error, vectors have different sizes");

      T res = 0;
      for (int i = 0; i < sz; i++)
          res += pMem[i] * v.pMem[i];
      return res;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
      swap(lhs.sz, rhs.sz);
      swap(lhs.pMem, rhs.pMem);
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
      if ((s == 0) || (s > MAX_MATRIX_SIZE))
          throw out_of_range("Error, matrix size should be greater than zero and not exceed MAX_MATRIX_SIZE");
      
      for (size_t i = 0; i < sz; i++)
          pMem[i] = TDynamicVector<T>(sz);
  }
  
  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::size;

  T& at(size_t ind1, size_t ind2)
  {
      if ((ind1 >= sz) || (ind2 >= sz))
          throw out_of_range("Error, one of index is out of range of the matrix size");

      return pMem[ind1][ind2];
  }

  const T& at(size_t ind1, size_t ind2) const
  {
      if ((ind1 >= sz) || (ind2 >= sz))
          throw out_of_range("Error, one of index is out of range of the matrix size");

      return pMem[ind1][ind2];
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
  TDynamicMatrix<T> operator*(T val)
  {
      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++)
          res[i] = pMem[i] * val;
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.size())
          throw invalid_argument("Error, matrix and vector have different sizes");

      TDynamicVector<T> res(sz);
      for (int i = 0; i < sz; i++)
          res[i] = pMem[i] * v;
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw invalid_argument("Error, matrices have different sizes");

      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++)
          res[i] = pMem[i] + m[i];
      return res;
  }

  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw invalid_argument("Error, matrices have different sizes");

      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++)
          res[i] = pMem[i] - m[i];
      return res;
  }

  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw invalid_argument("Error, matrices have different sizes");

      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++)
          for (int k = 0; k < sz; k++)
              for (int j = 0; j < sz; j++)
                  res[i][j] += pMem[i][k] * m.pMem[k][j];
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& m)
  {
      for (int i = 0; i < m.sz; i++)
          for (int j = 0; j < m.sz; j++)
              istr >> m.pMem[i][j];
      return istr;
  }

  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& m)
  {
      for (int i = 0; i < m.sz; i++)
      {
          for (int j = 0; j < m.sz; j++)
              ostr << m.pMem[i][j] << " ";
          ostr << "\n";
      }
      return ostr;
  }
};

#endif