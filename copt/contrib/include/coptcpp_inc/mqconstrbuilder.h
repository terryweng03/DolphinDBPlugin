#pragma once
#include "coptcpp.idl.h"
#include "mfactory.h"
#include "mquadexpr.h"

template <int N> class MQConstrBuilder {
public:
  MQConstrBuilder(const Shape<N>& shp) : m_builder(MFactory::Get().CreateMQConstrBuilder(shp.Get())) {}

  MQConstrBuilder(Copt::IMQConstrBuilder<N>* builder) : m_builder(builder) {}

  int GetND() const
  {
    return m_builder->GetND();
  }

  MQuadExpr<N> GetQuadExpr() const
  {
    return m_builder->GetQuadExpr();
  }

  char GetSense() const
  {
    return m_builder->GetSense();
  }

  MQConstrBuilder<1> Flatten() const
  {
    return m_builder->Flatten();
  }

  void Set(const MQuadExpr<N>& expr, char sense, double rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs);
  }

  template <int M> void Set(const MQuadExpr<N>& expr, char sense, const MVar<M>& rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs.Get());
    CHECKERROR(m_builder);
  }

  template <int M> void Set(const MQuadExpr<N>& expr, char sense, const MLinExpr<M>& rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs.Get());
    CHECKERROR(m_builder);
  }

  template <int M> void Set(const MQuadExpr<N>& expr, char sense, const MQuadExpr<M>& rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs.Get());
    CHECKERROR(m_builder);
  }

  template <class T> void Set(const MQuadExpr<N>& expr, char sense, const NdArray<T, N>& rhs)
  {
    m_builder->Set(expr.Get(), sense, rhs.Get());
  }

  Copt::IMQConstrBuilder<N>* Get() const
  {
    return &(*m_builder);
  }

private:
  std::shared_ptr<Copt::IMQConstrBuilder<N>> m_builder;
};

/* MQConstrBuilder less-than operators */
template <int N> MQConstrBuilder<N> operator<=(const MQuadExpr<N>& left, double rhs)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, rhs);
  return builder;
}

template <int N> MQConstrBuilder<N> operator<=(const MQuadExpr<N>& left, const MExpression& expr)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N> MQConstrBuilder<N> operator<=(const MQuadExpr<N>& left, const MQExpression& expr)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MQConstrBuilder<N> operator<=(const MQuadExpr<N>& left, const NdArray<T, N>& rhs)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, rhs);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator<=(const MQuadExpr<N>& left, const MVar<M>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, right);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator<=(const MQuadExpr<N>& left, const MLinExpr<M>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, right);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator<=(const MQuadExpr<N>& left, const MQuadExpr<M>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_LESS_EQUAL, right);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator<=(const MLinExpr<M>& left, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_GREATER_EQUAL, left);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator<=(const MVar<M>& left, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_GREATER_EQUAL, left);
  return builder;
}

template <class T, int N> MQConstrBuilder<N> operator<=(const NdArray<T, N>& left, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_GREATER_EQUAL, left);
  return builder;
}

template <int N> MQConstrBuilder<N> operator<=(double a, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_GREATER_EQUAL, a);
  return builder;
}

template <int N> MQConstrBuilder<N> operator<=(const MExpression& expr, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N> MQConstrBuilder<N> operator<=(const MQExpression& expr, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

/* MQConstrBuilder greater-than operators */
template <int N> MQConstrBuilder<N> operator>=(const MQuadExpr<N>& left, double rhs)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, rhs);
  return builder;
}

template <int N> MQConstrBuilder<N> operator>=(const MQuadExpr<N>& left, const MExpression& expr)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <int N> MQConstrBuilder<N> operator>=(const MQuadExpr<N>& left, const MQExpression& expr)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_GREATER_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MQConstrBuilder<N> operator>=(const MQuadExpr<N>& left, const NdArray<T, N>& rhs)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, rhs);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator>=(const MQuadExpr<N>& left, const MVar<M>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, right);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator>=(const MQuadExpr<N>& left, const MLinExpr<M>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, right);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator>=(const MQuadExpr<N>& left, const MQuadExpr<M>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_GREATER_EQUAL, right);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator>=(const MLinExpr<M>& left, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_LESS_EQUAL, left);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator>=(const MVar<M>& left, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_LESS_EQUAL, left);
  return builder;
}

template <class T, int N> MQConstrBuilder<N> operator>=(const NdArray<T, N>& left, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_LESS_EQUAL, left);
  return builder;
}

template <int N> MQConstrBuilder<N> operator>=(double a, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_LESS_EQUAL, a);
  return builder;
}

template <int N> MQConstrBuilder<N> operator>=(const MExpression& expr, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

template <int N> MQConstrBuilder<N> operator>=(const MQExpression& expr, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_LESS_EQUAL, 0.0);
  return builder;
}

/* MQConstrBuilder equal operators */
template <int N> MQConstrBuilder<N> operator==(const MQuadExpr<N>& left, double rhs)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, rhs);
  return builder;
}

template <int N> MQConstrBuilder<N> operator==(const MQuadExpr<N>& left, const MExpression& expr)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_EQUAL, 0.0);
  return builder;
}

template <int N> MQConstrBuilder<N> operator==(const MQuadExpr<N>& left, const MQExpression& expr)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left - expr, COPT_EQUAL, 0.0);
  return builder;
}

template <class T, int N> MQConstrBuilder<N> operator==(const MQuadExpr<N>& left, const NdArray<T, N>& rhs)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, rhs);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator==(const MQuadExpr<N>& left, const MVar<M>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, right);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator==(const MQuadExpr<N>& left, const MLinExpr<M>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, right);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator==(const MQuadExpr<N>& left, const MQuadExpr<M>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(left, COPT_EQUAL, right);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator==(const MLinExpr<M>& left, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_EQUAL, left);
  return builder;
}

template <int N, int M> MQConstrBuilder<N> operator==(const MVar<M>& left, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(left.GetShape());
  builder.Set(right, COPT_EQUAL, left);
  return builder;
}

template <class T, int N> MQConstrBuilder<N> operator==(const NdArray<T, N>& left, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_EQUAL, left);
  return builder;
}

template <int N> MQConstrBuilder<N> operator==(double a, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(right.GetShape());
  builder.Set(right, COPT_EQUAL, a);
  return builder;
}

template <int N> MQConstrBuilder<N> operator==(const MExpression& expr, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_EQUAL, 0.0);
  return builder;
}

template <int N> MQConstrBuilder<N> operator==(const MQExpression& expr, const MQuadExpr<N>& right)
{
  MQConstrBuilder<N> builder(right.GetShape());
  builder.Set(right - expr, COPT_EQUAL, 0.0);
  return builder;
}