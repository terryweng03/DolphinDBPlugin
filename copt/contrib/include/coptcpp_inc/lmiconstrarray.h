#pragma once
#include "coptcpp.idl.h"
#include "lmiconstraint.h"

class LmiConstrArray {
public:
  LmiConstrArray() : m_rows(CreateLmiConstrArray()) {}
  LmiConstrArray(Copt::ILmiConstrArray* ptr) : m_rows(ptr) {}

  void PushBack(const LmiConstraint& constr)
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

  LmiConstraint GetLmiConstr(int idx) const
  {
    return m_rows->GetLmiConstr(idx);
  }
  LmiConstraint operator[](int i) const
  {
    return m_rows->GetLmiConstr(i);
  }

  Copt::ILmiConstrArray* Get() const
  {
    return &(*m_rows);
  }

private:
  std::shared_ptr<Copt::ILmiConstrArray> m_rows;
};
