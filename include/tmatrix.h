// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iomanip>
#include <iostream>

using namespace std;

constexpr int MAX_VECTOR_SIZE = 100000000;
constexpr int MAX_MATRIX_SIZE = 10000;

template<typename T>
class TDynamicVector {
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size) {
    if (sz == 0 || sz > MAX_VECTOR_SIZE)
      throw out_of_range("Vector size should be greater than zero");
    pMem = new T[sz]();
  }

  TDynamicVector(T* arr, size_t s) : sz(s) {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }

  TDynamicVector(const TDynamicVector& other) : sz(other.sz), pMem(new T[sz]) {
      std::copy(other.pMem, other.pMem + other.sz, pMem);
  }

  TDynamicVector(TDynamicVector&& moved) noexcept : sz(moved.sz), pMem(moved.pMem)  {
      moved.pMem = nullptr;
  }

  ~TDynamicVector() {
      delete[] pMem;
  }

  TDynamicVector& operator=(const TDynamicVector& v) {
      if(sz != v.sz)
        delete[] pMem;
      sz = v.sz;
      pMem = new T[sz];
      std::copy(v.pMem, v.pMem + sz, pMem);
      return *this;
  }

  TDynamicVector& operator=(TDynamicVector&& v) noexcept {
      delete[] pMem;
      sz = v.sz;
      pMem = v.pMem;
      v.pMem = nullptr;
      return *this;
  }

  size_t size() const noexcept { return sz; }

  T& operator[](size_t ind) {
      return pMem[ind];
  }
  const T& operator[](size_t ind) const {
      return pMem[ind];
  }

  T& at(size_t ind) {
    if (ind < 0 || ind >= sz)
        throw std::out_of_range("TVector subscript out of range");
    return pMem[ind];
  }

  const T& at(size_t ind) const {
    if (ind < 0 || ind >= sz)
        throw std::out_of_range("TVector subscript out of range");
    return pMem[ind];
  }

  bool operator==(const TDynamicVector& v) const noexcept {
      if (this == &v) return true;
      if (sz != v.sz) return false;
      for (size_t i = 0; i < sz; ++i) {
          if (pMem[i] != v.pMem[i])
              return false;
      }
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept {
      return !(*this == v);
  }

  TDynamicVector operator+(T val) {
      TDynamicVector<T> res(*this);
      for (int i = 0; i < sz; i++)
          res.pMem[i] += val;
      return res;
  }

  TDynamicVector operator-(double val) {
      TDynamicVector<T> res(*this);
      for (int i = 0; i < sz; i++)
          res.pMem[i] -= val;
      return res;
  }

  TDynamicVector operator*(double val) {
      TDynamicVector<T> res(*this);
      for (int i = 0; i < sz; i++)
          res.pMem[i] *= val;
      return res;
  }

  TDynamicVector operator+(const TDynamicVector& v) {
      if (sz != v.sz)
          throw std::logic_error("different length");
      TDynamicVector<T> res(*this);
      for (int i = 0; i < sz; i++)
          res[i] += v[i];
      return res;
  }

  TDynamicVector operator-(const TDynamicVector& v) {
      if (sz != v.sz)
          throw std::logic_error("different length");
      TDynamicVector<T> res(*this);
      for (int i = 0; i < sz; i++)
          res.pMem[i] -= v.pMem[i];
      return res;
  }

  T operator*(const TDynamicVector& v) {
      if (sz != v.sz)
          throw std::logic_error("different length");
      T res{};
      for (int i = 0; i < sz; i++)
          res += pMem[i] * v.pMem[i];
      return res;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  friend istream& operator>>(istream& istr, TDynamicVector& v) {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i];
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v) {
    for (size_t i = 0; i < v.sz; i++)
      ostr <<std::left << std::setw(2)<< v.pMem[i] << ' ';
    return ostr;
  }
};


template<typename T>
class TDynamicMatrix : protected TDynamicVector<TDynamicVector<T>> {
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s) {
      if (s > MAX_MATRIX_SIZE)
          throw std::invalid_argument("Too large matrix");
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  size_t get_size() const noexcept { return sz * sz; }

  T& at(size_t i, size_t j) {
      if (i < 0 || i >= sz)
          throw std::out_of_range("TMatrix subscript out of range");
      return pMem[i][j];
  }

  const T& at(size_t i, size_t j) const {
      if (i < 0 || i >= sz)
          throw std::out_of_range("TMatrix subscript out of range");
      return pMem[i][j];
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  bool operator==(const TDynamicMatrix& m) const noexcept {
      if (sz != m.sz) return false;
      for (size_t i = 0; i < sz; ++i) {
          if (pMem[i] != m.pMem[i])
              return false;
      }
      return true;
  }

  bool operator!=(const TDynamicMatrix& m) const noexcept {
      return !(*this == m);
  }

  TDynamicMatrix<T> operator*(const T& val) {
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; ++i) {
          res.pMem[i] = pMem[i] * val;
      }
      return res;
  }

  TDynamicVector<T> operator*(const TDynamicVector<T>& v) {
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; ++i) {
          res[i] = pMem[i] * v;
      }
      return res;
  }

  TDynamicMatrix<T> operator+(const TDynamicMatrix& m) {
      if (sz != m.sz)
          throw std::logic_error("can't add matrix");
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; ++i) {
          res[i] = pMem[i] + m[i];
      }
      return res;
  }

  TDynamicMatrix<T> operator-(const TDynamicMatrix& m) {
      if (sz != m.sz)
          throw std::logic_error("can't add matrix");
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; ++i) {
          res[i] = pMem[i] - m[i];
      }
      return res;
  }

  TDynamicMatrix<T> operator*(const TDynamicMatrix& m) {
      if (sz != m.sz)
          throw std::logic_error("Can't multiply matrix");
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; ++i) {
          for (size_t j = 0; j < sz; ++j) {
              for (size_t k = 0; k < sz; ++k)
                  res[i][j] += pMem[i][k] * m[k][j];
          }
      }
      return res;
  }

  friend istream& operator>>(istream& istr, TDynamicMatrix& v) {
      for (size_t i = 0; i < v.sz; ++i) {
          istr >> v[i];
      }
      return istr;
  }

  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v) {
      for (size_t i = 0; i < v.sz; ++i) {
          ostr << v[i] << std::endl;
      }
      return ostr;
  }
};

#endif
