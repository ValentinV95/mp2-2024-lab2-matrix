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
    if ((sz == 0)||(sz> MAX_VECTOR_SIZE))
      throw out_of_range("Vector size should be greater than zero and less than 100000000");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    if ((sz==0)||sz> MAX_VECTOR_SIZE) throw out_of_range("Vector size should be greater than zero and less than 100000000");
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
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
      pMem = nullptr;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this != &v) {
          if (sz != v.sz) {
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
      swap(*this, v);
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](int ind)
  {
      return pMem[ind];
  }
  const T& operator[](int ind) const
  {
      return pMem[ind];
  }
  // индексация с контролем
  T& at(int ind)
  {
      if ((ind >= 0) && (ind < sz)) {
          return pMem[ind];
      }
      throw out_of_range("index should be greater than zero and less than 100000000");
  }
  const T& at(int ind) const
  {
      if ((ind >= 0) && (ind < sz)) {
          return pMem[ind];
      }
      throw out_of_range("index should be greater than zero and less than 100000000");
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz == v.sz) {
          for (int i = 0; i < sz; i++) {
              if (pMem[i] != v.pMem[i]) return false;
          }
          return true;
      }
      return false;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(v == *this);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector<T> tmp(sz);
      for (int i = 0; i < sz; i++) tmp.pMem[i] = pMem[i] + val;
      return tmp;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector<T> tmp(sz);
      for (int i = 0; i < sz; i++) tmp.pMem[i] = pMem[i] - val;
      return tmp;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector<T> tmp(sz);
      for (int i = 0; i < sz; i++) tmp.pMem[i] = pMem[i] * val;
      return tmp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz == v.sz) {
          TDynamicVector<T> tmp(sz);
          for (int i = 0; i < sz; i++) tmp.pMem[i] = pMem[i] + v.pMem[i];
          return tmp;
      }
      throw invalid_argument("we can only add vectors of the same size");
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz == v.sz) {
          TDynamicVector<T> tmp(sz);
          for (int i = 0; i < sz; i++) tmp.pMem[i] = pMem[i] - v.pMem[i];
          return tmp;
      }
      throw invalid_argument("we can only subtract vectors of the same size");
  }
  T operator*(const TDynamicVector& v)
  {
      if (sz == v.sz) {
          T res = {};
          for (int i = 0; i < sz; i++) res+=pMem[i]*v.pMem[i];
          return res;
      }
      throw invalid_argument("we can only multiply vectors of the same size");
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
    if ((s>MAX_MATRIX_SIZE)||(s==0)) throw out_of_range("Matrix size should be greater than zero and less than 10000");
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::at;
  using TDynamicVector<TDynamicVector<T>>::size;
  using TDynamicVector<TDynamicVector<T>>::operator=;

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
      TDynamicMatrix tmp(sz);
      for (int i = 0; i < sz; i++) tmp.pMem[i] = pMem[i] * val;
      return tmp;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz == v.size()) {
          TDynamicVector<T> tmp(sz);
          for (int i = 0; i < sz; i++) {
              tmp[i] = pMem[i] * v;
          }
          return tmp;
      }
      throw invalid_argument("We can multiply a matrix by a vector only of comparable size");
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz == m.sz) {
          TDynamicMatrix tmp(sz);
          for (int i = 0; i < sz; i++) tmp.pMem[i] = pMem[i] + m.pMem[i];
          return tmp;
      }
      throw invalid_argument("We can add a matrix by a vector only of comparable size");
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz == m.sz) {
          TDynamicMatrix tmp(sz);
          for (int i = 0; i < sz; i++) tmp.pMem[i] = pMem[i] - m.pMem[i];
          return tmp;
      }
      throw invalid_argument("We can subtract a matrix by a vector only of comparable size");
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz == m.sz) {
          TDynamicMatrix tmp(sz);
          for (int i = 0; i < sz; i++)
              for (int k = 0; k < sz; k++)
                  for (int j = 0; j < sz; j++)
                      tmp.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
          return tmp;
      }
      throw invalid_argument("We can multiply a matrix by a matrix only of comparable size");
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& m)
  {
      for (int i = 0; i < m.sz; i++) istr >> (m.pMem)[i];
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& m)
  {
      for (int i = 0; i < m.sz; i++) ostr << (m.pMem)[i] << '\n';
      return ostr;
  }
};

#endif
