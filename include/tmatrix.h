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
    if (sz <= 0||sz>MAX_VECTOR_SIZE)  
      throw out_of_range("Vector size should be greater than zero and less than MAX_VECTOR_SIZE");
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
      sz = v.sz;
      pMem = new T[sz];
      for (int i = 0; i < v.sz; i++) {
          pMem[i] = v.pMem[i];
      }
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
      sz = v.sz;
      pMem = v.pMem;
      v.pMem = nullptr;
      v.sz = 0;
  }
  ~TDynamicVector()
  {
      sz = 0;
      delete[] pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (*this == v) return *this;
      if (sz != v.sz) {
          sz = v.sz;
          delete[] pMem;
          T* tmp = new T[sz]();
          pMem = tmp;
      }
      for (int i = 0; i < sz; i++) {
          pMem[i] = v.pMem[i];
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      if (*this == v) return *this;
      delete[] pMem;
      sz = v.sz;
      pMem = v.pMem;
      v.pMem = nullptr;
      v.sz = 0;
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
      if ((ind >= 0) && (ind < sz)) return pMem[ind];
      else throw logic_error(" the index must be non-negative and smaller than the size of the vector");
  }
  const T& at(size_t ind) const
  {
      if ((ind >= 0) && (ind < sz)) return pMem[ind];
      else throw logic_error("the index must be non-negative and smaller than the size of the vector ");
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.size()) return false;
      for (int i = 0; i < sz; i++) {
          if (pMem[i] != v.pMem[i]) return false;
      }
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(*this == v);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector<T> tmp(sz);
      for (int i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] + val;
      }
      return tmp;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector<T> tmp(sz);
      for (int i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] - val;
      }
      return tmp;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector<T> tmp(sz);
      for (int i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] * val;
      }
      return tmp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz) {
          throw logic_error("vectors must be equal size");

      }
      TDynamicVector<T> tmp(sz);
      for (int i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] + v.pMem[i];
      }
      return tmp;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz) {
          throw logic_error("vectors must be equal size");

      }
      TDynamicVector<T> tmp(sz);
      for (int i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] - v.pMem[i];
      }
      return tmp;
  }

  T operator*(const TDynamicVector& v) 
  {

      if (sz != v.sz) {
          throw logic_error("vectors must be equal size");
          
      }
      T tmp = {};
      for (int i = 0; i < sz; i++) {
          tmp += pMem[i] * v.pMem[i];
      }
      return tmp;
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
      if (sz <= 0 || sz > MAX_MATRIX_SIZE)
          throw out_of_range("Vector size should be greater than zero and less than MAX_MATRIX_SIZE");
      for (size_t i = 0; i < sz; i++)
          pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];
  T& at(size_t i, size_t j)
  {
      if (((i >= 0) && (i < sz)) && ((j >= 0) && (j < sz))) return pMem[i][j];
      else throw logic_error("the index must be non-negative and smaller than the size of the matrix ");
  }
  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      if (sz != m.sz) return false;
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < pMem[i].size(); j++) {
              if (pMem[i][j] != m.pMem[i][j]) return false;
          }
      }
      return true;
  }
  bool operator !=(const TDynamicMatrix& m) const noexcept
  {
      return !(*this == m);
  }

  // матрично-скалярные операции
  TDynamicVector<T> operator*(const T& val)
  {
      TDynamicMatrix<T> tmp(sz);
      for (int i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] * val;
      }
      return tmp;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.sz) throw logic_error("Matrix and vector must be equal size");
      TDynamicVector<T> tmp(sz);
      for (int i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] * v;
      }
      return tmp;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz) throw logic_error("Matrix and vector must be equal size");
      TDynamicMatrix<T> tmp(sz);
      for (int i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] + m.pMem[i];
      }
      return tmp;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz) throw logic_error("Matrix and vector must be equal size");
      TDynamicMatrix<T> tmp(sz);
      for (int i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] - m.pMem[i];
      }
      return tmp;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz) throw logic_error("Matrix and vector must be equal size");
      TDynamicMatrix<T> tmp(sz);
      for (int i = 0; i < sz; i++)
          for (int j = 0; j < sz; j++)
              tmp.pMem[i][j] = 0;
      for (int i = 0; i < sz; i++) {
          for (int k = 0; k < sz; k++) {
              for (int j = 0; j < sz; j++) {
                  tmp.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
              }
          }
      }
      return tmp;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          for (size_t j = 0; j < v.sz; j++) 
              istr >> v.pMem[i][j]; // требуется оператор>> для типа T
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++) {
          for (size_t j = 0; j < v.sz; j++)
              ostr << v.pMem[i][j] << ' '; // требуется оператор<< для типа T
      }
      return ostr;
  }
};

#endif


