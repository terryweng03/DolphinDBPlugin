#pragma once
#include "mlinexpr.h"
#include "mpsdexpr.h"
#include "mquadexpr.h"
#include "mvar.h"

namespace Mat {

/* MLinExpr related template functions */
static COPT_UNUSED MLinExpr<1> repeat(const Expr& expr, size_t repeats)
{
  MExpression mex(expr);
  return MHelper::Get().Repeat(mex.Get(), repeats);
}
static COPT_UNUSED MLinExpr<1> repeat(const MExpression& expr, size_t repeats)
{
  return MHelper::Get().Repeat(expr.Get(), repeats);
}

/* Matrix Multiply with result of mlinexpr */
template <class T, int N, int M> MLinExpr<N + M - 2> matmult(const MVar<N>& left, const NdArray<T, M>& right)
{
  return MHelper::Get().MatMultiply<T, N, M, N + M - 2>(left.Get(), right.Get());
}

template <class T, int N, int M> MLinExpr<N + M - 2> matmult(const MLinExpr<N>& left, const NdArray<T, M>& right)
{
  return MHelper::Get().MatMultiply<T, N, M, N + M - 2>(left.Get(), right.Get());
}

template <class T, int N, int M> MLinExpr<N + M - 2> matmult(const NdArray<T, N>& left, const MVar<M>& right)
{
  return MHelper::Get().MatMultiply<T, N, M, N + M - 2>(left.Get(), right.Get());
}

template <class T, int N, int M> MLinExpr<N + M - 2> matmult(const NdArray<T, N>& left, const MLinExpr<M>& right)
{
  return MHelper::Get().MatMultiply<T, N, M, N + M - 2>(left.Get(), right.Get());
}

template <int N> MLinExpr<N> stack(const MVar<N>& vars, const MLinExpr<N>& exprs, int axis)
{
  return MHelper::Get().Stack<N>(vars.Get(), exprs.Get(), axis);
}

template <class T, int N> MLinExpr<N> stack(const MVar<N>& vars, const NdArray<T, N>& A, int axis)
{
  return MHelper::Get().Stack<T, N>(vars.Get(), A.Get(), axis);
}

template <class T, int N> MLinExpr<N> stack(const NdArray<T, N>& A, const MVar<N>& vars, int axis)
{
  return MHelper::Get().Stack<T, N>(A.Get(), vars.Get(), axis);
}

template <int N> MLinExpr<N> stack(const MLinExpr<N>& exprs, const MVar<N>& vars, int axis)
{
  return MHelper::Get().Stack<N>(exprs.Get(), vars.Get(), axis);
}

template <int N> MLinExpr<N> stack(const MLinExpr<N>& exprs1, const MLinExpr<N>& exprs2, int axis)
{
  return MHelper::Get().Stack<N>(exprs1.Get(), exprs2.Get(), axis);
}

template <class T, int N> MLinExpr<N> stack(const MLinExpr<N>& exprs, const NdArray<T, N>& A, int axis)
{
  return MHelper::Get().Stack<T, N>(exprs.Get(), A.Get(), axis);
}

template <class T, int N> MLinExpr<N> stack(const NdArray<T, N>& A, const MLinExpr<N>& exprs, int axis)
{
  return MHelper::Get().Stack<T, N>(A.Get(), exprs.Get(), axis);
}

template <int> MLinExpr<2> hstack(const MVar<1>& vars, const MLinExpr<1>& exprs)
{
  Shape<2> shp1 = vars.GetShape().Expand(1);
  Shape<2> shp2 = exprs.GetShape().Expand(1);
  return Mat::stack<2>(vars.Reshape(shp1), exprs.Reshape(shp2), -1);
}
template <int N> MLinExpr<N> hstack(const MVar<N>& vars, const MLinExpr<N>& exprs)
{
  return Mat::stack(vars, exprs, -1);
}

template <class T, int> MLinExpr<2> hstack(const MVar<1>& vars, const NdArray<T, 1>& A)
{
  Shape<2> shp1 = vars.GetShape().Expand(1);
  Shape<2> shp2 = A.GetShape().Expand(1);
  return Mat::stack<2>(vars.Reshape(shp1), A.Reshape(shp2), -1);
}
template <class T, int N> MLinExpr<N> hstack(const MVar<N>& vars, const NdArray<T, N>& A)
{
  return Mat::stack(vars, A, -1);
}

template <class T, int> MLinExpr<2> hstack(const NdArray<T, 1>& A, const MVar<1>& vars)
{
  Shape<2> shp1 = A.GetShape().Expand(1);
  Shape<2> shp2 = vars.GetShape().Expand(1);
  return Mat::stack<2>(A.Reshape(shp1), vars.Reshape(shp2), -1);
}
template <class T, int N> MLinExpr<N> hstack(const NdArray<T, N>& A, const MVar<N>& vars)
{
  return Mat::stack(A, vars, -1);
}

template <int> MLinExpr<2> hstack(const MLinExpr<1>& exprs, const MVar<1>& vars)
{
  Shape<2> shp1 = exprs.GetShape().Expand(1);
  Shape<2> shp2 = vars.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp1), vars.Reshape(shp2), -1);
}
template <int N> MLinExpr<N> hstack(const MLinExpr<N>& exprs, const MVar<N>& vars)
{
  return Mat::stack(exprs, vars, -1);
}

template <int> MLinExpr<2> hstack(const MLinExpr<1>& exprs1, const MLinExpr<1>& exprs2)
{
  Shape<2> shp1 = exprs1.GetShape().Expand(1);
  Shape<2> shp2 = exprs2.GetShape().Expand(1);
  return Mat::stack<2>(exprs1.Reshape(shp1), exprs2.Reshape(shp2), -1);
}
template <int N> MLinExpr<N> hstack(const MLinExpr<N>& exprs1, const MLinExpr<N>& exprs2)
{
  return Mat::stack(exprs1, exprs2, -1);
}

template <class T, int> MLinExpr<2> hstack(const MLinExpr<1>& exprs, const NdArray<T, 1>& A)
{
  Shape<2> shp1 = exprs.GetShape().Expand(1);
  Shape<2> shp2 = A.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp1), A.Reshape(shp2), -1);
}
template <class T, int N> MLinExpr<N> hstack(const MLinExpr<N>& exprs, const NdArray<T, N>& A)
{
  return Mat::stack(exprs, A, -1);
}

template <class T, int> MLinExpr<2> hstack(const NdArray<T, 1>& A, const MLinExpr<1>& exprs)
{
  Shape<2> shp1 = A.GetShape().Expand(1);
  Shape<2> shp2 = exprs.GetShape().Expand(1);
  return Mat::stack<2>(A.Reshape(shp1), exprs.Reshape(shp2), -1);
}
template <class T, int N> MLinExpr<N> hstack(const NdArray<T, N>& A, const MLinExpr<N>& exprs)
{
  return Mat::stack(A, exprs, -1);
}

template <int N> MLinExpr<N> vstack(const MVar<N>& vars, const MLinExpr<N>& exprs)
{
  return Mat::stack(vars, exprs, N == 1 ? -1 : -2);
}

template <class T, int N> MLinExpr<N> vstack(const MVar<N>& vars, const NdArray<T, N>& A)
{
  return Mat::stack(vars, A, N == 1 ? -1 : -2);
}

template <class T, int N> MLinExpr<N> vstack(const NdArray<T, N>& A, const MVar<N>& vars)
{
  return Mat::stack(A, vars, N == 1 ? -1 : -2);
}

template <int N> MLinExpr<N> vstack(const MLinExpr<N>& exprs, const MVar<N>& vars)
{
  return Mat::stack(exprs, vars, N == 1 ? -1 : -2);
}

template <int N> MLinExpr<N> vstack(const MLinExpr<N>& exprs1, const MLinExpr<N>& exprs2)
{
  return Mat::stack(exprs1, exprs2, N == 1 ? -1 : -2);
}

template <class T, int N> MLinExpr<N> vstack(const MLinExpr<N>& exprs, const NdArray<T, N>& A)
{
  return Mat::stack(exprs, A, N == 1 ? -1 : -2);
}

template <class T, int N> MLinExpr<N> vstack(const NdArray<T, N>& A, const MLinExpr<N>& exprs)
{
  return Mat::stack(A, exprs, N == 1 ? -1 : -2);
}

// stack scalar (convertiable to MExpression) and mvars
template <int N> MLinExpr<N> stack(const MExpression& expr, const MVar<N>& vars, int axis)
{
  MLinExpr<N> left(vars.GetShape().RebuildWith(1), expr);
  return MHelper::Get().Stack<N>(left.Get(), vars.Get(), axis);
}
template <int> MLinExpr<2> hstack(const MExpression& expr, const MVar<1>& vars)
{
  Shape<2> shp = vars.GetShape().Expand(1);
  return Mat::stack<2>(expr, vars.Reshape(shp), -1);
}
template <int N> MLinExpr<N> hstack(const MExpression& expr, const MVar<N>& vars)
{
  return Mat::stack(expr, vars, -1);
}
template <int N> MLinExpr<N> vstack(const MExpression& expr, const MVar<N>& vars)
{
  return Mat::stack(expr, vars, N == 1 ? -1 : -2);
}

template <int N> MLinExpr<N> stack(const MVar<N>& vars, const MExpression& expr, int axis)
{
  MLinExpr<N> right(vars.GetShape().RebuildWith(1), expr);
  return MHelper::Get().Stack<N>(vars.Get(), right.Get(), axis);
}
template <int> MLinExpr<2> hstack(const MVar<1>& vars, const MExpression& expr)
{
  Shape<2> shp = vars.GetShape().Expand(1);
  return Mat::stack<2>(vars.Reshape(shp), expr, -1);
}
template <int N> MLinExpr<N> hstack(const MVar<N>& vars, const MExpression& expr)
{
  return Mat::stack(vars, expr, -1);
}
template <int N> MLinExpr<N> vstack(const MVar<N>& vars, const MExpression& expr)
{
  return Mat::stack(vars, expr, N == 1 ? -1 : -2);
}

// stack scalar (convertible to MExpression) and mlinexpr
template <int N> MLinExpr<N> stack(const MExpression& expr, const MLinExpr<N>& exprs, int axis)
{
  MLinExpr<N> left(exprs.GetShape().RebuildWith(1), expr);
  return MHelper::Get().Stack<N>(left.Get(), exprs.Get(), axis);
}
template <int> MLinExpr<2> hstack(const MExpression& expr, const MLinExpr<1>& exprs)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(expr, exprs.Reshape(shp), -1);
}
template <int N> MLinExpr<N> hstack(const MExpression& expr, const MLinExpr<N>& exprs)
{
  return Mat::stack(expr, exprs, -1);
}
template <int N> MLinExpr<N> vstack(const MExpression& expr, const MLinExpr<N>& exprs)
{
  return Mat::stack(expr, exprs, N == 1 ? -1 : -2);
}

template <int N> MLinExpr<N> stack(const MLinExpr<N>& exprs, const MExpression& expr, int axis)
{
  MLinExpr<N> right(exprs.GetShape().RebuildWith(1), expr);
  return MHelper::Get().Stack<N>(exprs.Get(), right.Get(), axis);
}
template <int> MLinExpr<2> hstack(const MLinExpr<1>& exprs, const MExpression& expr)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp), expr, -1);
}
template <int N> MLinExpr<N> hstack(const MLinExpr<N>& exprs, const MExpression& expr)
{
  return Mat::stack(exprs, expr, -1);
}
template <int N> MLinExpr<N> vstack(const MLinExpr<N>& exprs, const MExpression& expr)
{
  return Mat::stack(exprs, expr, N == 1 ? -1 : -2);
}

/* MQuadExpr related template functions */
static COPT_UNUSED MQuadExpr<1> repeat(const MQExpression& expr, size_t repeats)
{
  return MHelper::Get().Repeat(expr.Get(), repeats);
}

/* Matrix Multiply with result of mquadexpr */
template <int N, int M> MQuadExpr<N + M - 2> matmult(const MVar<N>& left, const MVar<M>& right)
{
  return MHelper::Get().MatMultiply<N, M, N + M - 2>(left.Get(), right.Get());
}

template <int N, int M> MQuadExpr<N + M - 2> matmult(const MVar<N>& left, const MLinExpr<M>& right)
{
  return MHelper::Get().MatMultiply<N, M, N + M - 2>(left.Get(), right.Get());
}

template <int N, int M> MQuadExpr<N + M - 2> matmult(const MLinExpr<N>& left, const MVar<M>& right)
{
  return MHelper::Get().MatMultiply<N, M, N + M - 2>(left.Get(), right.Get());
}

template <int N, int M> MQuadExpr<N + M - 2> matmult(const MLinExpr<N>& left, const MLinExpr<M>& right)
{
  return MHelper::Get().MatMultiply<N, M, N + M - 2>(left.Get(), right.Get());
}

template <class T, int N, int M> MQuadExpr<N + M - 2> matmult(const MQuadExpr<N>& left, const NdArray<T, M>& right)
{
  return MHelper::Get().MatMultiply<T, N, M, N + M - 2>(left.Get(), right.Get());
}

template <class T, int N, int M> MQuadExpr<N + M - 2> matmult(const NdArray<T, N>& left, const MQuadExpr<M>& right)
{
  return MHelper::Get().MatMultiply<T, N, M, N + M - 2>(left.Get(), right.Get());
}

template <int N> MQuadExpr<N> stack(const MQuadExpr<N>& exprs, const MVar<N>& vars, int axis)
{
  return MHelper::Get().Stack<N>(exprs.Get(), vars.Get(), axis);
}

template <int N> MQuadExpr<N> stack(const MVar<N>& vars, const MQuadExpr<N>& exprs, int axis)
{
  return MHelper::Get().Stack<N>(vars.Get(), exprs.Get(), axis);
}

template <int N> MQuadExpr<N> stack(const MQuadExpr<N>& qexprs, const MLinExpr<N>& exprs, int axis)
{
  return MHelper::Get().Stack<N>(qexprs.Get(), exprs.Get(), axis);
}

template <int N> MQuadExpr<N> stack(const MLinExpr<N>& exprs, const MQuadExpr<N>& qexprs, int axis)
{
  return MHelper::Get().Stack<N>(exprs.Get(), qexprs.Get(), axis);
}

template <int N> MQuadExpr<N> stack(const MQuadExpr<N>& exprs1, const MQuadExpr<N>& exprs2, int axis)
{
  return MHelper::Get().Stack<N>(exprs1.Get(), exprs2.Get(), axis);
}

template <class T, int N> MQuadExpr<N> stack(const MQuadExpr<N>& exprs, const NdArray<T, N>& A, int axis)
{
  return MHelper::Get().Stack<T, N>(exprs.Get(), A.Get(), axis);
}

template <class T, int N> MQuadExpr<N> stack(const NdArray<T, N>& A, const MQuadExpr<N>& exprs, int axis)
{
  return MHelper::Get().Stack<T, N>(A.Get(), exprs.Get(), axis);
}

template <int> MQuadExpr<2> hstack(const MQuadExpr<1>& exprs, const MVar<1>& vars)
{
  Shape<2> shp1 = exprs.GetShape().Expand(1);
  Shape<2> shp2 = vars.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp1), vars.Reshape(shp2), -1);
}
template <int N> MQuadExpr<N> hstack(const MQuadExpr<N>& exprs, const MVar<N>& vars)
{
  return Mat::stack(exprs, vars, -1);
}

template <class T, int> MQuadExpr<2> hstack(const MVar<1>& vars, const MQuadExpr<1>& exprs)
{
  Shape<2> shp1 = vars.GetShape().Expand(1);
  Shape<2> shp2 = exprs.GetShape().Expand(1);
  return Mat::stack<2>(vars.Reshape(shp1), exprs.Reshape(shp2), -1);
}
template <class T, int N> MQuadExpr<N> hstack(const MVar<N>& vars, const MQuadExpr<N>& exprs)
{
  return Mat::stack(vars, exprs, -1);
}

template <int> MQuadExpr<2> hstack(const MQuadExpr<1>& qexprs, const MLinExpr<1>& exprs)
{
  Shape<2> shp1 = qexprs.GetShape().Expand(1);
  Shape<2> shp2 = exprs.GetShape().Expand(1);
  return Mat::stack<2>(qexprs.Reshape(shp1), exprs.Reshape(shp2), -1);
}
template <int N> MQuadExpr<N> hstack(const MQuadExpr<N>& qexprs, const MLinExpr<N>& exprs)
{
  return Mat::stack(qexprs, exprs, -1);
}

template <class T, int> MQuadExpr<2> hstack(const MLinExpr<1>& exprs, const MQuadExpr<1>& qexprs)
{
  Shape<2> shp1 = exprs.GetShape().Expand(1);
  Shape<2> shp2 = qexprs.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp1), qexprs.Reshape(shp2), -1);
}
template <class T, int N> MQuadExpr<N> hstack(const MLinExpr<N>& exprs, const MQuadExpr<N>& qexprs)
{
  return Mat::stack(exprs, qexprs, -1);
}

template <int> MQuadExpr<2> hstack(const MQuadExpr<1>& exprs1, const MQuadExpr<1>& exprs2)
{
  Shape<2> shp1 = exprs1.GetShape().Expand(1);
  Shape<2> shp2 = exprs2.GetShape().Expand(1);
  return Mat::stack<2>(exprs1.Reshape(shp1), exprs2.Reshape(shp2), -1);
}
template <int N> MQuadExpr<N> hstack(const MQuadExpr<N>& exprs1, const MQuadExpr<N>& exprs2)
{
  return Mat::stack(exprs1, exprs2, -1);
}

template <class T, int> MQuadExpr<2> hstack(const MQuadExpr<1>& exprs, const NdArray<T, 1>& A)
{
  Shape<2> shp1 = exprs.GetShape().Expand(1);
  Shape<2> shp2 = A.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp1), A.Reshape(shp2), -1);
}
template <class T, int N> MQuadExpr<N> hstack(const MQuadExpr<N>& exprs, const NdArray<T, N>& A)
{
  return Mat::stack(exprs, A, -1);
}

template <class T, int> MQuadExpr<2> hstack(const NdArray<T, 1>& A, const MQuadExpr<1>& exprs)
{
  Shape<2> shp1 = A.GetShape().Expand(1);
  Shape<2> shp2 = exprs.GetShape().Expand(1);
  return Mat::stack<2>(A.Reshape(shp1), exprs.Reshape(shp2), -1);
}
template <class T, int N> MQuadExpr<N> hstack(const NdArray<T, N>& A, const MQuadExpr<N>& exprs)
{
  return Mat::stack(A, exprs, -1);
}

template <int N> MQuadExpr<N> vstack(const MQuadExpr<N>& exprs, const MVar<N>& vars)
{
  return Mat::stack(exprs, vars, N == 1 ? -1 : -2);
}

template <class T, int N> MQuadExpr<N> vstack(const MVar<N>& vars, const MQuadExpr<N>& exprs)
{
  return Mat::stack(vars, exprs, N == 1 ? -1 : -2);
}

template <int N> MQuadExpr<N> vstack(const MQuadExpr<N>& qexprs, const MLinExpr<N>& exprs)
{
  return Mat::stack(qexprs, exprs, N == 1 ? -1 : -2);
}

template <class T, int N> MQuadExpr<N> vstack(const MLinExpr<N>& exprs, const MQuadExpr<N>& qexprs)
{
  return Mat::stack(exprs, qexprs, N == 1 ? -1 : -2);
}

template <int N> MQuadExpr<N> vstack(const MQuadExpr<N>& exprs1, const MQuadExpr<N>& exprs2)
{
  return Mat::stack(exprs1, exprs2, N == 1 ? -1 : -2);
}

template <class T, int N> MQuadExpr<N> vstack(const MQuadExpr<N>& exprs, const NdArray<T, N>& A)
{
  return Mat::stack(exprs, A, N == 1 ? -1 : -2);
}

template <class T, int N> MQuadExpr<N> vstack(const NdArray<T, N>& A, const MQuadExpr<N>& exprs)
{
  return Mat::stack(A, exprs, N == 1 ? -1 : -2);
}

// stack scalar and mquadexpr
template <int N> MQuadExpr<N> stack(double a, const MQuadExpr<N>& exprs, int axis)
{
  NdArray<double, N> left(exprs.GetShape().RebuildWith(1), a);
  return MHelper::Get().Stack<double, N>(left.Get(), exprs.Get(), axis);
}
template <int> MQuadExpr<2> hstack(double a, const MQuadExpr<1>& exprs)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(a, exprs.Reshape(shp), -1);
}
template <int N> MQuadExpr<N> hstack(double a, const MQuadExpr<N>& exprs)
{
  return Mat::stack(a, exprs, -1);
}
template <int N> MQuadExpr<N> vstack(double a, const MQuadExpr<N>& exprs)
{
  return Mat::stack(a, exprs, N == 1 ? -1 : -2);
}

template <int N> MQuadExpr<N> stack(const MQuadExpr<N>& exprs, double a, int axis)
{
  NdArray<double, N> right(exprs.GetShape().RebuildWith(1), a);
  return MHelper::Get().Stack<double, N>(exprs.Get(), right.Get(), axis);
}
template <int> MQuadExpr<2> hstack(const MQuadExpr<1>& exprs, double a)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp), a, -1);
}
template <int N> MQuadExpr<N> hstack(const MQuadExpr<N>& exprs, double a)
{
  return Mat::stack(exprs, a, -1);
}
template <int N> MQuadExpr<N> vstack(const MQuadExpr<N>& exprs, double a)
{
  return Mat::stack(exprs, a, N == 1 ? -1 : -2);
}

template <int N> MQuadExpr<N> stack(const MExpression& expr, const MQuadExpr<N>& exprs, int axis)
{
  MLinExpr<N> left(exprs.GetShape().RebuildWith(1), expr);
  return MHelper::Get().Stack<N>(left.Get(), exprs.Get(), axis);
}
template <int> MQuadExpr<2> hstack(const MExpression& expr, const MQuadExpr<1>& exprs)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(expr, exprs.Reshape(shp), -1);
}
template <int N> MQuadExpr<N> hstack(const MExpression& expr, const MQuadExpr<N>& exprs)
{
  return Mat::stack(expr, exprs, -1);
}
template <int N> MQuadExpr<N> vstack(const MExpression& expr, const MQuadExpr<N>& exprs)
{
  return Mat::stack(expr, exprs, N == 1 ? -1 : -2);
}

template <int N> MQuadExpr<N> stack(const MQuadExpr<N>& exprs, const MExpression& expr, int axis)
{
  MLinExpr<N> right(exprs.GetShape().RebuildWith(1), expr);
  return MHelper::Get().Stack<N>(exprs.Get(), right.Get(), axis);
}
template <int> MQuadExpr<2> hstack(const MQuadExpr<1>& exprs, const MExpression& expr)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp), expr, -1);
}
template <int N> MQuadExpr<N> hstack(const MQuadExpr<N>& exprs, const MExpression& expr)
{
  return Mat::stack(exprs, expr, -1);
}
template <int N> MQuadExpr<N> vstack(const MQuadExpr<N>& exprs, const MExpression& expr)
{
  return Mat::stack(exprs, expr, N == 1 ? -1 : -2);
}

template <int N> MQuadExpr<N> stack(const MQExpression& qexpr, const MQuadExpr<N>& exprs, int axis)
{
  MQuadExpr<N> left(exprs.GetShape().RebuildWith(1), qexpr);
  return MHelper::Get().Stack<N>(left.Get(), exprs.Get(), axis);
}
template <int> MQuadExpr<2> hstack(const MQExpression& qexpr, const MQuadExpr<1>& exprs)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(qexpr, exprs.Reshape(shp), -1);
}
template <int N> MQuadExpr<N> hstack(const MQExpression& qexpr, const MQuadExpr<N>& exprs)
{
  return Mat::stack(qexpr, exprs, -1);
}
template <int N> MQuadExpr<N> vstack(const MQExpression& qexpr, const MQuadExpr<N>& exprs)
{
  return Mat::stack(qexpr, exprs, N == 1 ? -1 : -2);
}

template <int N> MQuadExpr<N> stack(const MQuadExpr<N>& exprs, const MQExpression& qexpr, int axis)
{
  MQuadExpr<N> right(exprs.GetShape().RebuildWith(1), qexpr);
  return MHelper::Get().Stack<N>(exprs.Get(), right.Get(), axis);
}
template <int> MQuadExpr<2> hstack(const MQuadExpr<1>& exprs, const MQExpression& qexpr)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp), qexpr, -1);
}
template <int N> MQuadExpr<N> hstack(const MQuadExpr<N>& exprs, const MQExpression& qexpr)
{
  return Mat::stack(exprs, qexpr, -1);
}
template <int N> MQuadExpr<N> vstack(const MQuadExpr<N>& exprs, const MQExpression& qexpr)
{
  return Mat::stack(exprs, qexpr, N == 1 ? -1 : -2);
}

/* MPsdExpr related template functions */
static COPT_UNUSED MPsdExpr<1> repeat(const PsdExpr& expr, size_t repeats)
{
  return MHelper::Get().Repeat(expr.Get(), repeats);
}

/* static methods for basic matrix operations on PsdVar */
/* note that they cannot be decleared as PsdVar memebers for cycle header dependency */
static COPT_UNUSED MPsdExpr<1> diagonal(const PsdVar& var, int offset)
{
  auto ret = var.Get()->Diagonal(offset);
  CHECKERROR(ret);
  return ret;
}

static COPT_UNUSED MPsdExpr<1> pick(const PsdVar& var, const NdArray<int, 1>& indexes)
{
  auto ret = var.Get()->Pick(indexes.Get());
  CHECKERROR(ret);
  return ret;
}

static COPT_UNUSED MPsdExpr<1> pick(const PsdVar& var, const NdArray<int, 2>& idxrows)
{
  auto ret = var.Get()->Pick(idxrows.Get());
  CHECKERROR(ret);
  return ret;
}

static COPT_UNUSED MPsdExpr<2> slice(const PsdVar& var, const View& view)
{
  auto ret = var.Get()->Item(view.Get());
  CHECKERROR(ret);
  return ret;
}

static COPT_UNUSED PsdExpr sum(const PsdVar& var)
{
  return var.Get()->Sum();
}

static COPT_UNUSED MPsdExpr<2> toexpr(const PsdVar& var)
{
  return var.Get()->ToExpr();
}

/* Matrix Multiply with result of mpsdexpr */
template <class T, int N, int M> MPsdExpr<N + M - 2> matmult(const MPsdExpr<N>& left, const NdArray<T, M>& right)
{
  return MHelper::Get().MatMultiply<T, N, M, N + M - 2>(left.Get(), right.Get());
}

template <class T, int N, int M> MPsdExpr<N + M - 2> matmult(const NdArray<T, N>& left, const MPsdExpr<M>& right)
{
  return MHelper::Get().MatMultiply<T, N, M, N + M - 2>(left.Get(), right.Get());
}

template <int N> MPsdExpr<N> stack(const MPsdExpr<N>& exprs, const MVar<N>& vars, int axis)
{
  return MHelper::Get().Stack<N>(exprs.Get(), vars.Get(), axis);
}

template <int N> MPsdExpr<N> stack(const MVar<N>& vars, const MPsdExpr<N>& exprs, int axis)
{
  return MHelper::Get().Stack<N>(vars.Get(), exprs.Get(), axis);
}

template <int N> MPsdExpr<N> stack(const MPsdExpr<N>& qexprs, const MLinExpr<N>& exprs, int axis)
{
  return MHelper::Get().Stack<N>(qexprs.Get(), exprs.Get(), axis);
}

template <int N> MPsdExpr<N> stack(const MLinExpr<N>& exprs, const MPsdExpr<N>& qexprs, int axis)
{
  return MHelper::Get().Stack<N>(exprs.Get(), qexprs.Get(), axis);
}

template <int N> MPsdExpr<N> stack(const MPsdExpr<N>& exprs1, const MPsdExpr<N>& exprs2, int axis)
{
  return MHelper::Get().Stack<N>(exprs1.Get(), exprs2.Get(), axis);
}

template <class T, int N> MPsdExpr<N> stack(const MPsdExpr<N>& exprs, const NdArray<T, N>& A, int axis)
{
  return MHelper::Get().Stack<T, N>(exprs.Get(), A.Get(), axis);
}

template <class T, int N> MPsdExpr<N> stack(const NdArray<T, N>& A, const MPsdExpr<N>& exprs, int axis)
{
  return MHelper::Get().Stack<T, N>(A.Get(), exprs.Get(), axis);
}

template <int> MPsdExpr<2> hstack(const MPsdExpr<1>& exprs, const MVar<1>& vars)
{
  Shape<2> shp1 = exprs.GetShape().Expand(1);
  Shape<2> shp2 = vars.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp1), vars.Reshape(shp2), -1);
}
template <int N> MPsdExpr<N> hstack(const MPsdExpr<N>& exprs, const MVar<N>& vars)
{
  return Mat::stack(exprs, vars, -1);
}

template <int> MPsdExpr<2> hstack(const MVar<1>& vars, const MPsdExpr<1>& exprs)
{
  Shape<2> shp1 = vars.GetShape().Expand(1);
  Shape<2> shp2 = exprs.GetShape().Expand(1);
  return Mat::stack<2>(vars.Reshape(shp1), exprs.Reshape(shp2), -1);
}
template <int N> MPsdExpr<N> hstack(const MVar<N>& vars, const MPsdExpr<N>& exprs)
{
  return Mat::stack(vars, exprs, -1);
}

template <int> MPsdExpr<2> hstack(const MPsdExpr<1>& qexprs, const MLinExpr<1>& exprs)
{
  Shape<2> shp1 = qexprs.GetShape().Expand(1);
  Shape<2> shp2 = exprs.GetShape().Expand(1);
  return Mat::stack<2>(qexprs.Reshape(shp1), exprs.Reshape(shp2), -1);
}
template <int N> MPsdExpr<N> hstack(const MPsdExpr<N>& qexprs, const MLinExpr<N>& exprs)
{
  return Mat::stack(qexprs, exprs, -1);
}

template <int> MPsdExpr<2> hstack(const MLinExpr<1>& exprs, const MPsdExpr<1>& qexprs)
{
  Shape<2> shp1 = exprs.GetShape().Expand(1);
  Shape<2> shp2 = qexprs.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp1), qexprs.Reshape(shp2), -1);
}
template <int N> MPsdExpr<N> hstack(const MLinExpr<N>& exprs, const MPsdExpr<N>& qexprs)
{
  return Mat::stack(exprs, qexprs, -1);
}

template <int> MPsdExpr<2> hstack(const MPsdExpr<1>& exprs1, const MPsdExpr<1>& exprs2)
{
  Shape<2> shp1 = exprs1.GetShape().Expand(1);
  Shape<2> shp2 = exprs2.GetShape().Expand(1);
  return Mat::stack<2>(exprs1.Reshape(shp1), exprs2.Reshape(shp2), -1);
}
template <int N> MPsdExpr<N> hstack(const MPsdExpr<N>& exprs1, const MPsdExpr<N>& exprs2)
{
  return Mat::stack(exprs1, exprs2, -1);
}

template <class T, int> MPsdExpr<2> hstack(const MPsdExpr<1>& exprs, const NdArray<T, 1>& A)
{
  Shape<2> shp1 = exprs.GetShape().Expand(1);
  Shape<2> shp2 = A.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp1), A.Reshape(shp2), -1);
}
template <class T, int N> MPsdExpr<N> hstack(const MPsdExpr<N>& exprs, const NdArray<T, N>& A)
{
  return Mat::stack(exprs, A, -1);
}

template <class T, int> MPsdExpr<1> hstack(const NdArray<T, 1>& A, const MPsdExpr<1>& exprs)
{
  Shape<2> shp1 = A.GetShape().Expand(1);
  Shape<2> shp2 = exprs.GetShape().Expand(1);
  return Mat::stack<2>(A.Reshape(shp1), exprs.Reshape(shp2), -1);
}
template <class T, int N> MPsdExpr<N> hstack(const NdArray<T, N>& A, const MPsdExpr<N>& exprs)
{
  return Mat::stack(A, exprs, -1);
}

template <int N> MPsdExpr<N> vstack(const MPsdExpr<N>& exprs, const MVar<N>& vars)
{
  return Mat::stack(exprs, vars, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> vstack(const MVar<N>& vars, const MPsdExpr<N>& exprs)
{
  return Mat::stack(vars, exprs, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> vstack(const MPsdExpr<N>& qexprs, const MLinExpr<N>& exprs)
{
  return Mat::stack(qexprs, exprs, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> vstack(const MLinExpr<N>& exprs, const MPsdExpr<N>& qexprs)
{
  return Mat::stack(exprs, qexprs, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> vstack(const MPsdExpr<N>& exprs1, const MPsdExpr<N>& exprs2)
{
  return Mat::stack(exprs1, exprs2, N == 1 ? -1 : -2);
}

template <class T, int N> MPsdExpr<N> vstack(const MPsdExpr<N>& exprs, const NdArray<T, N>& A)
{
  return Mat::stack(exprs, A, N == 1 ? -1 : -2);
}

template <class T, int N> MPsdExpr<N> vstack(const NdArray<T, N>& A, const MPsdExpr<N>& exprs)
{
  return Mat::stack(A, exprs, N == 1 ? -1 : -2);
}

// stack scalar and mpsdexpr
template <int N> MPsdExpr<N> stack(double a, const MPsdExpr<N>& exprs, int axis)
{
  NdArray<double, N> left(exprs.GetShape().RebuildWith(1), a);
  return MHelper::Get().Stack<double, N>(left.Get(), exprs.Get(), axis);
}
template <int> MPsdExpr<2> hstack(double a, const MPsdExpr<1>& exprs)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(a, exprs.Reshape(shp), -1);
}
template <int N> MPsdExpr<N> hstack(double a, const MPsdExpr<N>& exprs)
{
  return Mat::stack(a, exprs, -1);
}
template <int N> MPsdExpr<N> vstack(double a, const MPsdExpr<N>& exprs)
{
  return Mat::stack(a, exprs, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> stack(const MPsdExpr<N>& exprs, double a, int axis)
{
  NdArray<double, N> right(exprs.GetShape().RebuildWith(1), a);
  return MHelper::Get().Stack<double, N>(exprs.Get(), right.Get(), axis);
}
template <int> MPsdExpr<2> hstack(const MPsdExpr<1>& exprs, double a)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp), a, -1);
}
template <int N> MPsdExpr<N> hstack(const MPsdExpr<N>& exprs, double a)
{
  return Mat::stack(exprs, a, -1);
}
template <int N> MPsdExpr<N> vstack(const MPsdExpr<N>& exprs, double a)
{
  return Mat::stack(exprs, a, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> stack(const Var& var, const MPsdExpr<N>& exprs, int axis)
{
  MVar<N> left(exprs.GetShape().RebuildWith(1), var);
  return MHelper::Get().Stack<N>(left.Get(), exprs.Get(), axis);
}
template <int> MPsdExpr<2> hstack(const Var& var, const MPsdExpr<1>& exprs)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(var, exprs.Reshape(shp), -1);
}
template <int N> MPsdExpr<N> hstack(const Var& var, const MPsdExpr<N>& exprs)
{
  return Mat::stack(var, exprs, -1);
}
template <int N> MPsdExpr<N> vstack(const Var& var, const MPsdExpr<N>& exprs)
{
  return Mat::stack(var, exprs, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> stack(const MPsdExpr<N>& exprs, const Var& var, int axis)
{
  MVar<N> right(exprs.GetShape().RebuildWith(1), var);
  return MHelper::Get().Stack<N>(exprs.Get(), right.Get(), axis);
}
template <int> MPsdExpr<2> hstack(const MPsdExpr<1>& exprs, const Var& var)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp), var, -1);
}
template <int N> MPsdExpr<N> hstack(const MPsdExpr<N>& exprs, const Var& var)
{
  return Mat::stack(exprs, var, -1);
}
template <int N> MPsdExpr<N> vstack(const MPsdExpr<N>& exprs, const Var& var)
{
  return Mat::stack(exprs, var, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> stack(const Expr& expr, const MPsdExpr<N>& exprs, int axis)
{
  MLinExpr<N> left(exprs.GetShape().RebuildWith(1), expr);
  return MHelper::Get().Stack<N>(left.Get(), exprs.Get(), axis);
}
template <int> MPsdExpr<2> hstack(const Expr& expr, const MPsdExpr<1>& exprs)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(expr, exprs.Reshape(shp), -1);
}
template <int N> MPsdExpr<N> hstack(const Expr& expr, const MPsdExpr<N>& exprs)
{
  return Mat::stack(expr, exprs, -1);
}
template <int N> MPsdExpr<N> vstack(const Expr& expr, const MPsdExpr<N>& exprs)
{
  return Mat::stack(expr, exprs, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> stack(const MPsdExpr<N>& exprs, const Expr& expr, int axis)
{
  MLinExpr<N> right(exprs.GetShape().RebuildWith(1), expr);
  return MHelper::Get().Stack<N>(exprs.Get(), right.Get(), axis);
}
template <int> MPsdExpr<2> hstack(const MPsdExpr<1>& exprs, const Expr& expr)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp), expr, -1);
}
template <int N> MPsdExpr<N> hstack(const MPsdExpr<N>& exprs, const Expr& expr)
{
  return Mat::stack(exprs, expr, -1);
}
template <int N> MPsdExpr<N> vstack(const MPsdExpr<N>& exprs, const Expr& expr)
{
  return Mat::stack(exprs, expr, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> stack(const MExpression& expr, const MPsdExpr<N>& exprs, int axis)
{
  MLinExpr<N> left(exprs.GetShape().RebuildWith(1), expr);
  return MHelper::Get().Stack<N>(left.Get(), exprs.Get(), axis);
}
template <int> MPsdExpr<2> hstack(const MExpression& expr, const MPsdExpr<1>& exprs)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(expr, exprs.Reshape(shp), -1);
}
template <int N> MPsdExpr<N> hstack(const MExpression& expr, const MPsdExpr<N>& exprs)
{
  return Mat::stack(expr, exprs, -1);
}
template <int N> MPsdExpr<N> vstack(const MExpression& expr, const MPsdExpr<N>& exprs)
{
  return Mat::stack(expr, exprs, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> stack(const MPsdExpr<N>& exprs, const MExpression& expr, int axis)
{
  MLinExpr<N> right(exprs.GetShape().RebuildWith(1), expr);
  return MHelper::Get().Stack<N>(exprs.Get(), right.Get(), axis);
}
template <int> MPsdExpr<2> hstack(const MPsdExpr<1>& exprs, const MExpression& expr)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp), expr, -1);
}
template <int N> MPsdExpr<N> hstack(const MPsdExpr<N>& exprs, const MExpression& expr)
{
  return Mat::stack(exprs, expr, -1);
}
template <int N> MPsdExpr<N> vstack(const MPsdExpr<N>& exprs, const MExpression& expr)
{
  return Mat::stack(exprs, expr, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> stack(const PsdExpr& expr, const MPsdExpr<N>& exprs, int axis)
{
  MPsdExpr<N> left(exprs.GetShape().RebuildWith(1), expr);
  return MHelper::Get().Stack<N>(left.Get(), exprs.Get(), axis);
}
template <int> MPsdExpr<2> hstack(const PsdExpr& expr, const MPsdExpr<1>& exprs)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(expr, exprs.Reshape(shp), -1);
}
template <int N> MPsdExpr<N> hstack(const PsdExpr& expr, const MPsdExpr<N>& exprs)
{
  return Mat::stack(expr, exprs, -1);
}
template <int N> MPsdExpr<N> vstack(const PsdExpr& expr, const MPsdExpr<N>& exprs)
{
  return Mat::stack(expr, exprs, N == 1 ? -1 : -2);
}

template <int N> MPsdExpr<N> stack(const MPsdExpr<N>& exprs, const PsdExpr& expr, int axis)
{
  MPsdExpr<N> right(exprs.GetShape().RebuildWith(1), expr);
  return MHelper::Get().Stack<N>(exprs.Get(), right.Get(), axis);
}
template <int> MPsdExpr<2> hstack(const MPsdExpr<1>& exprs, const PsdExpr& expr)
{
  Shape<2> shp = exprs.GetShape().Expand(1);
  return Mat::stack<2>(exprs.Reshape(shp), expr, -1);
}
template <int N> MPsdExpr<N> hstack(const MPsdExpr<N>& exprs, const PsdExpr& expr)
{
  return Mat::stack(exprs, expr, -1);
}
template <int N> MPsdExpr<N> vstack(const MPsdExpr<N>& exprs, const PsdExpr& expr)
{
  return Mat::stack(exprs, expr, N == 1 ? -1 : -2);
}

}  // namespace Mat
