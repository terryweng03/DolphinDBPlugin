#pragma once
#include "coptcpp.idl.h"
#include "mfactory.h"
#include "mhelper.h"
#include "mexpression.h"
#include "mqexpression.h"
#include "mvar.h"
#include "ndarray.h"

template <int N> class MQuadExpr {
public:
  MQuadExpr(const Shape<N>& shp, double constant) : m_qexpr(MFactory::Get().CreateMQuadExpr(shp.Get(), constant)) {}
  MQuadExpr(const Shape<N>& shp, const QuadExpr& expr) : m_qexpr(MFactory::Get().CreateMQuadExpr(shp.Get(), expr.Get()))
  {
  }
  MQuadExpr(const Shape<N>& shp, const MQExpression& expr)
    : m_qexpr(MFactory::Get().CreateMQuadExpr(shp.Get(), expr.Get()))
  {
  }

  MQuadExpr(const Shape<N>& shp, const std::vector<QuadExpr>& exprs)
    : m_qexpr(MFactory::Get().CreateMQuadExpr(shp.Get(), 0.0))
  {
    for (size_t i = 0; i < shp.GetSize(); i++)
    {
      MQExpression item(exprs[i]);
      m_qexpr->SetItem(i, item.Get());
    }
  }

  MQuadExpr(const Shape<N>& shp, const std::vector<MQExpression>& exprs)
    : m_qexpr(MFactory::Get().CreateMQuadExpr(shp.Get(), 0.0))
  {
    for (size_t i = 0; i < shp.GetSize(); i++)
    {
      m_qexpr->SetItem(i, exprs[i].Get());
    }
  }

  MQuadExpr(Copt::IMQuadExpr<N>* expr) : m_qexpr(expr) {}

  int GetND() const
  {
    return m_qexpr->GetND();
  }

  size_t GetSize() const
  {
    return m_qexpr->GetSize();
  }

  size_t GetDim(int i) const
  {
    return m_qexpr->GetDim(i);
  }

  Shape<N> GetShape() const
  {
    return m_qexpr->GetShape();
  }

  void AddConstant(double constant)
  {
    m_qexpr->AddConstrant(constant);
  }

  template <class T> void AddConstant(const NdArray<T, N>& constants)
  {
    m_qexpr->AddConstrant(constants.Get());
  }

  template <class T> void SubConstant(const NdArray<T, N>& constants)
  {
    m_qexpr->SubConstrant(constants.Get());
  }

  void AddTerm(const Var& var, double coeff)
  {
    m_qexpr->AddTerm(var.Get(), coeff);
  }

  void AddTerm(const Var& var1, const Var& var2, double coeff)
  {
    m_qexpr->AddTerm(var1.Get(), var2.Get(), coeff);
  }

  void AddTerms(const MVar<N>& vars, double mult)
  {
    m_qexpr->AddTerms(vars.Get(), mult);
  }

  void AddTerms(const MVar<N>& vars, const NdArray<double, N>& coeffs)
  {
    m_qexpr->AddTerms(vars.Get(), coeffs.Get());
  }

  void AddExpr(const Expr& expr, double mult = 1.0)
  {
    m_qexpr->AddExpr(expr.Get(), mult);
  }

  void AddQuadExpr(const QuadExpr& expr, double mult = 1.0)
  {
    m_qexpr->AddQuadExpr(expr.Get(), mult);
  }

  void AddMExpr(const MExpression& expr, double mult = 1.0)
  {
    m_qexpr->AddMExpr(expr.Get(), mult);
  }

  void AddMQExpr(const MQExpression& expr, double mult = 1.0)
  {
    m_qexpr->AddMQExpr(expr.Get(), mult);
  }

  void AddMLinExpr(const MLinExpr<N>& exprs, double mult = 1.0)
  {
    m_qexpr->AddMLinExpr(exprs.Get(), mult);
  }

  void AddMQuadExpr(const MQuadExpr<N>& exprs, double mult = 1.0)
  {
    m_qexpr->AddMQuadExpr(exprs.Get(), mult);
  }

  MQuadExpr<N - 1> Diagonal(int offset, int axis1 = 0, int axis2 = 1) const
  {
    return MHelper::Get().Diagonal(Get(), offset, axis1, axis2);
  }

  MQuadExpr<N + 1> Expand(int axis = 0) const
  {
    return MHelper::Get().Expand(Get(), axis);
  }

  MQuadExpr<1> Flatten() const
  {
    return m_qexpr->Flatten();
  }

  template <int M> MQuadExpr<M> Reshape(const Shape<M>& shp) const
  {
    auto ret = m_qexpr->Reshape(shp.Get());
    CHECKERROR(ret);
    return ret;
  }

  MQuadExpr<N> Repeat(size_t repeats, int axis = 0) const
  {
    auto ret = m_qexpr->Repeat(repeats, axis);
    CHECKERROR(ret);
    return ret;
  }

  MQuadExpr<N> RepeatBlock(size_t repeats, int axis = 0) const
  {
    auto ret = m_qexpr->RepeatBlock(repeats, axis);
    CHECKERROR(ret);
    return ret;
  }

  MQuadExpr<N - 1> Squeeze(int axis = 0) const
  {
    return MHelper::Get().Squeeze(Get(), axis);
  }

  MQuadExpr<N> Stack(const MQuadExpr<N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MQuadExpr<N> Stack(const MLinExpr<N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MQuadExpr<N> Stack(const MVar<N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MQuadExpr<N> Stack(const NdArray<double, N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MQuadExpr<0> Sum() const
  {
    return m_qexpr->Sum();
  }

  MQuadExpr<N - 1> Sum(int axis) const
  {
    return MHelper::Get().Sum(Get(), axis);
  }

  MQuadExpr<N> Transpose() const
  {
    return m_qexpr->Transpose();
  }

  MQExpression Item(size_t idx = 0) const
  {
    return m_qexpr->Item(idx);
  }

  void SetItem(size_t idx, const MQExpression& expr)
  {
    m_qexpr->SetItem(idx, expr.Get());
  }

  MQuadExpr<1> Pick(const NdArray<int, 1>& indexes) const
  {
    return m_qexpr->Pick(indexes.Get());
  }

  MQuadExpr<1> Pick(const NdArray<int, 2>& idxrows) const
  {
    return m_qexpr->Pick(idxrows.Get());
  }

  void Clear() const
  {
    m_qexpr->Clear();
  }

  MQuadExpr<N> Clone() const
  {
    return m_qexpr->Clone();
  }

  NdArray<double, N> Evaluate() const
  {
    NdArray<double, N> nda = m_qexpr->Evaluate();
    CHECKERROR(m_qexpr);
    return nda;
  }

  std::string Represent(size_t maxlen = 512) const
  {
    return m_qexpr->Represent(maxlen);
  }

  Copt::IMQuadExpr<N>* Get() const
  {
    return &(*m_qexpr);
  }

  MQuadExpr<N - 1> operator[](int64_t idx) const
  {
    MQuadExpr<N> ret = m_qexpr->Item(Mat::make_view(idx).Get());
    CHECKERROR(ret.Get());
    return ret.Squeeze(0);
  }

  MQuadExpr<N> operator[](const View& view) const
  {
    auto ret = m_qexpr->Item(view.Get());
    CHECKERROR(ret);
    return ret;
  }

  void operator*=(double constant)
  {
    m_qexpr->iMultiply(constant);
  }

  /* MQuadExpr + other */
  friend MQuadExpr<N> operator+(const MQuadExpr<N>& left, double a)
  {
    NdArray<double, 0> right(Shape<0>(), a);
    return BroadCastHelper::Get().PlusCast<double, N, 0, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator+(const MQuadExpr<N>& left, const Var& var)
  {
    MVar<0> right(Shape<0>(), var);
    return BroadCastHelper::Get().PlusCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator+(const MQuadExpr<N>& left, const MExpression& expr)
  {
    MLinExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator+(const MQuadExpr<N>& left, const MQExpression& expr)
  {
    MQuadExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<N, 0, N>(left.Get(), right.Get());
  }

  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator+(const MQuadExpr<N>& left, const MQuadExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator+(const MQuadExpr<N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator+(const MQuadExpr<N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MQuadExpr<COPT_MAX(N, M)> operator+(const MQuadExpr<N>& left, const NdArray<T, M>& right)
  {
    return BroadCastHelper::Get().PlusCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* other + MQuadExpr */
  friend MQuadExpr<N> operator+(double a, const MQuadExpr<N>& right)
  {
    NdArray<double, 0> left(Shape<0>(), a);
    return BroadCastHelper::Get().PlusCast<double, 0, N, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator+(const Var& var, const MQuadExpr<N>& right)
  {
    MVar<0> left(Shape<0>(), var);
    return BroadCastHelper::Get().PlusCast<0, N, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator+(const MExpression& expr, const MQuadExpr<N>& right)
  {
    MLinExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<0, N, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator+(const MQExpression& expr, const MQuadExpr<N>& right)
  {
    MQuadExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<0, N, N>(left.Get(), right.Get());
  }

  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator+(const MLinExpr<N>& left, const MQuadExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator+(const MVar<N>& left, const MQuadExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MQuadExpr<COPT_MAX(N, M)> operator+(const NdArray<T, N>& left, const MQuadExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* MQuadExpr - other */
  friend MQuadExpr<N> operator-(const MQuadExpr<N>& left, double a)
  {
    NdArray<double, 0> right(Shape<0>(), a);
    return BroadCastHelper::Get().SubCast<double, N, 0, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator-(const MQuadExpr<N>& left, const Var& var)
  {
    MVar<0> right(Shape<0>(), var);
    return BroadCastHelper::Get().SubCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator-(const MQuadExpr<N>& left, const MExpression& expr)
  {
    MLinExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator-(const MQuadExpr<N>& left, const MQExpression& expr)
  {
    MQuadExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<N, 0, N>(left.Get(), right.Get());
  }

  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator-(const MQuadExpr<N>& left, const MQuadExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator-(const MQuadExpr<N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator-(const MQuadExpr<N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MQuadExpr<COPT_MAX(N, M)> operator-(const MQuadExpr<N>& left, const NdArray<T, M>& right)
  {
    return BroadCastHelper::Get().SubCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* other - MQuadExpr */
  friend MQuadExpr<N> operator-(double a, const MQuadExpr<N>& right)
  {
    NdArray<double, 0> left(Shape<0>(), a);
    return BroadCastHelper::Get().SubCast<double, 0, N, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator-(const Var& var, const MQuadExpr<N>& right)
  {
    MVar<0> left(Shape<0>(), var);
    return BroadCastHelper::Get().SubCast<0, N, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator-(const MExpression& expr, const MQuadExpr<N>& right)
  {
    MLinExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<0, N, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator-(const MQExpression& expr, const MQuadExpr<N>& right)
  {
    MQuadExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<0, N, N>(left.Get(), right.Get());
  }

  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator-(const MLinExpr<N>& left, const MQuadExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator-(const MVar<N>& left, const MQuadExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MQuadExpr<COPT_MAX(N, M)> operator-(const NdArray<T, N>& left, const MQuadExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* MQuadExpr * other */
  friend MQuadExpr<N> operator*(const MQuadExpr<N>& left, double a)
  {
    NdArray<double, 0> right(Shape<0>(), a);
    return BroadCastHelper::Get().DotCast<double, N, 0, N>(left.Get(), right.Get());
  }
  friend MQuadExpr<N> operator*(double a, const MQuadExpr<N>& right)
  {
    NdArray<double, 0> left(Shape<0>(), a);
    return BroadCastHelper::Get().DotCast<double, 0, N, N>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MQuadExpr<COPT_MAX(N, M)> operator*(const MQuadExpr<N>& left, const NdArray<T, M>& right)
  {
    return BroadCastHelper::Get().DotCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MQuadExpr<COPT_MAX(M, N)> operator*(const NdArray<T, M>& left, const MQuadExpr<N>& right)
  {
    return BroadCastHelper::Get().DotCast<T, M, N, COPT_MAX(M, N)>(left.Get(), right.Get());
  }

  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator*(const MVar<N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().DotCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator*(const MVar<N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().DotCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator*(const MLinExpr<N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().DotCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MQuadExpr<COPT_MAX(N, M)> operator*(const MLinExpr<N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().DotCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  friend std::ostream& operator<<(std::ostream& out, const MQuadExpr& qexpr)
  {
    out << "  CoptCpp.MQuadExpr shape=" << qexpr.GetShape() << "\n";
    out << qexpr.Represent();
    return out;
  }

private:
  std::shared_ptr<Copt::IMQuadExpr<N>> m_qexpr;
};
