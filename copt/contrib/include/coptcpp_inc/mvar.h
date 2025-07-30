#pragma once
#include "coptcpp.idl.h"
#include "mfactory.h"
#include "mhelper.h"
#include "mlinexpr.h"
#include "ndarray.h"
#include "var.h"

template <int N> class MQuadExpr;

template <int N> class MVar {
public:
  MVar(const Shape<N>& shp, const Var& var) : m_var(MFactory::Get().CreateMVar(shp.Get(), var.Get())) {}
  MVar(const Shape<N>& shp, const VarArray& vars) : m_var(MFactory::Get().CreateMVar(shp.Get(), vars.Get())) {}
  MVar(Copt::IMVar<N>* var) : m_var(var) {}

  int GetND() const
  {
    return m_var->GetND();
  }

  size_t GetDim(int i) const
  {
    return m_var->GetDim(i);
  }

  size_t GetSize() const
  {
    return m_var->GetSize();
  }

  Shape<N> GetShape() const
  {
    return m_var->GetShape();
  }

  NdArray<int, N> GetBasis() const
  {
    return m_var->GetBasis();
  }

  NdArray<int, N> GetIdx() const
  {
    return m_var->GetIdx();
  }

  NdArray<int, N> GetLowerIIS() const
  {
    return m_var->GetLowerIIS();
  }

  NdArray<int, N> GetUpperIIS() const
  {
    return m_var->GetUpperIIS();
  }

  NdArray<char, N> GetType() const
  {
    return m_var->GetType();
  }

  NdArray<double, N> Get(const char* szInfo) const
  {
    return m_var->Get(szInfo);
  }

  void Set(const char* szInfo, double val) const
  {
    m_var->Set(szInfo, val);
  }

  void Set(const char* szInfo, const NdArray<double, N>& vals) const
  {
    m_var->Set(szInfo, vals.Get());
  }

  MVar<N - 1> Diagonal(int offset, int axis1 = 0, int axis2 = 1) const
  {
    return MHelper::Get().Diagonal(Get(), offset, axis1, axis2);
  }

  MVar<N + 1> Expand(int axis = 0) const
  {
    return MHelper::Get().Expand(Get(), axis);
  }

  MVar<1> Flatten() const
  {
    return m_var->Flatten();
  }

  template <int M> MVar<M> Reshape(const Shape<M>& shp) const
  {
    auto ret = m_var->Reshape(shp.Get());
    CHECKERROR(ret);
    return ret;
  }

  MVar<N> Repeat(size_t repeats, int axis = 0) const
  {
    auto ret = m_var->Repeat(repeats, axis);
    CHECKERROR(ret);
    return ret;
  }

  MVar<N> RepeatBlock(size_t repeats, int axis = 0) const
  {
    auto ret = m_var->RepeatBlock(repeats, axis);
    CHECKERROR(ret);
    return ret;
  }

  MVar<N - 1> Squeeze(int axis = 0) const
  {
    return MHelper::Get().Squeeze(Get(), axis);
  }

  MVar<N> Stack(const MVar<N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MLinExpr<0> Sum() const
  {
    return m_var->Sum();
  }

  MLinExpr<N - 1> Sum(int axis) const
  {
    return MHelper::Get().Sum(Get(), axis);
  }

  MVar<N> Transpose() const
  {
    return m_var->Transpose();
  }

  Var Item(size_t idx = 0) const
  {
    return m_var->Item(idx);
  }

  void SetItem(size_t idx, Var val)
  {
    m_var->SetItem(idx, val);
  }

  MVar<1> Pick(const NdArray<int, 1>& indexes) const
  {
    return m_var->Pick(indexes.Get());
  }

  MVar<1> Pick(const NdArray<int, 2>& idxrows) const
  {
    return m_var->Pick(idxrows.Get());
  }

  MVar<N> Clone() const
  {
    return m_var->Clone();
  }

  std::string Represent(size_t maxlen = 512) const
  {
    return m_var->Represent(maxlen);
  }

  Copt::IMVar<N>* Get() const
  {
    return &(*m_var);
  }

  MVar<N - 1> operator[](int64_t idx) const
  {
    MVar<N> ret = m_var->Item(Mat::make_view(idx).Get());
    CHECKERROR(ret.Get());
    return ret.Squeeze(0);
  }

  MVar<N> operator[](const View& view) const
  {
    auto ret = m_var->Item(view.Get());
    CHECKERROR(ret);
    return ret;
  }

  /* MVar + other */
  friend MLinExpr<N> operator+(const MVar<N>& left, double a)
  {
    NdArray<double, 0> right(Shape<0>(), a);
    return BroadCastHelper::Get().PlusCast<double, N, 0, N>(left.Get(), right.Get());
  }
  friend MLinExpr<N> operator+(const MVar<N>& left, const MExpression& expr)
  {
    MLinExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<N, 0, N>(left.Get(), right.Get());
  }

  template <int M> friend MLinExpr<COPT_MAX(N, M)> operator+(const MVar<N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MLinExpr<COPT_MAX(N, M)> operator+(const MVar<N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <class T, int M> friend MLinExpr<COPT_MAX(N, M)> operator+(const MVar<N>& left, const NdArray<T, M>& right)
  {
    return BroadCastHelper::Get().PlusCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* other + MVar */
  friend MLinExpr<N> operator+(double a, const MVar<N>& right)
  {
    NdArray<double, 0> left(Shape<0>(), a);
    return BroadCastHelper::Get().PlusCast<double, 0, N, N>(left.Get(), right.Get());
  }
  friend MLinExpr<N> operator+(const MExpression& expr, const MVar<N>& right)
  {
    MLinExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<0, N, N>(left.Get(), right.Get());
  }

  template <class T, int M> friend MLinExpr<COPT_MAX(N, M)> operator+(const NdArray<T, N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MLinExpr<COPT_MAX(N, M)> operator+(const MLinExpr<N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* MVar - other */
  friend MLinExpr<N> operator-(const MVar<N>& left, double a)
  {
    NdArray<double, 0> right(Shape<0>(), a);
    return BroadCastHelper::Get().SubCast<double, N, 0, N>(left.Get(), right.Get());
  }
  friend MLinExpr<N> operator-(const MVar<N>& left, const Var& var)
  {
    MVar<0> right(Shape<0>(), var);
    return BroadCastHelper::Get().SubCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MLinExpr<N> operator-(const MVar<N>& left, const MExpression& expr)
  {
    MLinExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<N, 0, N>(left.Get(), right.Get());
  }

  template <int M> friend MLinExpr<COPT_MAX(N, M)> operator-(const MVar<N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MLinExpr<COPT_MAX(N, M)> operator-(const MVar<N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <class T, int M> friend MLinExpr<COPT_MAX(N, M)> operator-(const MVar<N>& left, const NdArray<T, M>& right)
  {
    return BroadCastHelper::Get().SubCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* other - MVar */
  friend MLinExpr<N> operator-(double a, const MVar<N>& right)
  {
    NdArray<double, 0> left(Shape<0>(), a);
    return BroadCastHelper::Get().SubCast<double, 0, N, N>(left.Get(), right.Get());
  }
  friend MLinExpr<N> operator-(const MExpression& expr, const MVar<N>& right)
  {
    MLinExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<double, 0, N, N>(left.Get(), right.Get());
  }

  template <class T, int M> friend MLinExpr<COPT_MAX(N, M)> operator-(const NdArray<T, N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().SubCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MLinExpr<COPT_MAX(N, M)> operator-(const MLinExpr<N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* MVar/MLinExpr * other */
  friend MLinExpr<N> operator*(const MVar<N>& left, double a)
  {
    NdArray<double, 0> right(Shape<0>(), a);
    return BroadCastHelper::Get().DotCast<double, N, 0, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator*(const MVar<N>& left, const Var& var)
  {
    MVar<0> right(Shape<0>(), var);
    return BroadCastHelper::Get().DotCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator*(const MVar<N>& left, const MExpression& expr)
  {
    MLinExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().DotCast<N, 0, N>(left.Get(), right.Get());
  }
  template <class T, int M> friend MLinExpr<COPT_MAX(N, M)> operator*(const MVar<N>& left, const NdArray<T, M>& right)
  {
    return BroadCastHelper::Get().DotCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  friend MQuadExpr<N> operator*(const MLinExpr<N>& left, const Var& var)
  {
    MVar<0> right(Shape<0>(), var);
    return BroadCastHelper::Get().DotCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator*(const MLinExpr<N>& left, const MExpression& expr)
  {
    MLinExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().DotCast<N, 0, N>(left.Get(), right.Get());
  }

  /* other * MVar/MLinExpr */
  friend MLinExpr<N> operator*(double a, const MVar<N>& right)
  {
    NdArray<double, 0> left(Shape<0>(), a);
    return BroadCastHelper::Get().DotCast<double, 0, N, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator*(const Var& var, const MVar<N>& right)
  {
    MVar<0> left(Shape<0>(), var);
    return BroadCastHelper::Get().DotCast<double, 0, N, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator*(const MExpression& expr, const MVar<N>& right)
  {
    MLinExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().DotCast<double, 0, N, N>(left.Get(), right.Get());
  }
  template <class T, int M> friend MLinExpr<COPT_MAX(N, M)> operator*(const NdArray<T, N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().DotCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  friend MQuadExpr<N> operator*(const Var& var, const MLinExpr<N>& right)
  {
    MVar<0> left(Shape<0>(), var);
    return BroadCastHelper::Get().DotCast<0, N, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator*(const MExpression& expr, const MLinExpr<N>& right)
  {
    MLinExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().DotCast<0, N, N>(left.Get(), right.Get());
  }

  friend std::ostream& operator<<(std::ostream& out, const MVar& var)
  {
    out << "  CoptCpp.MVar shape=" << var.GetShape() << "\n";
    out << var.Represent();
    return out;
  }

private:
  std::shared_ptr<Copt::IMVar<N>> m_var;
};

namespace Mat {

static COPT_UNUSED MVar<1> repeat(const Var& var, size_t repeats)
{
  return MHelper::Get().Repeat(var.Get(), repeats);
}

template <int N> MVar<N> stack(const MVar<N>& vars1, const MVar<N>& vars2, int axis)
{
  return MHelper::Get().Stack<N>(vars1.Get(), vars2.Get(), axis);
}
template <int> MVar<2> hstack(const MVar<1>& vars1, const MVar<1>& vars2)
{
  Shape<2> shp1 = vars1.GetShape().Expand(1);
  Shape<2> shp2 = vars2.GetShape().Expand(1);
  return Mat::stack<2>(vars1.Reshape(shp1), vars2.Reshape(shp2), -1);
}
template <int N> MVar<N> hstack(const MVar<N>& vars1, const MVar<N>& vars2)
{
  return Mat::stack(vars1, vars2, -1);
}
template <int N> MVar<N> vstack(const MVar<N>& vars1, const MVar<N>& vars2)
{
  return Mat::stack(vars1, vars2, N == 1 ? -1 : -2);
}

template <int N> MVar<N> stack(const Var& var, const MVar<N>& vars, int axis)
{
  MVar<N> left(vars.GetShape().RebuildWith(1), var);
  return MHelper::Get().Stack<N>(left.Get(), vars.Get(), axis);
}
template <int> MVar<2> hstack(const Var& var, const MVar<1>& vars)
{
  Shape<2> shp = vars.GetShape().Expand(1);
  return Mat::stack<2>(var, vars.Reshape(shp), -1);
}
template <int N> MVar<N> hstack(const Var& var, const MVar<N>& vars)
{
  return Mat::stack(var, vars, -1);
}
template <int N> MVar<N> vstack(const Var& var, const MVar<N>& vars)
{
  return Mat::stack(var, vars, N == 1 ? -1 : -2);
}

template <int N> MVar<N> stack(const MVar<N>& vars, const Var& var, int axis)
{
  MVar<N> right(vars.GetShape().RebuildWith(1), var);
  return MHelper::Get().Stack<N>(vars.Get(), right.Get(), axis);
}
template <int> MVar<2> hstack(const MVar<1>& vars, const Var& var)
{
  Shape<2> shp = vars.GetShape().Expand(1);
  return Mat::stack<2>(vars.Reshape(shp), var, -1);
}
template <int N> MVar<N> hstack(const MVar<N>& vars, const Var& var)
{
  return Mat::stack(vars, var, -1);
}
template <int N> MVar<N> vstack(const MVar<N>& vars, const Var& var)
{
  return Mat::stack(vars, var, N == 1 ? -1 : -2);
}

}  // namespace Mat