#pragma once
#include "coptcpp.idl.h"
#include "psdvar.h"

class PsdVarArray {
public:
  PsdVarArray() : m_cols(CreatePsdVarArray()) {}
  PsdVarArray(Copt::IPsdVarArray* ptr) : m_cols(ptr) {}

  void PushBack(const PsdVar& var)
  {
    return m_cols->PushBack(var.Get());
  }

  int Size() const
  {
    return m_cols->Size();
  }

  void Reserve(int n)
  {
    m_cols->Reserve(n);
  }

  PsdVar GetPsdVar(int idx) const
  {
    return m_cols->GetPsdVar(idx);
  }
  PsdVar operator[](int i) const
  {
    return m_cols->GetPsdVar(i);
  }

  Copt::IPsdVarArray* Get() const
  {
    return &(*m_cols);
  }

private:
  std::shared_ptr<Copt::IPsdVarArray> m_cols;
};
