#pragma once
#include "coptcpp.idl.h"
#include "mfactory.h"
#include "mhelper.h"
#include "ndarray.h"
#include "shape.h"
#include "constrarray.h"
#include "view.h"

template <int N> class MConstr {
public:
  MConstr(const Shape<N>& shp, const Constraint& con) : m_con(MFactory::Get().CreateMConstr(shp.Get(), con.Get())) {}
  MConstr(const Shape<N>& shp, const ConstrArray& cons) : m_con(MFactory::Get().CreateMConstr(shp.Get(), cons.Get())) {}
  MConstr(Copt::IMConstr<N>* con) : m_con(con) {}

  int GetND() const
  {
    return m_con->GetND();
  }

  size_t GetDim(int i) const
  {
    return m_con->GetDim(i);
  }

  size_t GetSize() const
  {
    return m_con->GetSize();
  }

  Shape<N> GetShape() const
  {
    return m_con->GetShape();
  }

  NdArray<int, N> GetBasis() const
  {
    return m_con->GetBasis();
  }

  NdArray<int, N> GetIdx() const
  {
    return m_con->GetIdx();
  }

  NdArray<int, N> GetLowerIIS() const
  {
    return m_con->GetLowerIIS();
  }

  NdArray<int, N> GetUpperIIS() const
  {
    return m_con->GetUpperIIS();
  }

  NdArray<double, N> Get(const char* szInfo) const
  {
    return m_con->Get(szInfo);
  }

  void Set(const char* szInfo, double val) const
  {
    return m_con->Set(szInfo, val);
  }

  void Set(const char* szInfo, const NdArray<double, N>& vals) const
  {
    return m_con->Set(szInfo, vals.Get());
  }

  MConstr<N - 1> Diagonal(int offset, int axis1 = 0, int axis2 = 1) const
  {
    return MHelper::Get().Diagonal(Get(), offset, axis1, axis2);
  }

  MConstr<N + 1> Expand(int axis = 0) const
  {
    return MHelper::Get().Expand(Get(), axis);
  }

  MConstr<1> Flatten() const
  {
    return m_con->Flatten();
  }

  template <int M> MConstr<M> Reshape(const Shape<M>& shp) const
  {
    auto ret = m_con->Reshape(shp.Get());
    CHECKERROR(ret);
    return ret;
  }

  MConstr<N - 1> Squeeze(int axis = 0) const
  {
    return MHelper::Get().Squeeze(Get(), axis);
  }

  MConstr<N> Stack(const MConstr<N>& other, int axis) const
  {
    return MHelper::Get().Stack(Get(), other.Get(), axis);
  }

  MConstr<N> Transpose() const
  {
    return m_con->Transpose();
  }

  Constraint Item(size_t idx = 0) const
  {
    return m_con->Item(idx);
  }

  void SetItem(size_t idx, Constraint val)
  {
    m_con->SetItem(idx, val);
  }

  MConstr<1> Pick(const NdArray<int, 1>& indexes) const
  {
    return m_con->Pick(indexes.Get());
  }

  MConstr<1> Pick(const NdArray<int, 2>& idxrows) const
  {
    return m_con->Pick(idxrows.Get());
  }

  MConstr<N> Clone() const
  {
    return m_con->Clone();
  }

  std::string Represent(size_t maxlen = 512) const
  {
    return m_con->Represent(maxlen);
  }

  Copt::IMConstr<N>* Get() const
  {
    return &(*m_con);
  }

  MConstr<N - 1> operator[](int64_t idx) const
  {
    MConstr<N> ret = m_con->Item(Mat::make_view(idx).Get());
    CHECKERROR(ret.Get());
    return ret.Squeeze(0);
  }

  MConstr<N> operator[](const View& view) const
  {
    auto ret = m_con->Item(view.Get());
    CHECKERROR(ret);
    return ret;
  }

  friend std::ostream& operator<<(std::ostream& out, const MConstr& con)
  {
    out << "  CoptCpp.MConstr shape=" << con.GetShape().Represent() << "\n";
    out << con.Represent();
    return out;
  }

private:
  std::shared_ptr<Copt::IMConstr<N>> m_con;
};

namespace Mat {

template <int N> MConstr<N> stack(const MConstr<N>& cons1, const MConstr<N>& cons2, int axis)
{
  return MHelper::Get().Stack<N>(cons1.Get(), cons2.Get(), axis);
}
template <int> MConstr<2> hstack(const MConstr<1>& cons1, const MConstr<1>& cons2)
{
  Shape<2> shp1 = cons1.GetShape().Expand(1);
  Shape<2> shp2 = cons2.GetShape().Expand(1);
  return Mat::stack<2>(cons1.Reshape(shp1), cons2.Reshape(shp2), -1);
}
template <int N> MConstr<N> hstack(const MConstr<N>& cons1, const MConstr<N>& cons2)
{
  return Mat::stack(cons1, cons2, -1);
}
template <int N> MConstr<N> vstack(const MConstr<N>& cons1, const MConstr<N>& cons2)
{
  return Mat::stack(cons1, cons2, N == 1 ? -1 : -2);
}

template <int N> MConstr<N> stack(const Constraint& con, const MConstr<N>& cons, int axis)
{
  MConstr<N> left(cons.GetShape().RebuildWith(1), con);
  return MHelper::Get().Stack<N>(left.Get(), cons.Get(), axis);
}
template <int> MConstr<2> hstack(const Constraint& con, const MConstr<1>& cons)
{
  Shape<2> shp = cons.GetShape().Expand(1);
  return Mat::stack<2>(con, cons.Reshape(shp), -1);
}
template <int N> MConstr<N> hstack(const Constraint& con, const MConstr<N>& cons)
{
  return Mat::stack(con, cons, -1);
}
template <int N> MConstr<N> vstack(const Constraint& con, const MConstr<N>& cons)
{
  return Mat::stack(con, cons, N == 1 ? -1 : -2);
}

template <int N> MConstr<N> stack(const MConstr<N>& cons, const Constraint& con, int axis)
{
  MConstr<N> right(cons.GetShape().RebuildWith(1), con);
  return MHelper::Get().Stack<N>(cons.Get(), right.Get(), axis);
}
template <int> MConstr<2> hstack(const MConstr<1>& cons, const Constraint& con)
{
  Shape<2> shp = cons.GetShape().Expand(1);
  return Mat::stack<2>(cons.Reshape(shp), con, -1);
}
template <int N> MConstr<N> hstack(const MConstr<N>& cons, const Constraint& con)
{
  return Mat::stack(cons, con, -1);
}
template <int N> MConstr<N> vstack(const MConstr<N>& cons, const Constraint& con)
{
  return Mat::stack(cons, con, N == 1 ? -1 : -2);
}
}  // namespace Mat
