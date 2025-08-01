#pragma once
#include "coptcpp.idl.h"
#include "mfactory.h"
#include "mhelper.h"

template <int N> class Shape {
public:
  template <typename... TDs> Shape(TDs... dims) : m_ndim(MFactory::Get().CreateNDim<N>(dims...)) {}
  Shape(Copt::INDim<N>* ndim) : m_ndim(ndim) {}

  int GetND() const
  {
    return m_ndim->GetND();
  }

  size_t GetDim(int i) const
  {
    return m_ndim->GetDim(i);
  }

  size_t GetSize() const
  {
    return m_ndim->GetSize();
  }

  int64_t GetStride(int i) const
  {
    return m_ndim->GetStride(i);
  }

  int64_t GetStart(int i) const
  {
    return m_ndim->GetStart(i);
  }

  Shape<N + 1> Expand(int axis = 0) const
  {
    return MHelper::Get().Expand(Get(), axis);
  }

  Shape<N> Rebuild() const
  {
    return m_ndim->Rebuild();
  }
  Shape<N> RebuildWith(size_t dim) const
  {
    return m_ndim->RebuildWith(dim);
  }

  Shape<N - 1> Squeeze(int axis = 0) const
  {
    return MHelper::Get().Squeeze(Get(), axis);
  }

  std::string Represent(int type = 0) const
  {
    return m_ndim->Represent(type);
  }

  Copt::INDim<N>* Get() const
  {
    return &(*m_ndim);
  }

  bool operator==(const Shape<N>& other) const
  {
    return m_ndim->Equals(other.Get());
  }

  bool operator!=(const Shape<N>& other) const
  {
    return !(m_ndim->Equals(other.Get()));
  }

  friend std::ostream& operator<<(std::ostream& out, const Shape& shp)
  {
    out << shp.Represent();
    return out;
  }

private:
  std::shared_ptr<Copt::INDim<N>> m_ndim;
};

template <> class Shape<0> {
public:
  Shape(int = 1) : m_ndim(MFactory::Get().CreateNDim()) {}

  Shape(Copt::INDim<0>* ndim) : m_ndim(ndim) {}

  int GetND() const
  {
    return m_ndim->GetND();
  }

  size_t GetDim(int i) const
  {
    return m_ndim->GetDim(i);
  }

  size_t GetSize() const
  {
    return m_ndim->GetSize();
  }

  int64_t GetStride(int i) const
  {
    return m_ndim->GetStride(i);
  }

  int64_t GetStart(int i) const
  {
    return m_ndim->GetStart(i);
  }

  Shape<1> Expand(int axis = 0) const
  {
    return MHelper::Get().Expand(Get(), axis);
  }

  std::string Represent(int type = 0) const
  {
    return m_ndim->Represent(type);
  }

  Copt::INDim<0>* Get() const
  {
    return &(*m_ndim);
  }

  bool operator==(const Shape<0>& other) const
  {
    return m_ndim->Equals(other.Get());
  }

  bool operator!=(const Shape<0>& other) const
  {
    return !(m_ndim->Equals(other.Get()));
  }

  friend std::ostream& operator<<(std::ostream& out, const Shape& shp)
  {
    out << shp.Represent();
    return out;
  }

private:
  std::shared_ptr<Copt::INDim<0>> m_ndim;
};
