#pragma once
#include "coptcpp.idl.h"

#if defined(__GNUC__) || defined(__clang__)
#define COPT_UNUSED __attribute__((unused))
#elif defined(_MSC_VER)
#define COPT_UNUSED __pragma(warning(suppress : 4505))
#else
#define COPT_UNUSED
#endif

#define COPT_MAX(a, b) (((a) > (b)) ? (a) : (b))

class MHelper {
public:
  static MHelper& Get()
  {
    static MHelper helper;
    return helper;
  }

  /* templates of matrix multiplication */
  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* MatMultiply(const Copt::IMVar<N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->MatMultiply(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* MatMultiply(const Copt::IMVar<N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->MatMultiply(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* MatMultiply(const Copt::IMLinExpr<N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->MatMultiply(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* MatMultiply(const Copt::IMLinExpr<N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->MatMultiply(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N>
  Copt::IMLinExpr<N - 1>* MatMultiply(const Copt::INdArray<T, N>* A, const Copt::IVarArray* vars) const
  {
    auto ret = m_helper->MatMultiply(A, vars);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* MatMultiply(const Copt::INdArray<T, N>* A, const Copt::IMVar<M>* vars) const
  {
    auto ret = m_helper->MatMultiply(A, vars);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* MatMultiply(const Copt::INdArray<T, N>* A, const Copt::IMLinExpr<M>* exprs) const
  {
    auto ret = m_helper->MatMultiply(A, exprs);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMQuadExpr<K>* MatMultiply(const Copt::INdArray<T, N>* A, const Copt::IMQuadExpr<M>* exprs) const
  {
    auto ret = m_helper->MatMultiply(A, exprs);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMPsdExpr<K>* MatMultiply(const Copt::INdArray<T, N>* A, const Copt::IMPsdExpr<M>* exprs) const
  {
    auto ret = m_helper->MatMultiply(A, exprs);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N>
  Copt::IMLinExpr<N - 1>* MatMultiply(const Copt::IVarArray* vars, const Copt::INdArray<T, N>* A) const
  {
    auto ret = m_helper->MatMultiply(vars, A);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* MatMultiply(const Copt::IMVar<N>* vars, const Copt::INdArray<T, M>* A) const
  {
    auto ret = m_helper->MatMultiply(vars, A);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* MatMultiply(const Copt::IMLinExpr<N>* exprs, const Copt::INdArray<T, M>* A) const
  {
    auto ret = m_helper->MatMultiply(exprs, A);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMQuadExpr<K>* MatMultiply(const Copt::IMQuadExpr<N>* exprs, const Copt::INdArray<T, M>* A) const
  {
    auto ret = m_helper->MatMultiply(exprs, A);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMPsdExpr<K>* MatMultiply(const Copt::IMPsdExpr<N>* exprs, const Copt::INdArray<T, M>* A) const
  {
    auto ret = m_helper->MatMultiply(exprs, A);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::INdArray<double, K>* MatMultiply(const Copt::INdArray<T, N>* left, const Copt::INdArray<double, M>* right) const
  {
    auto ret = m_helper->MatMultiply(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::INdArray<T, K>* MatMultiply(const Copt::INdArray<T, N>* left, const Copt::INdArray<int, M>* right) const
  {
    auto ret = m_helper->MatMultiply(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* templates of diagnonal of mobjs, with offset and axis */
  template <int N> Copt::IMVar<N - 1>* Diagonal(const Copt::IMVar<N>* vars, int offset, int axis1, int axis2) const
  {
    auto ret = m_helper->Diagonal(vars, offset, axis1, axis2);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMConstr<N - 1>* Diagonal(const Copt::IMConstr<N>* cons, int offset, int axis1, int axis2) const
  {
    auto ret = m_helper->Diagonal(cons, offset, axis1, axis2);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMQConstr<N - 1>* Diagonal(const Copt::IMQConstr<N>* cons, int offset, int axis1, int axis2) const
  {
    auto ret = m_helper->Diagonal(cons, offset, axis1, axis2);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMPsdConstr<N - 1>* Diagonal(const Copt::IMPsdConstr<N>* cons, int offset, int axis1, int axis2) const
  {
    auto ret = m_helper->Diagonal(cons, offset, axis1, axis2);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMLinExpr<N - 1>* Diagonal(const Copt::IMLinExpr<N>* exprs, int offset, int axis1, int axis2) const
  {
    auto ret = m_helper->Diagonal(exprs, offset, axis1, axis2);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMQuadExpr<N - 1>* Diagonal(const Copt::IMQuadExpr<N>* exprs, int offset, int axis1, int axis2) const
  {
    auto ret = m_helper->Diagonal(exprs, offset, axis1, axis2);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMPsdExpr<N - 1>* Diagonal(const Copt::IMPsdExpr<N>* exprs, int offset, int axis1, int axis2) const
  {
    auto ret = m_helper->Diagonal(exprs, offset, axis1, axis2);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N>
  Copt::INdArray<T, N - 1>* Diagonal(const Copt::INdArray<T, N>* mat, int offset, int axis1, int axis2) const
  {
    auto ret = m_helper->Diagonal(mat, offset, axis1, axis2);
    CHECKERROR(ret);
    return ret;
  }

  /* expand shape to higher dimension along axis */
  template <int N> Copt::INDim<N + 1>* Expand(const Copt::INDim<N>* shape, int axis) const
  {
    auto ret = m_helper->Expand(shape, axis);
    CHECKERROR(ret);
    return ret;
  }
  template <int N> Copt::IMVar<N + 1>* Expand(const Copt::IMVar<N>* vars, int axis) const
  {
    auto ret = m_helper->Expand(vars, axis);
    CHECKERROR(ret);
    return ret;
  }
  template <int N> Copt::IMConstr<N + 1>* Expand(const Copt::IMConstr<N>* cons, int axis) const
  {
    auto ret = m_helper->Expand(cons, axis);
    CHECKERROR(ret);
    return ret;
  }
  template <int N> Copt::IMQConstr<N + 1>* Expand(const Copt::IMQConstr<N>* cons, int axis) const
  {
    auto ret = m_helper->Expand(cons, axis);
    CHECKERROR(ret);
    return ret;
  }
  template <int N> Copt::IMPsdConstr<N + 1>* Expand(const Copt::IMPsdConstr<N>* cons, int axis) const
  {
    auto ret = m_helper->Expand(cons, axis);
    CHECKERROR(ret);
    return ret;
  }
  template <int N> Copt::IMLinExpr<N + 1>* Expand(const Copt::IMLinExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Expand(exprs, axis);
    CHECKERROR(ret);
    return ret;
  }
  template <int N> Copt::IMQuadExpr<N + 1>* Expand(const Copt::IMQuadExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Expand(exprs, axis);
    CHECKERROR(ret);
    return ret;
  }
  template <int N> Copt::IMPsdExpr<N + 1>* Expand(const Copt::IMPsdExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Expand(exprs, axis);
    CHECKERROR(ret);
    return ret;
  }
  template <class T, int N> Copt::INdArray<T, N + 1>* Expand(const Copt::INdArray<T, N>* mat, int axis) const
  {
    auto ret = m_helper->Expand(mat, axis);
    CHECKERROR(ret);
    return ret;
  }

  Copt::INdArray<double, 1>* Repeat(double a, size_t repeats) const
  {
    return m_helper->Repeat(a, repeats);
  }

  Copt::INdArray<int64_t, 1>* Repeat(int64_t a, size_t repeats) const
  {
    return m_helper->Repeat(a, repeats);
  }

  Copt::INdArray<int, 1>* Repeat(int a, size_t repeats) const
  {
    return m_helper->Repeat(a, repeats);
  }

  Copt::IMVar<1>* Repeat(const Copt::IVar* var, size_t repeats) const
  {
    return m_helper->Repeat(var, repeats);
  }

  Copt::IMLinExpr<1>* Repeat(const Copt::IMExpression* expr, size_t repeats) const
  {
    return m_helper->Repeat(expr, repeats);
  }

  Copt::IMQuadExpr<1>* Repeat(const Copt::IMQExpression* expr, size_t repeats) const
  {
    return m_helper->Repeat(expr, repeats);
  }

  Copt::IMPsdExpr<1>* Repeat(const Copt::IPsdExpr* expr, size_t repeats) const
  {
    return m_helper->Repeat(expr, repeats);
  }

  /* templates of squeeze of mobjs, along axis */
  template <int N> Copt::INDim<N - 1>* Squeeze(const Copt::INDim<N>* shape, int axis) const
  {
    auto ret = m_helper->Squeeze(shape, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N> Copt::IMVar<N - 1>* Squeeze(const Copt::IMVar<N>* vars, int axis) const
  {
    auto ret = m_helper->Squeeze(vars, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N> Copt::IMConstr<N - 1>* Squeeze(const Copt::IMConstr<N>* cons, int axis) const
  {
    auto ret = m_helper->Squeeze(cons, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N> Copt::IMQConstr<N - 1>* Squeeze(const Copt::IMQConstr<N>* cons, int axis) const
  {
    auto ret = m_helper->Squeeze(cons, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N> Copt::IMPsdConstr<N - 1>* Squeeze(const Copt::IMPsdConstr<N>* cons, int axis) const
  {
    auto ret = m_helper->Squeeze(cons, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N> Copt::IMLinExpr<N - 1>* Squeeze(const Copt::IMLinExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Squeeze(exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N> Copt::IMQuadExpr<N - 1>* Squeeze(const Copt::IMQuadExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Squeeze(exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N> Copt::IMPsdExpr<N - 1>* Squeeze(const Copt::IMPsdExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Squeeze(exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N> Copt::INdArray<T, N - 1>* Squeeze(const Copt::INdArray<T, N>* mat, int axis) const
  {
    auto ret = m_helper->Squeeze(mat, axis);
    CHECKERROR(ret);
    return ret;
  }

  /* templates of stack of mobjs, along axis */
  template <class T, int N>
  Copt::INdArray<double, N>*
  Stack(const Copt::INdArray<T, N>* left, const Copt::INdArray<double, N>* right, int axis) const
  {
    auto ret = m_helper->Stack(left, right, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N>
  Copt::INdArray<T, N>* Stack(const Copt::INdArray<T, N>* left, const Copt::INdArray<int, N>* right, int axis) const
  {
    auto ret = m_helper->Stack(left, right, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMConstr<N>* Stack(const Copt::IMConstr<N>* cons1, const Copt::IMConstr<N>* cons2, int axis) const
  {
    auto ret = m_helper->Stack(cons1, cons2, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMQConstr<N>* Stack(const Copt::IMQConstr<N>* cons1, const Copt::IMQConstr<N>* cons2, int axis) const
  {
    auto ret = m_helper->Stack(cons1, cons2, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMPsdConstr<N>* Stack(const Copt::IMPsdConstr<N>* cons1, const Copt::IMPsdConstr<N>* cons2, int axis) const
  {
    auto ret = m_helper->Stack(cons1, cons2, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N> Copt::IMVar<N>* Stack(const Copt::IMVar<N>* vars1, const Copt::IMVar<N>* vars2, int axis) const
  {
    auto ret = m_helper->Stack(vars1, vars2, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMLinExpr<N>* Stack(const Copt::IMVar<N>* vars, const Copt::IMLinExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Stack(vars, exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N>
  Copt::IMLinExpr<N>* Stack(const Copt::IMVar<N>* vars, const Copt::INdArray<T, N>* A, int axis) const
  {
    auto ret = m_helper->Stack(vars, A, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N>
  Copt::IMLinExpr<N>* Stack(const Copt::INdArray<T, N>* A, const Copt::IMVar<N>* vars, int axis) const
  {
    auto ret = m_helper->Stack(A, vars, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMLinExpr<N>* Stack(const Copt::IMLinExpr<N>* exprs1, const Copt::IMLinExpr<N>* exprs2, int axis) const
  {
    auto ret = m_helper->Stack(exprs1, exprs2, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMLinExpr<N>* Stack(const Copt::IMLinExpr<N>* exprs, const Copt::IMVar<N>* vars, int axis) const
  {
    auto ret = m_helper->Stack(exprs, vars, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N>
  Copt::IMLinExpr<N>* Stack(const Copt::IMLinExpr<N>* exprs, const Copt::INdArray<T, N>* A, int axis) const
  {
    auto ret = m_helper->Stack(exprs, A, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N>
  Copt::IMLinExpr<N>* Stack(const Copt::INdArray<T, N>* A, const Copt::IMLinExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Stack(A, exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMQuadExpr<N>* Stack(const Copt::IMQuadExpr<N>* exprs1, const Copt::IMQuadExpr<N>* exprs2, int axis) const
  {
    auto ret = m_helper->Stack(exprs1, exprs2, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMQuadExpr<N>* Stack(const Copt::IMQuadExpr<N>* qexprs, const Copt::IMLinExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Stack(qexprs, exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMQuadExpr<N>* Stack(const Copt::IMLinExpr<N>* exprs, const Copt::IMQuadExpr<N>* qexprs, int axis) const
  {
    auto ret = m_helper->Stack(exprs, qexprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMQuadExpr<N>* Stack(const Copt::IMQuadExpr<N>* exprs, const Copt::IMVar<N>* vars, int axis) const
  {
    auto ret = m_helper->Stack(exprs, vars, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMQuadExpr<N>* Stack(const Copt::IMVar<N>* vars, const Copt::IMQuadExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Stack(vars, exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N>
  Copt::IMQuadExpr<N>* Stack(const Copt::IMQuadExpr<N>* exprs, const Copt::INdArray<T, N>* A, int axis) const
  {
    auto ret = m_helper->Stack(exprs, A, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N>
  Copt::IMQuadExpr<N>* Stack(const Copt::INdArray<T, N>* A, const Copt::IMQuadExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Stack(A, exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMPsdExpr<N>* Stack(const Copt::IMPsdExpr<N>* exprs1, const Copt::IMPsdExpr<N>* exprs2, int axis) const
  {
    auto ret = m_helper->Stack(exprs1, exprs2, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMPsdExpr<N>* Stack(const Copt::IMPsdExpr<N>* qexprs, const Copt::IMLinExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Stack(qexprs, exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMPsdExpr<N>* Stack(const Copt::IMLinExpr<N>* exprs, const Copt::IMPsdExpr<N>* qexprs, int axis) const
  {
    auto ret = m_helper->Stack(exprs, qexprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMPsdExpr<N>* Stack(const Copt::IMPsdExpr<N>* exprs, const Copt::IMVar<N>* vars, int axis) const
  {
    auto ret = m_helper->Stack(exprs, vars, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N>
  Copt::IMPsdExpr<N>* Stack(const Copt::IMVar<N>* vars, const Copt::IMPsdExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Stack(vars, exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N>
  Copt::IMPsdExpr<N>* Stack(const Copt::IMPsdExpr<N>* exprs, const Copt::INdArray<T, N>* A, int axis) const
  {
    auto ret = m_helper->Stack(exprs, A, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N>
  Copt::IMPsdExpr<N>* Stack(const Copt::INdArray<T, N>* A, const Copt::IMPsdExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Stack(A, exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  /* templates of sum of mobjs, along axis */
  template <int N> Copt::IMLinExpr<N - 1>* Sum(const Copt::IMVar<N>* vars, int axis) const
  {
    auto ret = m_helper->Sum(vars, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N> Copt::IMLinExpr<N - 1>* Sum(const Copt::IMLinExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Sum(exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N> Copt::IMQuadExpr<N - 1>* Sum(const Copt::IMQuadExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Sum(exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <int N> Copt::IMPsdExpr<N - 1>* Sum(const Copt::IMPsdExpr<N>* exprs, int axis) const
  {
    auto ret = m_helper->Sum(exprs, axis);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N> Copt::INdArray<T, N - 1>* Sum(const Copt::INdArray<T, N>* mat, int axis) const
  {
    auto ret = m_helper->Sum(mat, axis);
    CHECKERROR(ret);
    return ret;
  }

private:
  MHelper() : m_helper(CreateMHelper()) {}
  MHelper(const MHelper&);
  MHelper& operator=(const MHelper&);

  std::shared_ptr<Copt::IMHelper> m_helper;
};
