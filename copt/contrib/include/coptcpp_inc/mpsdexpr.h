#pragma once
#include "coptcpp.idl.h"
#include "mfactory.h"
#include "mhelper.h"
#include "mexpression.h"
#include "mvar.h"
#include "ndarray.h"
#include "psdexpr.h"

template <int N> class MPsdExpr {
public:
  MPsdExpr(const Shape<N>& shp, double constant) : m_psdexpr(MFactory::Get().CreateMPsdExpr(shp.Get(), constant)) {}
  MPsdExpr(const Shape<N>& shp, const PsdExpr& expr) : m_psdexpr(MFactory::Get().CreateMPsdExpr(shp.Get(), expr.Get()))
  {
  }
  MPsdExpr(const Shape<N>& shp, const MExpression& expr)
    : m_psdexpr(MFactory::Get().CreateMPsdExpr(shp.Get(), expr.Get()))
  {
  }

  MPsdExpr(const Shape<N>& shp, const std::vector<PsdExpr>& exprs)
    : m_psdexpr(MFactory::Get().CreateMPsdExpr(shp.Get(), 0.0))
  {
    for (size_t i = 0; i < shp.GetSize(); i++)
    {
      m_psdexpr->SetItem(i, exprs[i].Get());
    }
  }

  MPsdExpr(Copt::IMPsdExpr<N>* expr) : m_psdexpr(expr) {}

  int GetND() const
  {
    return m_psdexpr->GetND();
  }

  size_t GetSize() const
  {
    return m_psdexpr->GetSize();
  }

  size_t GetDim(int i) const
  {
    return m_psdexpr->GetDim(i);
  }

  Shape<N> GetShape() const
  {
    return m_psdexpr->GetShape();
  }

  void AddConstant(double constant)
  {
    m_psdexpr->AddConstrant(constant);
  }

  template <class T> void AddConstant(const NdArray<T, N>& constants)
  {
    m_psdexpr->AddConstrant(constants.Get());
  }

  template <class T> void SubConstant(const NdArray<T, N>& constants)
  {
    m_psdexpr->SubConstrant(constants.Get());
  }

  void AddTerm(const Var& var, double coeff)
  {
    m_psdexpr->AddTerm(var.Get(), coeff);
  }

  void AddTerm(const PsdVar& var, const SymMatrix& mat)
  {
    m_psdexpr->AddTerm(var.Get(), mat.Get());
  }

  void AddTerm(const PsdVar& var, const SymMatExpr& expr)
  {
    m_psdexpr->AddTerm(var.Get(), expr.Get());
  }

  void AddTerms(const MVar<N>& vars, double mult)
  {
    m_psdexpr->AddTerms(vars.Get(), mult);
  }

  void AddTerms(const MVar<N>& vars, const NdArray<double, N>& coeffs)
  {
    m_psdexpr->AddTerms(vars.Get(), coeffs.Get());
  }

  void AddLinExpr(const Expr& expr, double mult = 1.0)
  {
    m_psdexpr->AddLinExpr(expr.Get(), mult);
  }

  void AddPsdExpr(const PsdExpr& expr, double mult = 1.0)
  {
    m_psdexpr->AddPsdExpr(expr.Get(), mult);
  }

  void AddMExpr(const MExpression& expr, double mult = 1.0)
  {
    m_psdexpr->AddMExpr(expr.Get(), mult);
  }

  void AddMLinExpr(const MLinExpr<N>& exprs, double mult = 1.0)
  {
    m_psdexpr->AddMLinExpr(exprs.Get(), mult);
  }

  void AddMPsdExpr(const MPsdExpr<N>& exprs, double mult = 1.0)
  {
    m_psdexpr->AddMPsdExpr(exprs.Get(), mult);
  }

  MPsdExpr<N - 1> Diagonal(int offset, int axis1 = 0, int axis2 = 1) const
  {
    return MHelper::Get().Diagonal(Get(), offset, axis1, axis2);
  }
  MPsdExpr<N + 1> Expand(int axis = 0) const
  {
    return MHelper::Get().Expand(Get(), axis);
  }

  MPsdExpr<1> Flatten() const
  {
    return m_psdexpr->Flatten();
  }

  template <int M> MPsdExpr<M> Reshape(const Shape<M>& shp) const
  {
    auto ret = m_psdexpr->Reshape(shp.Get());
    CHECKERROR(ret);
    return ret;
  }

  MPsdExpr<N> Repeat(size_t repeats, int axis = 0) const
  {
    auto ret = m_psdexpr->Repeat(repeats, axis);
    CHECKERROR(ret);
    return ret;
  }

  MPsdExpr<N> RepeatBlock(size_t repeats, int axis = 0) const
  {
    auto ret = m_psdexpr->RepeatBlock(repeats, axis);
    CHECKERROR(ret);
    return ret;
  }

  MPsdExpr<N - 1> Squeeze(int axis = 0) const
  {
    return MHelper::Get().Squeeze(Get(), axis);
  }

  MPsdExpr<N> Stack(const MPsdExpr<N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MPsdExpr<N> Stack(const MLinExpr<N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MPsdExpr<N> Stack(const MVar<N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MPsdExpr<N> Stack(const NdArray<double, N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MPsdExpr<0> Sum() const
  {
    return m_psdexpr->Sum();
  }

  MPsdExpr<N - 1> Sum(int axis) const
  {
    return MHelper::Get().Sum(Get(), axis);
  }

  MPsdExpr<N> Transpose() const
  {
    return m_psdexpr->Transpose();
  }

  PsdExpr Item(size_t idx = 0) const
  {
    return m_psdexpr->Item(idx);
  }

  void SetItem(size_t idx, const MExpression& expr)
  {
    m_psdexpr->SetItem(idx, expr.Get());
  }

  void SetItem(size_t idx, const PsdExpr& expr)
  {
    m_psdexpr->SetItem(idx, expr.Get());
  }

  MPsdExpr<1> Pick(const NdArray<int, 1>& indexes) const
  {
    return m_psdexpr->Pick(indexes.Get());
  }

  MPsdExpr<1> Pick(const NdArray<int, 2>& idxrows) const
  {
    return m_psdexpr->Pick(idxrows.Get());
  }

  void Clear() const
  {
    m_psdexpr->Clear();
  }

  MPsdExpr<N> Clone() const
  {
    return m_psdexpr->Clone();
  }

  NdArray<double, N> Evaluate() const
  {
    auto nda = m_psdexpr->Evaluate();
    CHECKERROR(m_psdexpr);
    return nda;
  }

  std::string Represent(size_t maxlen = 512) const
  {
    return m_psdexpr->Represent(maxlen);
  }

  Copt::IMPsdExpr<N>* Get() const
  {
    return &(*m_psdexpr);
  }

  MPsdExpr<N - 1> operator[](int64_t idx) const
  {
    MPsdExpr<N> ret = m_psdexpr->Item(Mat::make_view(idx).Get());
    CHECKERROR(ret.Get());
    return ret.Squeeze(0);
  }

  MPsdExpr<N> operator[](const View& view) const
  {
    auto ret = m_psdexpr->Item(view.Get());
    CHECKERROR(ret);
    return ret;
  }

  void operator*=(double constant)
  {
    m_psdexpr->iMultiply(constant);
  }

  /* MPsdExpr + other */
  friend MPsdExpr<N> operator+(const MPsdExpr<N>& left, double a)
  {
    NdArray<double, 0> right(Shape<0>(), a);
    return BroadCastHelper::Get().PlusCast<double, N, 0, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator+(const MPsdExpr<N>& left, const Var& var)
  {
    MVar<0> right(Shape<0>(), var);
    return BroadCastHelper::Get().PlusCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator+(const MPsdExpr<N>& left, const Expr& expr)
  {
    MLinExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator+(const MPsdExpr<N>& left, const MExpression& expr)
  {
    MLinExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator+(const MPsdExpr<N>& left, const PsdExpr& expr)
  {
    MPsdExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<N, 0, N>(left.Get(), right.Get());
  }

  template <int M> friend MPsdExpr<COPT_MAX(N, M)> operator+(const MPsdExpr<N>& left, const MPsdExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MPsdExpr<COPT_MAX(N, M)> operator+(const MPsdExpr<N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MPsdExpr<COPT_MAX(N, M)> operator+(const MPsdExpr<N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MPsdExpr<COPT_MAX(N, M)> operator+(const MPsdExpr<N>& left, const NdArray<T, M>& right)
  {
    return BroadCastHelper::Get().PlusCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* other + MPsdExpr */
  friend MPsdExpr<N> operator+(double a, const MPsdExpr<N>& right)
  {
    NdArray<double, 0> left(Shape<0>(), a);
    return BroadCastHelper::Get().PlusCast<double, 0, N, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator+(const Var& var, const MPsdExpr<N>& right)
  {
    MVar<0> left(Shape<0>(), var);
    return BroadCastHelper::Get().PlusCast<0, N, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator+(const Expr& expr, const MPsdExpr<N>& right)
  {
    MLinExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<0, N, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator+(const MExpression& expr, const MPsdExpr<N>& right)
  {
    MLinExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<0, N, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator+(const PsdExpr& expr, const MPsdExpr<N>& right)
  {
    MPsdExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().PlusCast<0, N, N>(left.Get(), right.Get());
  }

  template <int M> friend MPsdExpr<COPT_MAX(N, M)> operator+(const MLinExpr<N>& left, const MPsdExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MPsdExpr<COPT_MAX(N, M)> operator+(const MVar<N>& left, const MPsdExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MPsdExpr<COPT_MAX(N, M)> operator+(const NdArray<T, N>& left, const MPsdExpr<M>& right)
  {
    return BroadCastHelper::Get().PlusCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* MPsdExpr - other */
  friend MPsdExpr<N> operator-(const MPsdExpr<N>& left, double a)
  {
    NdArray<double, 0> right(Shape<0>(), a);
    return BroadCastHelper::Get().SubCast<double, N, 0, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator-(const MPsdExpr<N>& left, const Var& var)
  {
    MVar<0> right(Shape<0>(), var);
    return BroadCastHelper::Get().SubCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator-(const MPsdExpr<N>& left, const Expr& expr)
  {
    MLinExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator-(const MPsdExpr<N>& left, const MExpression& expr)
  {
    MLinExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<N, 0, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator-(const MPsdExpr<N>& left, const PsdExpr& expr)
  {
    MPsdExpr<0> right(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<N, 0, N>(left.Get(), right.Get());
  }

  template <int M> friend MPsdExpr<COPT_MAX(N, M)> operator-(const MPsdExpr<N>& left, const MPsdExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MPsdExpr<COPT_MAX(N, M)> operator-(const MPsdExpr<N>& left, const MLinExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MPsdExpr<COPT_MAX(N, M)> operator-(const MPsdExpr<N>& left, const MVar<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MPsdExpr<COPT_MAX(N, M)> operator-(const MPsdExpr<N>& left, const NdArray<T, M>& right)
  {
    return BroadCastHelper::Get().SubCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* other - MPsdExpr */
  friend MPsdExpr<N> operator-(double a, const MPsdExpr<N>& right)
  {
    NdArray<double, 0> left(Shape<0>(), a);
    return BroadCastHelper::Get().SubCast<double, 0, N, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator-(const Var& var, const MPsdExpr<N>& right)
  {
    MVar<0> left(Shape<0>(), var);
    return BroadCastHelper::Get().SubCast<0, N, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator-(const Expr& expr, const MPsdExpr<N>& right)
  {
    MLinExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<0, N, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator-(const MExpression& expr, const MPsdExpr<N>& right)
  {
    MLinExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<0, N, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator-(const PsdExpr& expr, const MPsdExpr<N>& right)
  {
    MPsdExpr<0> left(Shape<0>(), expr);
    return BroadCastHelper::Get().SubCast<0, N, N>(left.Get(), right.Get());
  }

  template <int M> friend MPsdExpr<COPT_MAX(N, M)> operator-(const MLinExpr<N>& left, const MPsdExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <int M> friend MPsdExpr<COPT_MAX(N, M)> operator-(const MVar<N>& left, const MPsdExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MPsdExpr<COPT_MAX(N, M)> operator-(const NdArray<T, N>& left, const MPsdExpr<M>& right)
  {
    return BroadCastHelper::Get().SubCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }

  /* MPsdExpr * other */
  friend MPsdExpr<N> operator*(const MPsdExpr<N>& left, double a)
  {
    NdArray<double, 0> right(Shape<0>(), a);
    return BroadCastHelper::Get().DotCast<double, N, 0, N>(left.Get(), right.Get());
  }
  friend MPsdExpr<N> operator*(double a, const MPsdExpr<N>& right)
  {
    NdArray<double, 0> left(Shape<0>(), a);
    return BroadCastHelper::Get().DotCast<double, 0, N, N>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MPsdExpr<COPT_MAX(N, M)> operator*(const MPsdExpr<N>& left, const NdArray<T, M>& right)
  {
    return BroadCastHelper::Get().DotCast<T, N, M, COPT_MAX(N, M)>(left.Get(), right.Get());
  }
  template <class T, int M>
  friend MPsdExpr<COPT_MAX(M, N)> operator*(const NdArray<T, M>& left, const MPsdExpr<N>& right)
  {
    return BroadCastHelper::Get().DotCast<T, M, N, COPT_MAX(M, N)>(left.Get(), right.Get());
  }

  friend std::ostream& operator<<(std::ostream& out, const MPsdExpr& qexpr)
  {
    out << "  CoptCpp.MPsdExpr shape=" << qexpr.GetShape() << "\n";
    out << qexpr.Represent();
    return out;
  }

private:
  std::shared_ptr<Copt::IMPsdExpr<N>> m_psdexpr;
};
