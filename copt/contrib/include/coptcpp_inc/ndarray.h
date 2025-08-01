#pragma once
#include "coptcpp.idl.h"
#include "mfactory.h"
#include "broadcasthelper.h"
#include "shape.h"
#include "view.h"

template <class T, int N> class NdArray {
public:
  NdArray(const Shape<N>& shape, T val) : m_nda(MFactory::Get().CreateNdArray<T, N>(shape.Get(), val)) {}
  NdArray(const Shape<N>& shape, T (*func)(size_t)) : m_nda(MFactory::Get().CreateNdArray<T, N>(shape.Get(), func)) {}
  NdArray(const Shape<N>& shape, const T* data, size_t sz)
    : m_nda(MFactory::Get().CreateNdArray<T, N>(shape.Get(), data, sz))
  {
  }
  NdArray(const std::initializer_list<T>& list)
    : m_nda(MFactory::Get().CreateNdArray<T, N>(Shape<1>(list.size()).Get(), list.begin(), list.size()))
  {
  }
  NdArray(const std::initializer_list<std::initializer_list<T>>& list)
    : m_nda(MFactory::Get().CreateNdArray<T, N>(Shape<2>(list.size(), list.begin()->size()).Get(), T(0)))
  {
    size_t idx = 0;
    for (const auto& row : list)
    {
      for (const auto& val : row)
      {
        m_nda->SetItem(idx++, val);
      }
    }
  }
  NdArray(Copt::INdArray<T, N>* nda) : m_nda(nda) {}

  int GetND() const
  {
    return m_nda->GetND();
  }

  size_t GetDim(int i) const
  {
    return m_nda->GetDim(i);
  }

  size_t GetSize() const
  {
    return m_nda->GetSize();
  }

  Shape<N> GetShape() const
  {
    return m_nda->GetShape();
  }

  NdArray<T, N - 1> Diagonal(int offset, int axis1 = 0, int axis2 = 1) const
  {
    return MHelper::Get().Diagonal(Get(), offset, axis1, axis2);
  }

  NdArray<T, N + 1> Expand(int axis = 0) const
  {
    return MHelper::Get().Expand(Get(), axis);
  }

  void Fill(T val)
  {
    m_nda->Fill(val);
  }

  NdArray<T, 1> Flatten() const
  {
    return m_nda->Flatten();
  }

  NdArray<T, N> Repeat(size_t repeats, int axis = 0) const
  {
    auto ret = m_nda->Repeat(repeats, axis);
    CHECKERROR(ret);
    return ret;
  }

  NdArray<T, N> RepeatBlock(size_t repeats, int axis = 0) const
  {
    auto ret = m_nda->RepeatBlock(repeats, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int M> NdArray<T, M> Reshape(const Shape<M>& shape) const
  {
    auto ret = m_nda->Reshape(shape.Get());
    CHECKERROR(ret);
    return ret;
  }

  NdArray<T, N - 1> Squeeze(int axis = 0) const
  {
    return MHelper::Get().Squeeze(Get(), axis);
  }

  NdArray<double, N> Stack(const NdArray<double, N>& other, int axis)
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  NdArray<T, N> Stack(const NdArray<int, N>& other, int axis)
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  NdArray<T, 0> Sum() const
  {
    return m_nda->Sum();
  }

  NdArray<T, N - 1> Sum(int axis) const
  {
    return MHelper::Get().Sum(Get(), axis);
  }

  NdArray<T, N> Transpose() const
  {
    return m_nda->Transpose();
  }

  T Item(size_t idx = 0) const
  {
    return m_nda->Item(idx);
  }

  void SetItem(size_t idx, T val)
  {
    m_nda->SetItem(idx, val);
  }

  NdArray<T, 1> Pick(const NdArray<int, 1>& indexes) const
  {
    return m_nda->Pick(indexes.Get());
  }

  NdArray<T, 1> Pick(const NdArray<int, 2>& idxrows) const
  {
    return m_nda->Pick(idxrows.Get());
  }

  std::string Represent(size_t maxlen = 512) const
  {
    return m_nda->Represent(maxlen);
  }

  NdArray<T, N - 1> operator[](int64_t idx) const
  {
    NdArray<T, N> ret = m_nda->Item(Mat::make_view(idx).Get());
    CHECKERROR(ret.Get());
    return ret.Squeeze(0);
  }

  NdArray<T, N> operator[](const View& view) const
  {
    auto ret = m_nda->Item(view.Get());
    CHECKERROR(ret);
    return ret;
  }

  /* plus operation for ndarray of same dimensions */
  NdArray<double, N> operator+(const NdArray<double, N>& mat) const
  {
    return BroadCastHelper::Get().PlusCast<T, double, double, N, N, N>(Get(), mat.Get());
  }

  NdArray<T, N> operator+(const NdArray<int, N>& mat) const
  {
    return BroadCastHelper::Get().PlusCast<T, int, T, N, N, N>(Get(), mat.Get());
  }

  /* substraction operation for ndarray of same dimensions */
  NdArray<double, N> operator-(const NdArray<double, N>& mat) const
  {
    return BroadCastHelper::Get().SubCast<T, double, double, N, N, N>(Get(), mat.Get());
  }

  NdArray<T, N> operator-(const NdArray<int, N>& mat) const
  {
    return BroadCastHelper::Get().SubCast<T, int, T, N, N, N>(Get(), mat.Get());
  }

  /* muliplication operation for ndarray of same dimensions */
  NdArray<double, N> operator*(const NdArray<double, N>& mat) const
  {
    return BroadCastHelper::Get().DotCast<T, double, double, N, N, N>(Get(), mat.Get());
  }

  NdArray<T, N> operator*(const NdArray<int, N>& mat) const
  {
    return BroadCastHelper::Get().DotCast<T, int, T, N, N, N>(Get(), mat.Get());
  }

  Copt::INdArray<T, N>* Get() const
  {
    return &(*m_nda);
  }

  friend std::ostream& operator<<(std::ostream& out, const NdArray& nda)
  {
    out << nda.Represent();
    return out;
  }

private:
  std::shared_ptr<Copt::INdArray<T, N>> m_nda;
};


/* plus casts for ndarray<double/int> */
template <class T, int N> NdArray<double, N> operator+(double a, const NdArray<T, N>& right)
{
  NdArray<double, 0> left(Shape<0>(), a);
  return BroadCastHelper::Get().PlusCast<double, T, double, 0, N, N>(left.Get(), right.Get());
}
template <class T, int N> NdArray<double, N> operator+(const NdArray<T, N>& left, double a)
{
  NdArray<double, 0> right(Shape<0>(), a);
  return BroadCastHelper::Get().PlusCast<T, double, double, N, 0, N>(left.Get(), right.Get());
}

template <class T, int N, int M>
NdArray<double, COPT_MAX(N, M)> operator+(const NdArray<T, N>& left, const NdArray<double, M>& right)
{
  return BroadCastHelper::Get().PlusCast<T, double, double, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
}

template <class T, int N, int M>
NdArray<T, COPT_MAX(N, M)> operator+(const NdArray<T, N>& left, const NdArray<int, M>& right)
{
  return BroadCastHelper::Get().PlusCast<T, int, T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
}

/* substract casts for ndarray<double/int> */
template <class T, int N> NdArray<double, N> operator-(double a, const NdArray<T, N>& right)
{
  NdArray<double, 0> left(Shape<0>(), a);
  return BroadCastHelper::Get().SubCast<double, T, double, 0, N, N>(left.Get(), right.Get());
}
template <class T, int N> NdArray<double, N> operator-(const NdArray<T, N>& left, double a)
{
  NdArray<double, 0> right(Shape<0>(), a);
  return BroadCastHelper::Get().SubCast<T, double, double, N, 0, N>(left.Get(), right.Get());
}

template <class T, int N, int M>
NdArray<double, COPT_MAX(N, M)> operator-(const NdArray<T, N>& left, const NdArray<double, M>& right)
{
  return BroadCastHelper::Get().SubCast<T, double, double, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
}

template <class T, int N, int M>
NdArray<T, COPT_MAX(N, M)> operator-(const NdArray<T, N>& left, const NdArray<int, M>& right)
{
  return BroadCastHelper::Get().SubCast<T, int, T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
}

/* multiplication casts for ndarray<double/int> */
template <class T, int N> NdArray<double, N> operator*(double a, const NdArray<T, N>& right)
{
  NdArray<double, 0> left(Shape<0>(), a);
  return BroadCastHelper::Get().DotCast<double, T, double, 0, N, N>(left.Get(), right.Get());
}
template <class T, int N> NdArray<double, N> operator*(const NdArray<T, N>& left, double a)
{
  NdArray<double, 0> right(Shape<0>(), a);
  return BroadCastHelper::Get().DotCast<T, double, double, N, 0, N>(left.Get(), right.Get());
}

template <class T, int N, int M>
NdArray<double, COPT_MAX(N, M)> operator*(const NdArray<T, N>& left, const NdArray<double, M>& right)
{
  return BroadCastHelper::Get().DotCast<T, double, double, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
}

template <class T, int N, int M>
NdArray<T, COPT_MAX(N, M)> operator*(const NdArray<T, N>& left, const NdArray<int, M>& right)
{
  return BroadCastHelper::Get().DotCast<T, int, T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
}

namespace Mat {

static COPT_UNUSED NdArray<double, 1> repeat(double a, size_t repeats)
{
  return MHelper::Get().Repeat(a, repeats);
}

static COPT_UNUSED NdArray<int64_t, 1> repeat(int64_t a, size_t repeats)
{
  return MHelper::Get().Repeat(a, repeats);
}

static COPT_UNUSED NdArray<int, 1> repeat(int a, size_t repeats)
{
  return MHelper::Get().Repeat(a, repeats);
}

/* Matrix Multiply with result of NdArray */
template <class T, int N, int M>
NdArray<double, N + M - 2> matmult(const NdArray<T, N>& left, const NdArray<double, M>& right)
{
  return MHelper::Get().MatMultiply<T, N, M, N + M - 2>(left.Get(), right.Get());
}

template <class T, int N, int M> NdArray<T, N + M - 2> matmult(const NdArray<T, N>& left, const NdArray<int, M>& right)
{
  return MHelper::Get().MatMultiply<T, N, M, N + M - 2>(left.Get(), right.Get());
}

template <class T, int N> NdArray<double, N> stack(const NdArray<T, N>& left, const NdArray<double, N>& right, int axis)
{
  return MHelper::Get().Stack<T, N>(left.Get(), right.Get(), axis);
}

template <class T, int N> NdArray<T, N> stack(const NdArray<T, N>& left, const NdArray<int, N>& right, int axis)
{
  return MHelper::Get().Stack<T, N>(left.Get(), right.Get(), axis);
}

// stack scalar and NdArray
template <class T, int N> NdArray<T, N> stack(T a, const NdArray<T, N>& nda, int axis)
{
  NdArray<T, N> left(nda.GetShape().RebuildWith(1), a);
  return MHelper::Get().Stack<T, N>(left.Get(), nda.Get(), axis);
}
template <class T, int> NdArray<T, 2> hstack(T a, const NdArray<T, 1>& nda)
{
  Shape<2> shp = nda.GetShape().Expand(1);
  return Mat::stack<T, 2>(a, nda.Reshape(shp), -1);
}
template <class T, int N> NdArray<T, N> hstack(T a, const NdArray<T, N>& nda)
{
  return Mat::stack(a, nda, -1);
}
template <class T, int N> NdArray<T, N> vstack(T a, const NdArray<T, N>& nda)
{
  return Mat::stack(a, nda, N == 1 ? -1 : -2);
}

template <class T, int N> NdArray<T, N> stack(const NdArray<T, N>& nda, T a, int axis)
{
  NdArray<T, N> right(nda.GetShape().RebuildWith(1), a);
  return MHelper::Get().Stack<T, N>(nda.Get(), right.Get(), axis);
}
template <class T, int> NdArray<T, 2> hstack(const NdArray<T, 1>& nda, T a)
{
  Shape<2> shp = nda.GetShape().Expand(1);
  return Mat::stack<T, 2>(nda.Reshape(shp), a, -1);
}
template <class T, int N> NdArray<T, N> hstack(const NdArray<T, N>& nda, T a)
{
  return Mat::stack(nda, a, -1);
}
template <class T, int N> NdArray<T, N> vstack(const NdArray<T, N>& nda, T a)
{
  return Mat::stack(nda, a, N == 1 ? -1 : -2);
}

}  // namespace Mat