#pragma once
#include "coptcpp.idl.h"
#include "nlconstraint.h"

class NlConstrArray {
public:
  NlConstrArray() : m_rows(CreateNlConstrArray()) {}
  NlConstrArray(Copt::INlConstrArray* ptr) : m_rows(ptr) {}

  void PushBack(const NlConstraint& constr)
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

  NlConstraint GetNlConstr(int idx) const
  {
    return m_rows->GetNlConstr(idx);
  }
  NlConstraint operator[](int i) const
  {
    return m_rows->GetNlConstr(i);
  }

  Copt::INlConstrArray* Get() const
  {
    return &(*m_rows);
  }

private:
  std::shared_ptr<Copt::INlConstrArray> m_rows;
};
