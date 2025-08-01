#pragma once
#include "coptcpp.idl.h"
#include "symmatrix.h"

class SymMatrixArray {
public:
  SymMatrixArray() : m_mats(CreateSymMatrixArray()) {}
  SymMatrixArray(Copt::ISymMatrixArray* ptr) : m_mats(ptr) {}

  void PushBack(const SymMatrix& mat)
  {
    return m_mats->PushBack(mat.Get());
  }

  int Size() const
  {
    return m_mats->Size();
  }

  void Reserve(int n)
  {
    m_mats->Reserve(n);
  }

  SymMatrix GetMatrix(int idx) const
  {
    return m_mats->GetMatrix(idx);
  }
  SymMatrix operator[](int i) const
  {
    return m_mats->GetMatrix(i);
  }

  Copt::ISymMatrixArray* Get() const
  {
    return &(*m_mats);
  }

private:
  std::shared_ptr<Copt::ISymMatrixArray> m_mats;
};
