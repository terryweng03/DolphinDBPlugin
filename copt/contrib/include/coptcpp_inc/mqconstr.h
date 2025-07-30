#pragma once
#include "coptcpp.idl.h"
#include "mfactory.h"
#include "mhelper.h"
#include "ndarray.h"
#include "qconstraint.h"
#include "shape.h"
#include "view.h"

template <int N> class MQConstr {
public:
  MQConstr(const Shape<N>& shp, const QConstraint& con) : m_qcon(MFactory::Get().CreateMQConstr(shp.Get(), con.Get()))
  {
  }
  MQConstr(const Shape<N>& shp, const QConstrArray& cons)
    : m_qcon(MFactory::Get().CreateMQConstr(shp.Get(), cons.Get()))
  {
  }
  MQConstr(Copt::IMQConstr<N>* qcon) : m_qcon(qcon) {}

  int GetND() const
  {
    return m_qcon->GetND();
  }

  size_t GetDim(int i) const
  {
    return m_qcon->GetDim(i);
  }

  size_t GetSize() const
  {
    return m_qcon->GetSize();
  }

  Shape<N> GetShape() const
  {
    return m_qcon->GetShape();
  }

  NdArray<int, N> GetIdx() const
  {
    return m_qcon->GetIdx();
  }

  NdArray<double, N> GetRhs() const
  {
    return m_qcon->GetRhs();
  }

  NdArray<char, N> GetSense() const
  {
    return m_qcon->GetSense();
  }

  NdArray<double, N> Get(const char* szInfo) const
  {
    return m_qcon->Get(szInfo);
  }

  void Set(const char* szInfo, double val) const
  {
    return m_qcon->Set(szInfo, val);
  }

  void Set(const char* szInfo, const NdArray<double, N>& vals) const
  {
    return m_qcon->Set(szInfo, vals.Get());
  }

  MQConstr<N - 1> Diagonal(int offset, int axis1 = 0, int axis2 = 1) const
  {
    return MHelper::Get().Diagonal(Get(), offset, axis1, axis2);
  }

  MQConstr<N + 1> Expand(int axis = 0) const
  {
    return MHelper::Get().Expand(Get(), axis);
  }

  MQConstr<1> Flatten() const
  {
    return m_qcon->Flatten();
  }

  template <int M> MQConstr<M> Reshape(const Shape<M>& shp) const
  {
    auto ret = m_qcon->Reshape(shp.Get());
    CHECKERROR(ret);
    return ret;
  }

  MQConstr<N - 1> Squeeze(int axis = 0) const
  {
    return MHelper::Get().Squeeze(Get(), axis);
  }

  MQConstr<N> Stack(const MQConstr<N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MQConstr<N> Transpose() const
  {
    return m_qcon->Transpose();
  }

  QConstraint Item(size_t idx = 0) const
  {
    return m_qcon->Item(idx);
  }

  void SetItem(size_t idx, QConstraint val)
  {
    m_qcon->SetItem(idx, val);
  }

  MQConstr<1> Pick(const NdArray<int, 1>& indexes) const
  {
    return m_qcon->Pick(indexes.Get());
  }

  MQConstr<1> Pick(const NdArray<int, 2>& idxrows) const
  {
    return m_qcon->Pick(idxrows.Get());
  }

  MQConstr<N> Clone() const
  {
    return m_qcon->Clone();
  }

  std::string Represent(size_t maxlen = 512) const
  {
    return m_qcon->Represent(maxlen);
  }

  Copt::IMQConstr<N>* Get() const
  {
    return &(*m_qcon);
  }

  MQConstr<N - 1> operator[](int64_t idx) const
  {
    MQConstr<N> ret = m_qcon->Item(Mat::make_view(idx).Get());
    CHECKERROR(ret.Get());
    return ret.Squeeze(0);
  }

  MQConstr<N> operator[](const View& view) const
  {
    auto ret = m_qcon->Item(view.Get());
    CHECKERROR(ret);
    return ret;
  }

  friend std::ostream& operator<<(std::ostream& out, const MQConstr& qcon)
  {
    out << "  CoptCpp.MQConstr shape=" << qcon.GetShape().Represent() << "\n";
    out << qcon.Represent();
    return out;
  }

private:
  std::shared_ptr<Copt::IMQConstr<N>> m_qcon;
};

namespace Mat {

template <int N> MQConstr<N> stack(const MQConstr<N>& cons1, const MQConstr<N>& cons2, int axis)
{
  return MHelper::Get().Stack<N>(cons1.Get(), cons2.Get(), axis);
}
template <int> MQConstr<2> hstack(const MQConstr<1>& cons1, const MQConstr<1>& cons2)
{
  Shape<2> shp1 = cons1.GetShape().Expand(1);
  Shape<2> shp2 = cons2.GetShape().Expand(1);
  return Mat::stack<2>(cons1.Reshape(shp1), cons2.Reshape(shp2), -1);
}
template <int N> MQConstr<N> hstack(const MQConstr<N>& cons1, const MQConstr<N>& cons2)
{
  return Mat::stack(cons1, cons2, -1);
}
template <int N> MQConstr<N> vstack(const MQConstr<N>& cons1, const MQConstr<N>& cons2)
{
  return Mat::stack(cons1, cons2, N == 1 ? -1 : -2);
}

template <int N> MQConstr<N> stack(const QConstraint& con, const MQConstr<N>& cons, int axis)
{
  MQConstr<N> left(cons.GetShape().RebuildWith(1), con);
  return MHelper::Get().Stack<N>(left.Get(), cons.Get(), axis);
}
template <int> MQConstr<2> hstack(const QConstraint& con, const MQConstr<1>& cons)
{
  Shape<2> shp = cons.GetShape().Expand(1);
  return Mat::stack<2>(con, cons.Reshape(shp), -1);
}
template <int N> MQConstr<N> hstack(const QConstraint& con, const MQConstr<N>& cons)
{
  return Mat::stack(con, cons, -1);
}
template <int N> MQConstr<N> vstack(const QConstraint& con, const MQConstr<N>& cons)
{
  return Mat::stack(con, cons, N == 1 ? -1 : -2);
}

template <int N> MQConstr<N> stack(const MQConstr<N>& cons, const QConstraint& con, int axis)
{
  MQConstr<N> right(cons.GetShape().RebuildWith(1), con);
  return MHelper::Get().Stack<N>(cons.Get(), right.Get(), axis);
}
template <int> MQConstr<2> hstack(const MQConstr<1>& cons, const QConstraint& con)
{
  Shape<2> shp = cons.GetShape().Expand(1);
  return Mat::stack<2>(cons.Reshape(shp), con, -1);
}
template <int N> MQConstr<N> hstack(const MQConstr<N>& cons, const QConstraint& con)
{
  return Mat::stack(cons, con, -1);
}
template <int N> MQConstr<N> vstack(const MQConstr<N>& cons, const QConstraint& con)
{
  return Mat::stack(cons, con, N == 1 ? -1 : -2);
}
}  // namespace Mat
