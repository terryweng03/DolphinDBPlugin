#pragma once
#include "coptcpp.idl.h"
#include "mfactory.h"
#include "mpsdexpr.h"

template <int N> class MPsdConstrBuilder {
public:
  MPsdConstrBuilder(const Shape<N>& shp) : m_builder(MFactory::Get().CreateMPsdConstrBuilder(shp.Get())) {}

  MPsdConstrBuilder(Copt::IMPsdConstrBuilder<N>* builder) : m_builder(builder) {}

  int GetND() const
  {
    return m_builder->GetND();
  }

  MPsdExpr<N> GetPsdExpr() const
  {
    return m_builder->GetPsdExpr();
  }

  char GetSense() const
  {
    return m_builder->GetSense();
  }

  double GetRange() const
  {
    return m_builder->GetRange();
  }

  MPsdConstrBuilder<1> Flatten() const
  {
    return m_builder->Flatten();
  }

  void SetRange(const MPsdExpr<N>& expr, double range)
  {
    m_builder->SetRange(expr.Get(), range);
  }

  void Set(const MPsdExpr<N>& expr, char sense, double rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs);
  }

  template <int M> void Set(const MPsdExpr<N>& expr, char sense, const MVar<M>& rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs.Get());
    CHECKERROR(m_builder);
  }

  template <int M> void Set(const MPsdExpr<N>& expr, char sense, const MLinExpr<M>& rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs.Get());
    CHECKERROR(m_builder);
  }

  template <int M> void Set(const MPsdExpr<N>& expr, char sense, const MPsdExpr<M>& rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs.Get());
    CHECKERROR(m_builder);
  }

  template <class T> void Set(const MPsdExpr<N>& expr, char sense, const NdArray<T, N>& rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs.Get());
    CHECKERROR(m_builder);
  }

  Copt::IMPsdConstrBuilder<N>* Get() const
  {
    return &(*m_builder);
  }

private:
  std::shared_ptr<Copt::IMPsdConstrBuilder<N>> m_builder;
};

/* MPsdConstrBuilder less-than operators */
template <int N> MPsdConstrBuilder<N> operator<=(const MPsdExpr<N>& left, double rhs)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, rhs);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator<=(const MPsdExpr<N>& left, const Var& var)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - var, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator<=(const MPsdExpr<N>& left, const Expr& expr)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator<=(const MPsdExpr<N>& left, const MExpression& expr)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator<=(const MPsdExpr<N>& left, const PsdExpr& expr)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MPsdConstrBuilder<N> operator<=(const MPsdExpr<N>& left, const NdArray<T, N>& rhs)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, rhs);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator<=(const MPsdExpr<N>& left, const MVar<M>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, right);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator<=(const MPsdExpr<N>& left, const MLinExpr<M>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, right);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator<=(const MPsdExpr<N>& left, const MPsdExpr<M>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, right);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator<=(const MLinExpr<M>& left, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_GREATER_EQUAL, left);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator<=(const MVar<M>& left, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_GREATER_EQUAL, left);
  return builder;
}

template <class T, int N> MPsdConstrBuilder<N> operator<=(const NdArray<T, N>& left, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_GREATER_EQUAL, left);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator<=(double a, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_GREATER_EQUAL, a);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator<=(const Var& var, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - var, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator<=(const Expr& expr, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator<=(const MExpression& expr, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator<=(const PsdExpr& expr, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

/* MPsdConstrBuilder greater-than operators */
template <int N> MPsdConstrBuilder<N> operator>=(const MPsdExpr<N>& left, double rhs)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, rhs);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator>=(const MPsdExpr<N>& left, const Var& var)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - var, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator>=(const MPsdExpr<N>& left, const Expr& expr)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator>=(const MPsdExpr<N>& left, const MExpression& expr)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator>=(const MPsdExpr<N>& left, const PsdExpr& expr)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MPsdConstrBuilder<N> operator>=(const MPsdExpr<N>& left, const NdArray<T, N>& rhs)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, rhs);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator>=(const MPsdExpr<N>& left, const MVar<M>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, right);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator>=(const MPsdExpr<N>& left, const MLinExpr<M>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, right);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator>=(const MPsdExpr<N>& left, const MPsdExpr<M>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, right);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator>=(const MLinExpr<M>& left, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_LESS_EQUAL, left);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator>=(const MVar<M>& left, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_LESS_EQUAL, left);
  return builder;
}

template <class T, int N> MPsdConstrBuilder<N> operator>=(const NdArray<T, N>& left, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_LESS_EQUAL, left);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator>=(double a, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_LESS_EQUAL, a);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator>=(const Var& var, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - var, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator>=(const Expr& expr, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator>=(const MExpression& expr, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator>=(const PsdExpr& expr, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

/* MPsdConstrBuilder equal operators */
template <int N> MPsdConstrBuilder<N> operator==(const MPsdExpr<N>& left, double rhs)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, rhs);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator==(const MPsdExpr<N>& left, const Var& var)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - var, COPT_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator==(const MPsdExpr<N>& left, const Expr& expr)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator==(const MPsdExpr<N>& left, const MExpression& expr)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator==(const MPsdExpr<N>& left, const PsdExpr& expr)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MPsdConstrBuilder<N> operator==(const MPsdExpr<N>& left, const NdArray<T, N>& rhs)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, rhs);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator==(const MPsdExpr<N>& left, const MVar<M>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, right);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator==(const MPsdExpr<N>& left, const MLinExpr<M>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, right);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator==(const MPsdExpr<N>& left, const MPsdExpr<M>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, right);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator==(const MLinExpr<M>& left, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_EQUAL, left);
  return builder;
}

template <int N, int M> MPsdConstrBuilder<N> operator==(const MVar<M>& left, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_EQUAL, left);
  return builder;
}

template <class T, int N> MPsdConstrBuilder<N> operator==(const NdArray<T, N>& left, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_EQUAL, left);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator==(double a, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_EQUAL, a);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator==(const Var& var, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - var, COPT_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator==(const Expr& expr, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator==(const MExpression& expr, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_EQUAL, 0.0);
  return builder;
}

template <int N> MPsdConstrBuilder<N> operator==(const PsdExpr& expr, const MPsdExpr<N>& right)
{
  MPsdConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_EQUAL, 0.0);
  return builder;
}