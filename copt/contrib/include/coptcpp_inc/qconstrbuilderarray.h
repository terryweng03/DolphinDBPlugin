#pragma once
#include "coptcpp.idl.h"
#include "qconstrbuilder.h"

class QConstrBuilderArray {
public:
  QConstrBuilderArray() : m_builders(CreateQConstrBuilderArray()) {}
  QConstrBuilderArray(Copt::IQConstrBuilderArray* ptr) : m_builders(ptr) {}

  void PushBack(const QConstrBuilder& builder)
  {
    return m_builders->PushBack(builder.Get());
  }

  int Size() const
  {
    return m_builders->Size();
  }

  void Reserve(int n)
  {
    m_builders->Reserve(n);
  }

  QConstrBuilder GetBuilder(int idx) const
  {
    return m_builders->GetBuilder(idx);
  }
  QConstrBuilder operator[](int i) const
  {
    return m_builders->GetBuilder(i);
  }

  Copt::IQConstrBuilderArray* Get() const
  {
    return &(*m_builders);
  }

private:
  std::shared_ptr<Copt::IQConstrBuilderArray> m_builders;
};
