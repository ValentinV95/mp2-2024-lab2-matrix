// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__
#include <iostream>

using namespace std;

constexpr int MAX_VECTOR_SIZE = 100000000;
constexpr int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)    //DONE
  {
      if (sz == 0)
          throw out_of_range("Vector size should be greater than zero");
      if (sz > MAX_VECTOR_SIZE) {
          throw length_error("bad vector size!");
      }
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)      //DONE
  {
      if (sz == 0)
          throw out_of_range("Vector size should be greater than zero");
      if (sz > MAX_VECTOR_SIZE) {
          throw length_error("bad vector size!");
      }
      if (arr == nullptr) {
          throw exception("nullptr array");
      }
      assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)   //DONE
  {
      sz = v.sz;
      pMem = new T[sz];
      std::copy(v.pMem, v.pMem + sz, pMem);
  }
  TDynamicVector(TDynamicVector&& v) noexcept   //DONE
  {
      pMem = nullptr;
      swap(*this, v);
  }
  ~TDynamicVector() //DONE
  {
      sz = 0;
      delete[] pMem;    //с 11го c++ delete[] вызовет деструкторы у элементов массива(если есть)
      pMem = nullptr;
  }
  TDynamicVector& operator=(const TDynamicVector& v)    //DONE
  {
      if (&v == this) { return *this; }

          if (sz != v.sz) {
              sz = v.sz;
              T* p = new T[sz];
              delete[] pMem;
              pMem = p;
          }
          std::copy(v.pMem, v.pMem + sz, pMem);
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept    //DONE
  {
      swap(*this, v);
      return *this;
  }

  size_t size() const noexcept { return sz; }   //DONE

  // индексация
  T& operator[](size_t ind) //DONE
  {
      return pMem[ind];
  }

  const T& operator[](size_t ind) const //DONE
  {
      return pMem[ind];
  }

  // индексация с контролем
  T& at(size_t ind)     //MAYBE DONE
  {
      if (ind >= sz) {
          throw out_of_range("at out of range");
      }
      return pMem[ind];
  }
  const T& at(size_t ind) const //MAYBE DONE
  {
      if (ind >= sz) {
          throw out_of_range("at out of range");
      }
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept   //DONE
  {
      if (sz != v.sz) return false;

      T eps = std::numeric_limits<T>::epsilon();    //for double and float)

      for (size_t i = 0; i < sz; i++) {
          if (pMem[i] > v.pMem[i]) {
              if (pMem[i] - v.pMem[i] > eps) {
                  return false;
              }
          }
          else {
              if (v.pMem[i] - pMem[i] > eps) {
                  return false;
              }
          }
      }

      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept   //DONE
  {
      return !(*this == v);
  }

  // скалярные операции
  TDynamicVector<T> operator+(T val)   //DONE
  {
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] + val;
      }
      return res;
  }
  TDynamicVector<T> operator-(T val)  //DONE
  {
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] - val;
      }
      return res;
  }

  TDynamicVector<T> operator*(T val)  //DONE
  {
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] * val;
      }
      return res;
  }

  // векторные операции
  TDynamicVector<T> operator+(const TDynamicVector& v) //DONE
  {
      if (sz != v.sz) {
          throw length_error("different lengths! ");
      }
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] + v.pMem[i];
      }
      return res;
  }
  TDynamicVector<T> operator-(const TDynamicVector& v) //DONE
  {
      if (sz != v.sz) {
          throw length_error("different lengths! ");
      }
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] - v.pMem[i];
      }
      return res;
  }
  T operator*(const TDynamicVector& v)  //DONE
  {
      if (sz != v.sz) {
          throw length_error("different lengths! ");
      }
      T res = static_cast<T>(0);
      for (size_t i = 0; i < sz; i++) {
          res += pMem[i] * v.pMem[i];
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
      if (sz > MAX_MATRIX_SIZE) throw length_error("bad matrix size");
      for (size_t i = 0; i < sz; i++)
        pMem[i] = TDynamicVector<T>(sz);
  }

  //<--------------vector's f block------------------>
  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::at;
  using TDynamicVector<TDynamicVector<T>>::size;
  //<-------------------end-------------------------->

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      for (size_t i = 0; i < sz; i++) {
          if (pMem[i] != m.pMem[i]) return false;
      }
      return true;
  }
  bool operator!=(const TDynamicMatrix& m) const noexcept
  {
      return !(*this == m);
  }

  // матрично-скалярные операции
  TDynamicMatrix<T> operator*(const T& val)
  {     
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz;i++) {
          res.pMem[i] = pMem[i] * val;
      }
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.size()) {
          throw length_error("bad m and v lengths");
      }
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; i++)
          res[i] = pMem[i] * v;
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix<T> operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz) {
          throw length_error("different sizes");
      }
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] + m.pMem[i];
      }
      return res;
  }
  TDynamicMatrix<T> operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz) {
          throw length_error("different sizes");
      }
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] - m.pMem[i];
      }
      return res;
  }
  TDynamicMatrix<T> operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz) {
          throw length_error("bad sizes");
      }
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; i++) {
          for (size_t j = 0; j < sz; j++) {
              for (size_t u = 0; u < sz; u++) {
                  res.pMem[i][j] += pMem[i][u] * m.pMem[u][j];
              }
          }
      }
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz;i++) {
          istr >> v[i];
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz;i++) {
          ostr << v[i] << std::endl;
      }

      return ostr;
  }
};

#endif
