#pragma once
#include "coptcpp.idl.h"
#include "mexpression.h"
#include "mfactory.h"
#include "mhelper.h"
#include "ndarray.h"

template <int N> class MVar;

template <int N> class MLinExpr {
public:
  MLinExpr(const Shape<N>& shp, double constant) : m_expr(MFactory::Get().CreateMLinExpr(shp.Get(), constant)) {}
  MLinExpr(const Shape<N>& shp, const Expr& expr) : m_expr(MFactory::Get().CreateMLinExpr(shp.Get(), expr.Get())) {}
  MLinExpr(const Shape<N>& shp, const MExpression& expr) : m_expr(MFactory::Get().CreateMLinExpr(shp.Get(), expr.Get()))
  {
  }

  MLinExpr(const Shape<N>& shp, const std::vector<Expr>& exprs) : m_expr(MFactory::Get().CreateMLinExpr(shp.Get(), 0.0))
  {
    for (size_t i = 0; i < shp.GetSize(); i++)
    {
      MExpression item(exprs[i]);
      m_expr->SetItem(i, item.Get());
    }
  }

  MLinExpr(const Shape<N>& shp, const std::vector<MExpression>& exprs)
    : m_expr(MFactory::Get().CreateMLinExpr(shp.Get(), 0.0))
  {
    for (size_t i = 0; i < shp.GetSize(); i++)
    {
      m_expr->SetItem(i, exprs[i].Get());
    }
  }

  MLinExpr(Copt::IMLinExpr<N>* expr) : m_expr(expr) {}

  int GetND() const
  {
    return m_expr->GetND();
  }

  size_t GetDim(int i) const
  {
    return m_expr->GetDim(i);
  }

  size_t GetSize() const
  {
    return m_expr->GetSize();
  }

  Shape<N> GetShape() const
  {
    return m_expr->GetShape();
  }

  void AddConstant(double constant)
  {
    m_expr->AddConstrant(constant);
  }

  template <class T> void AddConstant(const NdArray<T, N>& constants)
  {
    m_expr->AddConstrant(constants.Get());
  }

  template <class T> void SubConstant(const NdArray<T, N>& constants)
  {
    m_expr->SubConstrant(constants.Get());
  }

  void AddTerm(const Var& var, double coeff)
  {
    m_expr->AddTerm(var.Get(), coeff);
  }

  void AddTerms(const MVar<N>& vars, double mult = 1.0)
  {
    m_expr->AddTerms(vars.Get(), mult);
  }

  void AddTerms(const MVar<N>& vars, const NdArray<double, N>& coeffs)
  {
    m_expr->AddTerms(vars.Get(), coeffs.Get());
  }

  void AddExpr(const Expr& expr, double mult = 1.0)
  {
    m_expr->AddExpr(expr.Get(), mult);
  }

  void AddMExpr(const MExpression& expr, double mult = 1.0)
  {
    m_expr->AddMExpr(expr.Get(), mult);
  }

  void AddMLinExpr(const MLinExpr<N>& exprs, double mult = 1.0)
  {
    m_expr->AddMLinExpr(exprs.Get(), mult);
  }

  MLinExpr<N - 1> Diagonal(int offset, int axis1 = 0, int axis2 = 1) const
  {
    return MHelper::Get().Diagonal(Get(), offset, axis1, axis2);
  }

  MLinExpr<N + 1> Expand(int axis = 0) const
  {
    return MHelper::Get().Expand(Get(), axis);
  }

  MLinExpr<1> Flatten() const
  {
    return m_expr->Flatten();
  }

  template <int M> MLinExpr<M> Reshape(const Shape<M>& shp) const
  {
    auto ret = m_expr->Reshape(shp.Get());
    CHECKERROR(ret);
    return ret;
  }

  MLinExpr<N> Repeat(size_t repeats, int axis = 0) const
  {
    auto ret = m_expr->Repeat(repeats, axis);
    CHECKERROR(ret);
    return ret;
  }

  MLinExpr<N> RepeatBlock(size_t repeats, int axis = 0) const
  {
    auto ret = m_expr->RepeatBlock(repeats, axis);
    CHECKERROR(ret);
    return ret;
  }

  MLinExpr<N - 1> Squeeze(int axis = 0) const
  {
    return MHelper::Get().Squeeze(Get(), axis);
  }

  MLinExpr<N> Stack(const MLinExpr<N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MLinExpr<N> Stack(const MVar<N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MLinExpr<N> Stack(const NdArray<double, N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MLinExpr<0> Sum() const
  {
    return m_expr->Sum();
  }

  MLinExpr<N - 1> Sum(int axis) const
  {
    return MHelper::Get().Sum(Get(), axis);
  }

  MLinExpr<N> Transpose() const
  {
    return m_expr->Transpose();
  }

  MExpression Item(size_t idx = 0) const
  {
    return m_expr->Item(idx);
  }

  void SetItem(size_t idx, MExpression val)
  {
    m_expr->SetItem(idx, val);
  }

  MLinExpr<1> Pick(const NdArray<int, 1>& indexes) const
  {
    return m_expr->Pick(indexes.Get());
  }

  MLinExpr<1> Pick(const NdArray<int, 2>& idxrows) const
  {
    return m_expr->Pick(idxrows.Get());
  }

  void Clear() const
  {
    m_expr->Clear();
  }

  MLinExpr<N> Clone() const
  {
    return m_expr->Clone();
  }

  NdArray<double, N> Evaluate() const
  {
    auto nda = m_expr->Evaluate();
    CHECKERROR(m_expr);
    return nda;
  }

  std::string Represent(size_t maxlen = 512) const
  {
    return m_expr->Represent(maxlen);
  }

  Copt::IMLinExpr<N>* Get() const
  {
    return &(*m_expr);
  }

  MLinExpr<N - 1> operator[](int64_t idx) const
  {
    MLinExpr<N> ret = m_expr->Item(Mat::make_view(idx).Get());
    CHECKERROR(ret.Get());
    return ret.Squeeze(0);
  }

  MLinExpr<N> operator[](const View& view) const
  {
    auto ret = m_expr->Item(view.Get());
    CHECKERROR(ret);
    return ret;
  }

  void operator*=(double constant)
  {
    m_expr->iMultiply(constant);
  }

  /* MLinExpr + other */
  friend MLinExpr<N> operator+(const MLinExpr<N>& left, double a)
  {
    NdArray<double, 0> right(Shape<0>(), a);
    return BroadCastHelper::Get().PlusCast<double, N, 0, N>(left.Get(), right.Get());
  }
  friend MLinExpr<N> operator+(const MLinExpr<N>& left, const MExpression& expr)
  {
    MLinExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<N, 0, N>(left.Get(), right.Get());
  }

  template <class T, int M>
  friend MLinExpr<COPT_MAX(N, M)> operator+(const MLinExpr<N>& left, const NdArray<T, M>& right)
  {
    return BroadCastHelper::Get().PlusCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MLinExpr<COPT_MAX(N, M)> operator+(const MLinExpr<N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* other + MLinExpr */
  friend MLinExpr<N> operator+(double a, const MLinExpr<N>& right)
  {
    NdArray<double, 0> left(Shape<0>(), a);
    return BroadCastHelper::Get().PlusCast<double, 0, N, N>(left.Get(), right.Get());
  }
  friend MLinExpr<N> operator+(const MExpression& expr, const MLinExpr<N>& right)
  {
    MLinExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<0, N, N>(left.Get(), right.Get());
  }

  template <class T, int M>
  friend MLinExpr<COPT_MAX(N, M)> operator+(const NdArray<T, N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* MLinExpr - other */
  friend MLinExpr<N> operator-(const MLinExpr<N>& left, double a)
  {
    NdArray<double, 0> right(Shape<0>(), a);
    return BroadCastHelper::Get().SubCast<double, N, 0, N>(left.Get(), right.Get());
  }
  friend MLinExpr<N> operator-(const MLinExpr<N>& left, const MExpression& expr)
  {
    MLinExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<N, 0, N>(left.Get(), right.Get());
  }

  template <class T, int M>
  friend MLinExpr<COPT_MAX(N, M)> operator-(const MLinExpr<N>& left, const NdArray<T, M>& right)
  {
    return BroadCastHelper::Get().SubCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MLinExpr<COPT_MAX(N, M)> operator-(const MLinExpr<N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* other - MLinExpr */
  friend MLinExpr<N> operator-(double a, const MLinExpr<N>& right)
  {
    NdArray<double, 0> left(Shape<0>(), a);
    return BroadCastHelper::Get().SubCast<double, 0, N, N>(left.Get(), right.Get());
  }
  friend MLinExpr<N> operator-(const MExpression& expr, const MLinExpr<N>& right)
  {
    MLinExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<0, N, N>(left.Get(), right.Get());
  }

  template <class T, int M>
  friend MLinExpr<COPT_MAX(N, M)> operator-(const NdArray<T, N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* MLinExpr * other */
  friend MLinExpr<N> operator*(const MLinExpr<N>& left, double a)
  {
    NdArray<double, 0> right(Shape<0>(), a);
    return BroadCastHelper::Get().DotCast<double, N, 0, N>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MLinExpr<COPT_MAX(N, M)> operator*(const MLinExpr<N>& left, const NdArray<T, M>& right)
  {
    return BroadCastHelper::Get().DotCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* other * MLinExpr */
  friend MLinExpr<N> operator*(double a, const MLinExpr<N>& right)
  {
    NdArray<double, 0> left(Shape<0>(), a);
    return BroadCastHelper::Get().DotCast<double, 0, N, N>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MLinExpr<COPT_MAX(N, M)> operator*(const NdArray<T, N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().DotCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  friend std::ostream& operator<<(std::ostream& out, const MLinExpr& expr)
  {
    out << "  CoptCpp.MLinExpr shape=" << expr.GetShape() << "\n";
    out << expr.Represent();
    return out;
  }

private:
  std::shared_ptr<Copt::IMLinExpr<N>> m_expr;
};
