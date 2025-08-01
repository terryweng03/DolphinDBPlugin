#pragma once
#include "coptcpp.idl.h"
#include "qconstraint.h"

class QConstrArray {
public:
  QConstrArray() : m_rows(CreateQConstrArray()) {}
  QConstrArray(Copt::IQConstrArray* ptr) : m_rows(ptr) {}

  void PushBack(const QConstraint& constr)
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

  QConstraint GetQConstr(int idx) const
  {
    return m_rows->GetQConstr(idx);
  }
  QConstraint operator[](int i) const
  {
    return m_rows->GetQConstr(i);
  }

  Copt::IQConstrArray* Get() const
  {
    return &(*m_rows);
  }

private:
  std::shared_ptr<Copt::IQConstrArray> m_rows;
};
