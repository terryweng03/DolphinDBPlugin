#pragma once
#include "coptcpp.idl.h"
#include "psdconstraint.h"

class PsdConstrArray {
public:
  PsdConstrArray() : m_rows(CreatePsdConstrArray()) {}
  PsdConstrArray(Copt::IPsdConstrArray* ptr) : m_rows(ptr) {}

  void PushBack(const PsdConstraint& constr)
  {
    return m_rows->PushBack(constr.Get());
  }

  int Size() const
  {
    return m_rows->Size();
  }

  void Reserve(int n)
  {
    m_rows->Reserve(n);
  }

  PsdConstraint GetPsdConstr(int idx) const
  {
    return m_rows->GetPsdConstr(idx);
  }
  PsdConstraint operator[](int i) const
  {
    return m_rows->GetPsdConstr(i);
  }

  Copt::IPsdConstrArray* Get() const
  {
    return &(*m_rows);
  }

private:
  std::shared_ptr<Copt::IPsdConstrArray> m_rows;
};
