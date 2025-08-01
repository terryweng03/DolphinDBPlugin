#pragma once
#include "coptcpp.idl.h"
#include "mfactory.h"
#include "mhelper.h"
#include "ndarray.h"
#include "psdconstraint.h"
#include "psdconstrarray.h"
#include "shape.h"
#include "view.h"

template <int N> class MPsdConstr {
public:
  MPsdConstr(const Shape<N>& shp, const PsdConstraint& con)
    : m_psdcon(MFactory::Get().CreateMPsdConstr(shp.Get(), con.Get()))
  {
  }
  MPsdConstr(const Shape<N>& shp, const PsdConstrArray& cons)
    : m_psdcon(MFactory::Get().CreateMPsdConstr(shp.Get(), cons.Get()))
  {
  }
  MPsdConstr(Copt::IMPsdConstr<N>* qcon) : m_psdcon(qcon) {}

  int GetND() const
  {
    return m_psdcon->GetND();
  }

  size_t GetDim(int i) const
  {
    return m_psdcon->GetDim(i);
  }

  size_t GetSize() const
  {
    return m_psdcon->GetSize();
  }

  Shape<N> GetShape() const
  {
    return m_psdcon->GetShape();
  }

  NdArray<int, N> GetIdx() const
  {
    return m_psdcon->GetIdx();
  }

  NdArray<double, N> Get(const char* szInfo) const
  {
    return m_psdcon->Get(szInfo);
  }

  void Set(const char* szInfo, double val) const
  {
    m_psdcon->Set(szInfo, val);
  }

  void Set(const char* szInfo, const NdArray<double, N>& vals) const
  {
    m_psdcon->Set(szInfo, vals.Get());
  }

  MPsdConstr<N - 1> Diagonal(int offset, int axis1 = 0, int axis2 = 1) const
  {
    return MHelper::Get().Diagonal(Get(), offset, axis1, axis2);
  }

  MPsdConstr<N + 1> Expand(int axis = 0) const
  {
    return MHelper::Get().Expand(Get(), axis);
  }

  MPsdConstr<1> Flatten() const
  {
    return m_psdcon->Flatten();
  }

  template <int M> MPsdConstr<M> Reshape(const Shape<M>& shp) const
  {
    auto ret = m_psdcon->Reshape(shp.Get());
    CHECKERROR(ret);
    return ret;
  }

  MPsdConstr<N - 1> Squeeze(int axis = 0) const
  {
    return MHelper::Get().Squeeze(Get(), axis);
  }

  MPsdConstr<N> Stack(const MPsdConstr<N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MPsdConstr<N> Transpose() const
  {
    return m_psdcon->Transpose();
  }

  PsdConstraint Item(size_t idx = 0) const
  {
    return m_psdcon->Item(idx);
  }

  void SetItem(size_t idx, PsdConstraint val)
  {
    m_psdcon->SetItem(idx, val);
  }

  MPsdConstr<1> Pick(const NdArray<int, 1>& indexes) const
  {
    return m_psdcon->Pick(indexes.Get());
  }

  MPsdConstr<1> Pick(const NdArray<int, 2>& idxrows) const
  {
    return m_psdcon->Pick(idxrows.Get());
  }

  MPsdConstr<N> Clone() const
  {
    return m_psdcon->Clone();
  }

  std::string Represent(size_t maxlen = 512) const
  {
    return m_psdcon->Represent(maxlen);
  }

  Copt::IMPsdConstr<N>* Get() const
  {
    return &(*m_psdcon);
  }

  MPsdConstr<N - 1> operator[](int64_t idx) const
  {
    MPsdConstr<N> ret = m_psdcon->Item(Mat::make_view(idx).Get());
    CHECKERROR(ret.Get());
    return ret.Squeeze(0);
  }

  MPsdConstr<N> operator[](const View& view) const
  {
    auto ret = m_psdcon->Item(view.Get());
    CHECKERROR(ret);
    return ret;
  }

  friend std::ostream& operator<<(std::ostream& out, const MPsdConstr& qcon)
  {
    out << "  CoptCpp.MPsdConstr shape=" << qcon.GetShape().Represent() << "\n";
    out << qcon.Represent();
    return out;
  }

private:
  std::shared_ptr<Copt::IMPsdConstr<N>> m_psdcon;
};

namespace Mat {

template <int N> MPsdConstr<N> stack(const MPsdConstr<N>& cons1, const MPsdConstr<N>& cons2, int axis)
{
  return MHelper::Get().Stack<N>(cons1.Get(), cons2.Get(), axis);
}
template <int> MPsdConstr<2> hstack(const MPsdConstr<1>& cons1, const MPsdConstr<1>& cons2)
{
  Shape<2> shp1 = cons1.GetShape().Expand(1);
  Shape<2> shp2 = cons2.GetShape().Expand(1);
  return Mat::stack<2>(cons1.Reshape(shp1), cons2.Reshape(shp2), -1);
}
template <int N> MPsdConstr<N> hstack(const MPsdConstr<N>& cons1, const MPsdConstr<N>& cons2)
{
  return Mat::stack(cons1, cons2, -1);
}
template <int N> MPsdConstr<N> vstack(const MPsdConstr<N>& cons1, const MPsdConstr<N>& cons2)
{
  return Mat::stack(cons1, cons2, N == 1 ? -1 : -2);
}

template <int N> MPsdConstr<N> stack(const PsdConstraint& con, const MPsdConstr<N>& cons, int axis)
{
  MPsdConstr<N> left(cons.GetShape().RebuildWith(1), con);
  return MHelper::Get().Stack<N>(left.Get(), cons.Get(), axis);
}
template <int> MPsdConstr<2> hstack(const PsdConstraint& con, const MPsdConstr<1>& cons)
{
  Shape<2> shp = cons.GetShape().Expand(1);
  return Mat::stack<2>(con, cons.Reshape(shp), -1);
}
template <int N> MPsdConstr<N> hstack(const PsdConstraint& con, const MPsdConstr<N>& cons)
{
  return Mat::stack(con, cons, -1);
}
template <int N> MPsdConstr<N> vstack(const PsdConstraint& con, const MPsdConstr<N>& cons)
{
  return Mat::stack(con, cons, -N == 1 ? -1 : -2);
}

template <int N> MPsdConstr<N> stack(const MPsdConstr<N>& cons, const PsdConstraint& con, int axis)
{
  MPsdConstr<N> right(cons.GetShape().RebuildWith(1), con);
  return MHelper::Get().Stack<N>(cons.Get(), right.Get(), axis);
}
template <int> MPsdConstr<2> hstack(const MPsdConstr<1>& cons, const PsdConstraint& con)
{
  Shape<2> shp = cons.GetShape().Expand(1);
  return Mat::stack<2>(cons.Reshape(shp), con, -1);
}
template <int N> MPsdConstr<N> hstack(const MPsdConstr<N>& cons, const PsdConstraint& con)
{
  return Mat::stack(cons, con, -1);
}
template <int N> MPsdConstr<N> vstack(const MPsdConstr<N>& cons, const PsdConstraint& con)
{
  return Mat::stack(cons, con, N == 1 ? -1 : -2);
}
}  // namespace Mat
