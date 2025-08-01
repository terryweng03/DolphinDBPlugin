#pragma once
#include "coptcpp.idl.h"
#include "mfactory.h"
#include "mlinexpr.h"
#include "mvar.h"

template <int N> class MConstrBuilder {
public:
  MConstrBuilder(const Shape<N>& shp) : m_builder(MFactory::Get().CreateMConstrBuilder(shp.Get())) {}

  MConstrBuilder(Copt::IMConstrBuilder<N>* builder) : m_builder(builder) {}

  int GetND() const
  {
    return m_builder->GetND();
  }

  MLinExpr<N> GetExpr() const
  {
    return m_builder->GetExpr();
  }

  double GetRange() const
  {
    return m_builder->GetRange();
  }

  char GetSense() const
  {
    return m_builder->GetSense();
  }

  MConstrBuilder<1> Flatten() const
  {
    return m_builder->Flatten();
  }

  void SetRange(const MLinExpr<N>& expr, double range)
  {
    m_builder->SetRange(expr.Get(), range);
  }

  void Set(const MLinExpr<N>& expr, char sense, double rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs);
  }

  template <int M> void Set(const MLinExpr<N>& expr, char sense, const MVar<M>& rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs.Get());
    CHECKERROR(m_builder);
  }

  template <int M> void Set(const MLinExpr<N>& expr, char sense, const MLinExpr<M>& rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs.Get());
    CHECKERROR(m_builder);
  }

  template <class T> void Set(const MLinExpr<N>& expr, char sense, const NdArray<T, N>& rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs.Get());
  }

  Copt::IMConstrBuilder<N>* Get() const
  {
    return &(*m_builder);
  }

private:
  std::shared_ptr<Copt::IMConstrBuilder<N>> m_builder;
};


/* MConstrBuilder less-than operators */
template <int N> MConstrBuilder<N> operator<=(const MLinExpr<N>& left, double rhs)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, rhs);
  return builder;
}

template <int N> MConstrBuilder<N> operator<=(const MLinExpr<N>& left, const MExpression& expr)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MConstrBuilder<N> operator<=(const MLinExpr<N>& left, const NdArray<T, N>& rhs)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, rhs);
  return builder;
}

template <int N, int M> MConstrBuilder<N> operator<=(const MLinExpr<N>& left, const MVar<M>& right)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, right);
  return builder;
}

template <int N, int M> MConstrBuilder<N> operator<=(const MLinExpr<N>& left, const MLinExpr<M>& right)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, right);
  return builder;
}

template <int N> MConstrBuilder<N> operator<=(const MVar<N>& left, double rhs)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - rhs, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N> MConstrBuilder<N> operator<=(const MVar<N>& left, const MExpression& expr)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MConstrBuilder<N> operator<=(const MVar<N>& left, const NdArray<T, N>& rhs)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - rhs, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N, int M> MConstrBuilder<N> operator<=(const MVar<N>& left, const MVar<M>& right)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - right, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N, int M> MConstrBuilder<N> operator<=(const MVar<M>& left, const MLinExpr<N>& right)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_GREATER_EQUAL, left);
  return builder;
}

template <class T, int N> MConstrBuilder<N> operator<=(const NdArray<T, N>& left, const MVar<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - left, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MConstrBuilder<N> operator<=(const NdArray<T, N>& left, const MLinExpr<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_GREATER_EQUAL, left);
  return builder;
}

template <int N> MConstrBuilder<N> operator<=(double a, const MVar<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - a, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N> MConstrBuilder<N> operator<=(const MExpression& expr, const MVar<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N> MConstrBuilder<N> operator<=(double a, const MLinExpr<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_GREATER_EQUAL, a);
  return builder;
}

template <int N> MConstrBuilder<N> operator<=(const MExpression& expr, const MLinExpr<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

/* MConstrBuilder greater-than operators */
template <int N> MConstrBuilder<N> operator>=(const MLinExpr<N>& left, double rhs)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, rhs);
  return builder;
}

template <int N> MConstrBuilder<N> operator>=(const MLinExpr<N>& left, const MExpression& expr)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MConstrBuilder<N> operator>=(const MLinExpr<N>& left, const NdArray<T, N>& rhs)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, rhs);
  return builder;
}

template <int N, int M> MConstrBuilder<N> operator>=(const MLinExpr<N>& left, const MVar<M>& right)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, right);
  return builder;
}

template <int N, int M> MConstrBuilder<N> operator>=(const MLinExpr<N>& left, const MLinExpr<M>& right)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, right);
  return builder;
}

template <int N> MConstrBuilder<N> operator>=(const MVar<N>& left, double rhs)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - rhs, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N> MConstrBuilder<N> operator>=(const MVar<N>& left, const MExpression& expr)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MConstrBuilder<N> operator>=(const MVar<N>& left, const NdArray<T, N>& rhs)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - rhs, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N, int M> MConstrBuilder<N> operator>=(const MVar<N>& left, const MVar<M>& right)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - right, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N, int M> MConstrBuilder<N> operator>=(const MVar<M>& left, const MLinExpr<N>& right)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_LESS_EQUAL, left);
  return builder;
}

template <class T, int N> MConstrBuilder<N> operator>=(const NdArray<T, N>& left, const MVar<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - left, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MConstrBuilder<N> operator>=(const NdArray<T, N>& left, const MLinExpr<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_LESS_EQUAL, left);
  return builder;
}

template <int N> MConstrBuilder<N> operator>=(double a, const MVar<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - a, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N> MConstrBuilder<N> operator>=(const MExpression& expr, const MVar<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N> MConstrBuilder<N> operator>=(double a, const MLinExpr<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_LESS_EQUAL, a);
  return builder;
}

template <int N> MConstrBuilder<N> operator>=(const MExpression& expr, const MLinExpr<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

/* MConstrBuilder equal operators */
template <int N> MConstrBuilder<N> operator==(const MLinExpr<N>& left, double rhs)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, rhs);
  return builder;
}

template <int N> MConstrBuilder<N> operator==(const MLinExpr<N>& left, const MExpression& expr)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MConstrBuilder<N> operator==(const MLinExpr<N>& left, const NdArray<T, N>& rhs)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, rhs);
  return builder;
}

template <int N, int M> MConstrBuilder<N> operator==(const MLinExpr<N>& left, const MVar<M>& right)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, right);
  return builder;
}

template <int N, int M> MConstrBuilder<N> operator==(const MLinExpr<N>& left, const MLinExpr<M>& right)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, right);
  return builder;
}

template <int N> MConstrBuilder<N> operator==(const MVar<N>& left, double rhs)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - rhs, COPT_EQUAL, 0.0);
  return builder;
}

template <int N> MConstrBuilder<N> operator==(const MVar<N>& left, const MExpression& expr)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MConstrBuilder<N> operator==(const MVar<N>& left, const NdArray<T, N>& rhs)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - rhs, COPT_EQUAL, 0.0);
  return builder;
}

template <int N, int M> MConstrBuilder<N> operator==(const MVar<N>& left, const MVar<M>& right)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - right, COPT_EQUAL, 0.0);
  return builder;
}

template <int N, int M> MConstrBuilder<N> operator==(const MVar<M>& left, const MLinExpr<N>& right)
{
  MConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_EQUAL, left);
  return builder;
}

template <class T, int N> MConstrBuilder<N> operator==(const NdArray<T, N>& left, const MVar<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - left, COPT_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MConstrBuilder<N> operator==(const NdArray<T, N>& left, const MLinExpr<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_EQUAL, left);
  return builder;
}

template <int N> MConstrBuilder<N> operator==(double lhs, const MVar<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - lhs, COPT_EQUAL, 0.0);
  return builder;
}

template <int N> MConstrBuilder<N> operator==(const MExpression& expr, const MVar<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_EQUAL, 0.0);
  return builder;
}

template <int N> MConstrBuilder<N> operator==(double lhs, const MLinExpr<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_EQUAL, lhs);
  return builder;
}

template <int N> MConstrBuilder<N> operator==(const MExpression& expr, const MLinExpr<N>& right)
{
  MConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_EQUAL, expr);
  return builder;
}