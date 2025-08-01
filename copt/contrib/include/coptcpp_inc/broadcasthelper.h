#pragma once
#include "coptcpp.idl.h"

class BroadCastHelper {
public:
  static BroadCastHelper& Get()
  {
    static BroadCastHelper helper;
    return helper;
  }

  /* MQuadExpr: broadcasting methods of plus */
  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* PlusCast(const Copt::IMVar<N>* left, const Copt::IMQuadExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* PlusCast(const Copt::IMLinExpr<N>* left, const Copt::IMQuadExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* PlusCast(const Copt::IMQuadExpr<N>* left, const Copt::IMQuadExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMQuadExpr<K>* PlusCast(const Copt::INdArray<T, N>* left, const Copt::IMQuadExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* MQuadExpr: broadcasting methods of substract */
  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* SubCast(const Copt::IMVar<N>* left, const Copt::IMQuadExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* SubCast(const Copt::IMLinExpr<N>* left, const Copt::IMQuadExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* SubCast(const Copt::IMQuadExpr<N>* left, const Copt::IMQuadExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMQuadExpr<K>* SubCast(const Copt::INdArray<T, N>* left, const Copt::IMQuadExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* MQuadExpr: broadcasting methods of multiplication */
  template <class T, int N, int M, int K>
  Copt::IMQuadExpr<K>* DotCast(const Copt::INdArray<T, N>* left, const Copt::IMQuadExpr<M>* right) const
  {
    auto ret = m_helper->DotCast(left, right);
    CHECKERROR(ret);
    return ret;
  }


  /* MPsdExpr: broadcasting methods of plus */
  template <int N, int M, int K>
  Copt::IMPsdExpr<K>* PlusCast(const Copt::IMVar<N>* left, const Copt::IMPsdExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMPsdExpr<K>* PlusCast(const Copt::IMLinExpr<N>* left, const Copt::IMPsdExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMPsdExpr<K>* PlusCast(const Copt::IMPsdExpr<N>* left, const Copt::IMPsdExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMPsdExpr<K>* PlusCast(const Copt::INdArray<T, N>* left, const Copt::IMPsdExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* MPsdExpr: broadcasting methods of substract */
  template <int N, int M, int K>
  Copt::IMPsdExpr<K>* SubCast(const Copt::IMVar<N>* left, const Copt::IMPsdExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMPsdExpr<K>* SubCast(const Copt::IMLinExpr<N>* left, const Copt::IMPsdExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMPsdExpr<K>* SubCast(const Copt::IMPsdExpr<N>* left, const Copt::IMPsdExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMPsdExpr<K>* SubCast(const Copt::INdArray<T, N>* left, const Copt::IMPsdExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* MPsdExpr: broadcasting methods of multiplication */
  template <class T, int N, int M, int K>
  Copt::IMPsdExpr<K>* DotCast(const Copt::INdArray<T, N>* left, const Copt::IMPsdExpr<M>* right) const
  {
    auto ret = m_helper->DotCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* MLinExpr: broadcasting methods of plus */
  template <int N, int M, int K>
  Copt::IMLinExpr<K>* PlusCast(const Copt::IMVar<N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMLinExpr<K>* PlusCast(const Copt::IMLinExpr<N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* PlusCast(const Copt::IMQuadExpr<N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMPsdExpr<K>* PlusCast(const Copt::IMPsdExpr<N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* PlusCast(const Copt::INdArray<T, N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* MLinExpr: broadcasting methods of substract */
  template <int N, int M, int K>
  Copt::IMLinExpr<K>* SubCast(const Copt::IMVar<N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMLinExpr<K>* SubCast(const Copt::IMLinExpr<N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* SubCast(const Copt::IMQuadExpr<N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMPsdExpr<K>* SubCast(const Copt::IMPsdExpr<N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* SubCast(const Copt::INdArray<T, N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* MLinExpr: broadcasting methods of multiplication */
  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* DotCast(const Copt::IMVar<N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->DotCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* DotCast(const Copt::IMLinExpr<N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->DotCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* DotCast(const Copt::INdArray<T, N>* left, const Copt::IMLinExpr<M>* right) const
  {
    auto ret = m_helper->DotCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* MVar: broadcasting methods of plus */
  template <int N, int M, int K>
  Copt::IMLinExpr<K>* PlusCast(const Copt::IMVar<N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMLinExpr<K>* PlusCast(const Copt::IMLinExpr<N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* PlusCast(const Copt::IMQuadExpr<N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMPsdExpr<K>* PlusCast(const Copt::IMPsdExpr<N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* PlusCast(const Copt::INdArray<T, N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* MVar: broadcasting methods of substract */
  template <int N, int M, int K>
  Copt::IMLinExpr<K>* SubCast(const Copt::IMVar<N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMLinExpr<K>* SubCast(const Copt::IMLinExpr<N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* SubCast(const Copt::IMQuadExpr<N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMPsdExpr<K>* SubCast(const Copt::IMPsdExpr<N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* SubCast(const Copt::INdArray<T, N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* MVar: broadcasting methods of multiplication */
  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* DotCast(const Copt::IMVar<N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->DotCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <int N, int M, int K>
  Copt::IMQuadExpr<K>* DotCast(const Copt::IMLinExpr<N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->DotCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* DotCast(const Copt::INdArray<T, N>* left, const Copt::IMVar<M>* right) const
  {
    auto ret = m_helper->DotCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* NdArray<T>: broadcasting methods of plus */
  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* PlusCast(const Copt::IMVar<N>* left, const Copt::INdArray<T, M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* PlusCast(const Copt::IMLinExpr<N>* left, const Copt::INdArray<T, M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMQuadExpr<K>* PlusCast(const Copt::IMQuadExpr<N>* left, const Copt::INdArray<T, M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMPsdExpr<K>* PlusCast(const Copt::IMPsdExpr<N>* left, const Copt::INdArray<T, M>* right) const
  {
    auto ret = m_helper->PlusCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* NdArray<T>: broadcasting methods of substract */
  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* SubCast(const Copt::IMVar<N>* left, const Copt::INdArray<T, M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* SubCast(const Copt::IMLinExpr<N>* left, const Copt::INdArray<T, M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMQuadExpr<K>* SubCast(const Copt::IMQuadExpr<N>* left, const Copt::INdArray<T, M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMPsdExpr<K>* SubCast(const Copt::IMPsdExpr<N>* left, const Copt::INdArray<T, M>* right) const
  {
    auto ret = m_helper->SubCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* NdArray<T>: broadcasting methods of multiplication */
  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* DotCast(const Copt::IMVar<N>* left, const Copt::INdArray<T, M>* right) const
  {
    auto ret = m_helper->DotCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMLinExpr<K>* DotCast(const Copt::IMLinExpr<N>* left, const Copt::INdArray<T, M>* right) const
  {
    auto ret = m_helper->DotCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMQuadExpr<K>* DotCast(const Copt::IMQuadExpr<N>* left, const Copt::INdArray<T, M>* right) const
  {
    auto ret = m_helper->DotCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class T, int N, int M, int K>
  Copt::IMPsdExpr<K>* DotCast(const Copt::IMPsdExpr<N>* left, const Copt::INdArray<T, M>* right) const
  {
    auto ret = m_helper->DotCast(left, right);
    CHECKERROR(ret);
    return ret;
  }

  /* plus/sub/dot casts for ndarray */
  template <class Ta, class Tb, class T, int N, int M, int K>
  Copt::INdArray<T, K>* PlusCast(const Copt::INdArray<Ta, N>* left, const Copt::INdArray<Tb, M>* right) const
  {
    auto ret = m_helper->PlusCasting(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class Ta, class Tb, class T, int N, int M, int K>
  Copt::INdArray<T, K>* SubCast(const Copt::INdArray<Ta, N>* left, const Copt::INdArray<Tb, M>* right) const
  {
    auto ret = m_helper->SubCasting(left, right);
    CHECKERROR(ret);
    return ret;
  }

  template <class Ta, class Tb, class T, int N, int M, int K>
  Copt::INdArray<T, K>* DotCast(const Copt::INdArray<Ta, N>* left, const Copt::INdArray<Tb, M>* right) const
  {
    auto ret = m_helper->DotCasting(left, right);
    CHECKERROR(ret);
    return ret;
  }

private:
  BroadCastHelper() : m_helper(CreateBroadCastHelper()) {}
  BroadCastHelper(const BroadCastHelper&);
  BroadCastHelper& operator=(const BroadCastHelper&);

  std::shared_ptr<Copt::IBroadCastHelper> m_helper;
};
